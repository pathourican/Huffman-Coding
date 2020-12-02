# Patrick Hourican
# pjh4as
# 11/9/2020
# Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #Enable all warnings
DEBUG=-g

main: huffmanenc huffmandec

huffmanenc: huffmanenc.o heap.o huffmanNode.o
		$(CXX) $(DEBUG) huffmanenc.o heap.o huffmanNode.o -o encoder

huffmandec: huffmandec.o huffmanNode.o
		$(CXX) $(DEBUG) huffmandec.o huffmanNode.o -o decoder

huffmanenc.o: huffmanenc.cpp

huffmandec.o: huffmandec.cpp

heap.o: heap.cpp heap.h

huffmanNode.o: huffmanNode.cpp huffmanNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ encoder decoder
