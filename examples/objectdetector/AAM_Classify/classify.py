import numpy as np
import caffe
import sys
import cv2

if(sys.argv[5] == "gpu"):
	caffe.set_mode_gpu()
	caffe.set_device(0)
else:
	caffe.set_mode_cpu()


net = caffe.Net(sys.argv[1], sys.argv[2], caffe.TEST)

transformer = caffe.io.Transformer({'data': net.blobs['data'].data.shape})
transformer.set_transpose('data',(2,0,1))

img = caffe.io.load_image (sys.argv[3])
net.blobs['data'].data[...] = transformer.preprocess('data', img)

out = net.forward ()
predicts = out['prob']

print "Predicted label:"
predicts = predicts*255
print predicts[0]

img = cv2.imread(sys.argv[3])
f = open(sys.argv[4],'w')
for i in range(15):
	x = (predicts[0][2*i])
	y = (predicts[0][2*i+1])
	x = int(x)
	y = int(y)
	cv2.circle(img, (x,y), 1, (255,255,255), 2, 8, 0)
	stringVal = str(x) + " " + str(y)
	f.write(stringVal)
	f.write('\n')

cv2.imshow("img", img)
cv2.waitKey(0)


