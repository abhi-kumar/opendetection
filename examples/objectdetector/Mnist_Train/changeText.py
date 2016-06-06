import cv2
import numpy as np

f = open("train_base.txt",'r')
f1 = open("train.txt",'w')

for i in range(42000):
	lines = f.readline()
	cutLines = lines[88:]
	cutLines = "../examples/objectdetector/" + cutLines
	f1.write(cutLines)
