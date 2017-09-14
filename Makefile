INCLUDE_DIR=$(shell echo ~)/local/include
LIBRARY_DIR=$(shell echo ~)/local/lib
DESDTIR=/
PREFIX=/usr
GITREF=\"$(shell git log | head -n 1 | awk '{ print $$2; }')\"
GITSTATUS=\"$(shell echo 'if [ "x$$(git status -s)" == "x" ]; then echo "clean"; else echo "dirty"; fi' | bash)\"

CXX=g++
CXXFLAGS=-DGITREF=${GITREF} -DGITSTATUS=${GITSTATUS} -L${LIBRARY_DIR} -I${INCLUDE_DIR} -march=native -O3 -flto -std=c++14 -fPIC -Wall -Wextra -fopenmp -fno-omit-frame-pointer -g

all: libfix.a libfix.so test

install: libfix.so libfix.a src/fix.h
	mkdir -p ${DESTDIR}/${PREFIX}/lib
	cp *.a ${DESTDIR}/${PREFIX}/lib
	cp *.so ${DESTDIR}/${PREFIX}/lib
	mkdir -p ${DESTDIR}/${PREFIX}/include/fix/
	cp src/fix.h ${DESTDIR}/${PREFIX}/include/fix/

test: src/test.cc src/fix.h fix.o
	${CXX} ${CXXFLAGS} -o test src/test.cc fix.o

libfix.so: fix.o
	${CXX} ${CXXFLAGS} -shared -Wl,-soname,libfix.so -o libfix.so fix.o

libfix.a: fix.o
	 ar rcs libfix.a fix.o

fix.o: src/fix.cc src/fix.h
	${CXX} ${CXXFLAGS} -c src/fix.cc -o fix.o

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so
	rm -f test
