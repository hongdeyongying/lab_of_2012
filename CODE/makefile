
# edit for the suitable path to the dependent thirdpacke directory
export THIRD_PACKAGE=$(HOME)/workspace/SETUP/lab_of_2012/thirdpackage/


all:
	make -C public
	make -C TEST
	make -C DGW
	make -C UGW


clean:	
	make -C DGW clean
	make -C UGW clean
	make -C TEST clean
	make -C public clean

install:
	make -C DGW install 
	make -C UGW install
