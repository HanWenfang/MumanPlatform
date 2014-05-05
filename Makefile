

include common.mk

default: libMumanPlatform.a test/HelloWorld worker/MessageSystem main-cgi/main-get.cgi main-cgi/main-post.cgi

libMumanPlatform.a: $(obj-x) database/cJSON.o
	$(STLIB) $@ $^
	$(RANLIB) $@

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

worker/MessageSystem: $(obj-MessageSystem)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

main-cgi/main-get.cgi: $(obj-main-get)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

main-cgi/main-post.cgi: $(obj-main-post)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

database/cJSON.o: database/cJSON.c database/cJSON.h
	$(CXX) -Wall $(INCLUDE) -c $< -o $@

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@

clean:
	rm -rf libMumanPlatform.a $(obj-x) $(obj-HelloWorld) $(obj-main-get) $(obj-main-post) test/HelloWorld worker/MessageSystem database/cJSON.o main-cgi/main-get.cgi main-cgi/main-post.cgi



