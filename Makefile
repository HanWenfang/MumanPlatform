

include common.mk

default: libMumanPlatform.a test/HelloWorld worker/MessageSystem

libMumanPlatform.a: $(obj-x) database/cJSON.o
	$(STLIB) $@ $^
	$(RANLIB) $@

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

worker/MessageSystem: $(obj-MessageSystem)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

database/cJSON.o: database/cJSON.c database/cJSON.h
	$(CXX) -Wall $(INCLUDE) -c $< -o $@

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@

clean:
	rm -rf libMumanPlatform.a $(obj-x) $(obj-HelloWorld) test/HelloWorld database/cJSON.o



