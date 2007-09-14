all: lond.so

lond.so: xchat-dll.cpp xchat-dll.h dllmain.cpp
	g++ -Wl,--export-dynamic -Wall -O1 -shared -fPIC xchat-dll.cpp -o lond.so -lboost_regex-gcc41

