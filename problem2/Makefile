CXX=-clang++

# CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=testMatrix1 testMatrix1Y 

all: ${BINARIES}

testMatrix1: matrixMultiply.o testMatrix1.o 
	${CXX} $^ -o $@

testMatrix1Y: matrixMultiply.o testMatrix1Y.o 
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testMatrix1
	./testMatrix1Y
clean:
	/bin/rm -f ${BINARIES} *.o
