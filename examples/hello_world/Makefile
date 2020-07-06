LIBS= -lcrypto -lcppcms -lbooster 


all: hello

hello: hello.cpp
	$(CXX) -O2 -Wall -g hello.cpp -o hello ${LIBS}

clean:
	rm -fr hello.dSYM hello hello.exe cppcms_rundir
