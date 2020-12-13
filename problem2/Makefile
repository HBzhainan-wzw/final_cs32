CXX=-clang++

# CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=testMatrix1 

all: ${BINARIES}

testMatrix1: matrixMultiply.o testMatrix1.o 
	${CXX} $^ -o $@

tests: ${BINARIES}
	./testMatrix1

clean:
	/bin/rm -f ${BINARIES} *.o
