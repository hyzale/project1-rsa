default: all

numberTheory.o: numberTheory.hpp numberTheory.cpp
	g++ -c numberTheory.cpp

encrypt: encrypt.cpp numberTheory.o
	g++ -o encrypt encrypt.cpp numberTheory.o

decrypt: decrypt.cpp numberTheory.o
	g++ -o decrypt decrypt.cpp numberTheory.o

keygen: keygen.cpp numberTheory.o
	g++ -g -o keygen keygen.cpp numberTheory.o

reallyLongInt.o: reallyLongInt.hpp reallyLongInt.hpp
	g++ -c reallyLongInt.cpp

all: encrypt decrypt keygen reallyLongInt.o

reallyLongInt_TEST: reallyLongInt_TEST.cpp reallyLongInt.o catch.hpp
	g++ -o reallyLongInt_TEST reallyLongInt_TEST.cpp reallyLongInt.cpp
	./reallyLongInt_TEST

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.o catch.hpp
	g++ -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp
	./numberTheory_TEST

tests: numberTheory_TEST reallyLongInt_TEST

testgcov_reallyLongInt: reallyLongInt_TEST
	g++ --coverage -o reallyLongInt_TEST reallyLongInt_TEST.cpp reallyLongInt.cpp 
	./reallyLongInt_TEST 
	gcov reallyLongInt.cpp 

testlcov_reallyLongInt: testgcov_reallyLongInt
	lcov --directory ./ --zerocounters
	./reallyLongInt_TEST
	lcov --directory ./ --capture --output-file reallyLongInt_TEST.info
	genhtml --output-directory coverage reallyLongInt_TEST.info


testgcov_numberTheory: numberTheory_TEST
	g++ --coverage -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp 
	./numberTheory_TEST 
	gcov numberTheory.cpp 

testlcov_numberTheory: testgcov_numberTheory
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	lcov --directory ./ --capture --output-file numberTheory_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info

clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov encrypt decrypt numberTheory_TEST keygen coverage a.out reallyLongInt_TEST