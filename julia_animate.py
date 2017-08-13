from multiprocessing import Process, Value, Lock
import time
#import multiprocessing
from subprocess import call
import math
class parametric:
	def __init__(self,tmin,tmax,xeq,yeq):
		self.tmin=tmin
		self.tmax=tmax
		self.xeq=xeq #ex. 2*t
		self.yeq=yeq
	def evalatt(self,t):
		return [eval(self.xeq),eval(self.yeq)]
	def evalratio(self,ratio):
		t=self.tmin+(ratio*(self.tmax-self.tmin))
		return [eval(self.xeq),eval(self.yeq)]
def test(lock,numframes,currentframe,para):
	while currentframe.value<numframes:
		with lock:
			print(str(currentframe.value)+".png")
			framenum=currentframe.value
			currentframe.value+=1
		coords=para.evalratio(float(framenum)/float(numframes))
		x=coords[0]
		y=coords[1]
		call(["./julia","2560","1440","200","1.75",str(x),str(y),"./images/%06d.png"%(framenum)])
	return
#main
if __name__ == '__main__':
	para=parametric(-1,.5,"t","math.atan(t)")
	numthreads=4
	numframes=3600
	
	currentframe=Value("i",0)
	lock=Lock()
	processes=[]
	start=time.time()
	for i in range(numthreads):
		processes.append(Process(target=test,args=(lock,numframes,currentframe,para)))
	for i in range(numthreads):
		processes[i].start()
	for i in range(numthreads):
		processes[i].join()
	print(time.time()-start)
