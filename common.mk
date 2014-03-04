STLIB 	= ar -cr
RANLIB  = ranlib
INCLUDE = -I. -I/usr/local/include
CPP 	= g++
CXX		= gcc
LIBRARY = -L. -L/usr/local/lib
SYSLIBS = -lMumanPlatform -lPocoFoundation -lm

#core
obj-x += core/ComputeCore.o
obj-x += core/AsynCore.o

#communication
obj-x += communication/Message.o
obj-x += communication/MessageHandler.o
obj-x += communication/Protocol.o
obj-x += communication/Connect.o
obj-x += communication/VirtualCommunicator.o

#ranks
#obj-x += ranks/UniqueServer.o
obj-x += ranks/ArgumentsParser.o

#reactor
obj-x += reactor/Reactor.o
obj-x += reactor/TReactor.o

#proactor
obj-x += proactor/Proactor.o

#routers
obj-x += routers/PointToPoint.o

#thread
obj-x += thread/ThreadManager.o

#database
obj-x += database/LinkDB.o
obj-x += database/JSONNode.o

#actors
obj-x += actors/Actor.o

#test
obj-HelloWorld += test/HelloWorld.o

#worker
obj-MessageSystem += worker/MessageSystem.o
obj-MessageSystem += worker/Online.o
