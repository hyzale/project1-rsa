
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

testgcov: tests
	g++ --coverage -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp
	./numberTheory_TEST
	gcov numberTheory.cpp

testlcov: testgcov
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	lcov --directory ./ --capture --output-file numberTheory_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info

clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov encrypt decrypt numberTheory_TEST coverage a.out