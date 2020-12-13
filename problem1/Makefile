# Makefile
CXX=g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
BINARIES=testException1 testException5

all: ${BINARIES}

testException1: testException1.o tddFuncs.o
	${CXX} $^ -o $@

testException5: testException5.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testException1
	./testException5

clean:
	/bin/rm -f ${BINARIES} *.o
