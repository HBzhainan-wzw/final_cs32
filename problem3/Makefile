# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=testFootwearOrder testFootwearOrderY

all: ${BINARIES}

testFootwearOrder: testFootwearOrder.o FootwearOrder.o FootwearItem.o GetCreative.o PreMadeDeal.o tddFuncs.o
	${CXX} $^ -o $@

testFootwearOrderY: testFootwearOrderY.o FootwearOrder.o FootwearItem.o GetCreative.o PreMadeDeal.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
