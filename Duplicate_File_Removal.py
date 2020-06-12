import os;
import hashlib;
from sys import *;
import time;
def hashfile(path,blocksize=1024):
	
	fd=open(path,'rb')
	hasher=hashlib.md5()
	buf=fd.read(blocksize)


	while(len(buf))>0:
		hasher.update(buf)
		buf=fd.read(blocksize);
		
	fd.close()

	return hasher.hexdigest()
	
def ChkSum(path):
	flag=os.path.isabs(path)
	if flag==False:
		path=os.path.abspath(path);
	Dup={};
	exists=os.path.isdir(path)
	if exists:
		for foldername,subfolder,filename in os.walk(path):
			print("Current Folder is:",foldername);
			
			for filen in filename:
				newpath=os.path.join(path,filen);
				hashno=hashfile(newpath);
				if hashno in Dup:
					Dup[hashno].append(newpath);
				else:
					Dup[hashno]=[newpath];
	return Dup;

def DiplayDuplicate(dir):
	ret=list(filter(lambda x:len(x)>1,dir.values()));
	iCnt=0;
	fd = open('Log.txt', 'w') 
	fd.write("Duplicate file Name is:\n");
	fd.write("----------------------------\n");
	if len(ret)>0:
		print("Duplicate Files are:")
		for result in ret:
			for sub in result:
				iCnt+=1;
				if iCnt>=2:
					fd.write(sub+"\n");
					os.remove(sub);
						
def main():
	
	if(len(argv)!=2):
		print("Error:No of parameter is invalid");
	elif(argv[1]=='-h'):
		print("This Script show the CheckSum of Files");
		exit();
	elif(argv[1]=='-u'):
		print("This Scrpt is use to display the Checksum of files");
		exit();
	Arr={};
	starttime=time.time();
	Arr=ChkSum(argv[1]);
	DiplayDuplicate(Arr);
	endtime=time.time();
	print(endtime-starttime);
if __name__=="__main__":
	main();
