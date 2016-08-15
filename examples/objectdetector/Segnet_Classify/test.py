import numpy as np
import sys
import cv2
import matplotlib.pyplot as plt

#caffe_root = '/home/abhi/Desktop/GSOC/target7/caffe-segnet-segnet-cleaned/'
caffe_root = sys.argv[1];
sys.path.insert(0, caffe_root + 'python')
import caffe

if(sys.argv[7] == "gpu"):
	caffe.set_mode_gpu()
	caffe.set_device(0)
else:
	caffe.set_mode_cpu()

# caffemodel file
#MODEL_FILE ='bayesian_segnet_basic_camvid.caffemodel'
MODEL_FILE = sys.argv[3];
# deploy file reference /caffe/models/bvlc_alexnet/deploy.prototxt
#DEPLOY_FILE ='bayesian_segnet_basic_inference.prototxt'
DEPLOY_FILE = sys.argv[2];
net = caffe.Net(DEPLOY_FILE, MODEL_FILE, caffe.TEST)

transformer = caffe.io.Transformer({'data': net.blobs['data'].data.shape})
transformer.set_transpose('data',(2,0,1))
#transformer.set_raw_scale('data',255)
#transformer.set_channel_swap('data',(2,1,0))
#net.blobs['data'].reshape(1,3,360,480)

#img = caffe.io.load_image ('1.png')
#net.blobs['data'].data[...] = transformer.preprocess('data', img)

#out = net.forward ()

input_shape = net.blobs['data'].data.shape

label_colours = cv2.imread(sys.argv[6]).astype(np.uint8)
input_image_file = sys.argv[4];
ground_truth_file = sys.argv[5];
input_image_raw = caffe.io.load_image(input_image_file)
ground_truth = cv2.imread(ground_truth_file, 0)

input_image = caffe.io.resize_image(input_image_raw, (input_shape[2],input_shape[3]))
input_image = input_image*255
input_image = input_image.transpose((2,0,1))
input_image = input_image[(2,1,0),:,:]
input_image = np.asarray([input_image])
input_image = np.repeat(input_image,input_shape[0],axis=0)

out = net.forward_all(data=input_image)

predicted = net.blobs['prob'].data

output = np.mean(predicted,axis=0)
uncertainty = np.var(predicted,axis=0)
ind = np.argmax(output, axis=0)

segmentation_ind_3ch = np.resize(ind,(3,input_shape[2],input_shape[3]))
segmentation_ind_3ch = segmentation_ind_3ch.transpose(1,2,0).astype(np.uint8)
segmentation_rgb = np.zeros(segmentation_ind_3ch.shape, dtype=np.uint8)

gt_ind_3ch = np.resize(ground_truth,(3,input_shape[2],input_shape[3]))
gt_ind_3ch = gt_ind_3ch.transpose(1,2,0).astype(np.uint8)
gt_rgb = np.zeros(gt_ind_3ch.shape, dtype=np.uint8)

cv2.LUT(segmentation_ind_3ch,label_colours,segmentation_rgb)
cv2.LUT(gt_ind_3ch,label_colours,gt_rgb)

uncertainty = np.transpose(uncertainty, (1,2,0))

average_unc = np.mean(uncertainty,axis=2)
min_average_unc = np.min(average_unc)
max_average_unc = np.max(average_unc)
max_unc = np.max(uncertainty)

plt.imshow(input_image_raw,vmin=0, vmax=255)
plt.figure()
plt.imshow(segmentation_rgb,vmin=0, vmax=255)
plt.figure()
plt.imshow(gt_rgb,vmin=0, vmax=255)
plt.set_cmap('bone_r')
#plt.figure()
#plt.imshow(average_unc,vmin=0, vmax=max_average_unc)
plt.show()

# uncomment to save results
#scipy.misc.toimage(segmentation_rgb, cmin=0.0, cmax=255.0).save(IMAGE_FILE+'_segnet_segmentation.png')
#cm = matplotlib.pyplot.get_cmap('bone_r') 
#matplotlib.image.imsave(input_image_file+'_segnet_uncertainty.png',average_unc,cmap=cm, vmin=0, vmax=max_average_unc)

print 'Processed: ', input_image_file


'''
arr = net.blobs['prob'].data[0]
arr1 = np.multiply(arr,100000)
print arr1[4]



r = cv2.imread('1.png',1)
r[:,:,0][arr1[4] > 6] = 0
r[:,:,1][arr1[4] > 6] = 0
r[:,:,2][arr1[4] > 6] = 255

cv2.imshow("r",r)
cv2.imshow("arr",arr[4])
cv2.waitKey(0)
'''
