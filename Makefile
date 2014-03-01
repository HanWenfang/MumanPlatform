

include common.mk

default: libMumanPlatform.a test/HelloWorld

libMumanPlatform.a: $(obj-x)
	$(STLIB) $@ $^
	$(RANLIB) $@

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@

%.o: %.c
	$(CXX) -Wall $(INCLUDE) -c $< -o $@


clean:
	rm -rf libMumanPlatform.a $(obj-x) $(obj-HelloWorld) test/HelloWorld



