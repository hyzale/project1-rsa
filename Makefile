
numberTheory.o: numberTheory.hpp numberTheory.cpp
	g++ -c numberTheory.cpp

encrypt: encrypt.cpp numberTheory.o
	g++ -o encrypt encrypt.cpp numberTheory.o

decrypt: decrypt.cpp numberTheory.o
	g++ -o decrypt decrypt.cpp numberTheory.o

all: encrypt decrypt

numberTheory_TEST: numberTheory_TEST.cpp catch.hpp
	g++ -o numberTheory_TEST numberTheory_Test.cpp numberTheory.cpp

tests: numberTheory_TEST

testgcov: numberTheory_TEST.cpp numberTheory.cpp
	g++ --coverage -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp

testlcov: 
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	lcov --directory ./ --capture --output-file absolute_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info

clean:
	rm *.o *.gcda *.info *.gcno encrypt decrypt numberTheory_TEST