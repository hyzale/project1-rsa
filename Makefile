default: all

all: encrypt decrypt keygen 

ReallyLongInt.o: ReallyLongInt.hpp ReallyLongInt.cpp
	g++ -c ReallyLongInt.cpp	

encrypt: encrypt.cpp ReallyLongInt.o
	g++ -o encrypt encrypt.cpp ReallyLongInt.cpp

decrypt: decrypt.cpp ReallyLongInt.o
	g++ -o decrypt decrypt.cpp ReallyLongInt.cpp

keygen: keygen.cpp ReallyLongInt.o
	g++ -g -o keygen keygen.cpp ReallyLongInt.cpp


ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.o catch.hpp
	g++ -o ReallyLongInt_TEST ReallyLongInt.cpp ReallyLongInt_TEST.cpp
	./ReallyLongInt_TEST

numberTheory_TEST: numberTheory_TEST.cpp ReallyLongInt.o catch.hpp
	g++ -o numberTheory_TEST ReallyLongInt.cpp numberTheory_TEST.cpp
	./numberTheory_TEST

tests: numberTheory_TEST ReallyLongInt_TEST

testgcov_ReallyLongInt: ReallyLongInt_TEST
	g++ --coverage -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp 
	./ReallyLongInt_TEST 
	gcov ReallyLongInt.cpp 

testlcov_ReallyLongInt: testgcov_ReallyLongInt
	lcov --directory ./ --zerocounters
	./ReallyLongInt_TEST
	lcov --directory ./ --capture --output-file ReallyLongInt_TEST.info
	genhtml --output-directory coverage ReallyLongInt_TEST.info

testgcov_numberTheory: numberTheory_TEST
	g++ --coverage -o numberTheory_TEST ReallyLongInt.cpp numberTheory_TEST.cpp 
	./numberTheory_TEST 
	gcov numberTheory_TEST.cpp

testlcov_numberTheory: testgcov_numberTheory
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	lcov --directory ./ --capture --output-file numberTheory_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info

tesetgcov: testgcov_numberTheory testgcov_ReallyLongInt

testlcov: tesetgcov
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	./ReallyLongInt_TEST
	lcov --directory ./ --capture --output-file ReallyLongInt_TEST.info
	lcov --directory ./ --capture --output-file numberTheory_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info ReallyLongInt_TEST.info

clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM encrypt decrypt numberTheory_TEST keygen coverage a.out reallyLongInt_TEST ReallyLongInt_TEST