STLIB 	= ar -cr
RANLIB  = ranlib
INCLUDE = -I. -I/usr/local/include
CPP 	= g++
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = 

#core
obj-x += core/ComputeCore.o

#communication
obj-x += communication/Message.o

#test
obj-HelloWorld += test/HelloWorld.o

