import numpy as np

def nms(box):
	if len(box) == 0:
		return []
	print box
	
	print "nms"


	overlapThresh = 0.5

	sample = list()
	boundingBoxes = list()
	#boxes=np.asarray(box)
	boxes = box
	print len(box)
	for i in range(0,len(box)):
		sample = list()
		x1 = boxes[i,0]
		y1 = boxes[i,1]
		x2 = boxes[i,0] + boxes[i,2]
		y2 = boxes[i,1] + boxes[i,3]

		sample.append(x1)
		sample.append(y1)
		sample.append(x2)
		sample.append(y2)
		boundingBoxes.append(sample)

	x1 = boxes[:,0]
	y1 = boxes[:,1]
	x2 = boxes[:,2]
	y2 = boxes[:,3]

	print boundingBoxes

	area = (x2 - x1 + 1) * (y2 - y1 + 1)
	idxs = np.argsort(y2)
	print idxs

	pick = list()
	while len(idxs) > 0:
		last = len(idxs) - 1
		i = idxs[last]
		pick.append(i)
		suppress = [last]

                # loop over all indexes in the indexes list
                for pos in xrange(0, last):
			print pos
                        # grab the current index
                        j = idxs[pos]
			print j

                        # find the largest (x, y) coordinates for the start of
                        # the bounding box and the smallest (x, y) coordinates
                        # for the end of the bounding box
                        xx1 = max(x1[i], x1[j])
                        yy1 = max(y1[i], y1[j])
                        xx2 = min(x2[i], x2[j])
                        yy2 = min(y2[i], y2[j])

                        # compute the width and height of the bounding box
                        w = max(0, xx2 - xx1 + 1)
                        h = max(0, yy2 - yy1 + 1)

			print xx1,yy1,xx2,yy2

                        # compute the ratio of overlap between the computed
                        # bounding box and the bounding box in the area list
                        overlap = float(w * h) / area[j]

                        # if there is sufficient overlap, suppress the
                        # current bounding box
                        if overlap > overlapThresh:
                                suppress.append(pos)

                # delete all indexes from the index list that are in the
                # suppression list
                idxs = np.delete(idxs, suppress)

	print boxes[pick]

def get_data():
	return np.array([[11,11,24,24],
			[10,11,20,20],
			[11,9,24,24],
			[40,42,20,20]])

def main():
	box = get_data()
	print box.shape
	nms(box)

if __name__ == '__main__':
    	main()
