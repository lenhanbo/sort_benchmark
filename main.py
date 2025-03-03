import numpy as np
import time

with open("temp", "r") as file:
	test = str(file.read())
file.close()
with open("cur_sum", "r") as file:
	tmp = file.read()
	sum = int(tmp)
file.close()

with open("test_" + test + ".inp", "r") as ip :
	n = int(ip.readline())
	a = np.array(list(map(float,ip.readline().split())))
	start = time.time()
	a.sort()
	end = time.time()

	with open("result.out", "a") as op:
		op.write("Python_sort : ")
		sum += int((end - start) * 1000)
		# print(end - start * 1000)
		op.write(str(int((end - start) * 1000)))
		op.write("ms")
		op.write('\n')
		op.write('\n')

with open("cur_sum", "w") as file:
	file.write(str(sum))
	file.close()
