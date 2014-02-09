STLIB 	= ar -cr
RANLIB  = ranlib
INCLUDE = -I. -I/usr/local/include
CPP 	= g++
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = -lMumanPlatform -lPocoFoundation

#core
obj-x += core/ComputeCore.o
obj-x += core/AsynCore.o

#communication
obj-x += communication/Message.o
obj-x += communication/MessageHandler.o
obj-x += communication/Protocol.o

#ranks
#obj-x += Ranks/UniqueServer.o
obj-x += Ranks/ArgumentsParser.o

#reactor
obj-x += reactor/Reactor.o

#test
obj-HelloWorld += test/HelloWorld.o

