default: all

all: encrypt decrypt keygen reallyLongInt.o
	
numberTheory.o: numberTheory.hpp numberTheory.cpp
	g++ -c numberTheory.cpp

encrypt: encrypt.cpp numberTheory.o
	g++ -o encrypt encrypt.cpp numberTheory.o

decrypt: decrypt.cpp numberTheory.o
	g++ -o decrypt decrypt.cpp numberTheory.o

keygen: keygen.cpp numberTheory.o
	g++ -g -o keygen keygen.cpp numberTheory.o

# reallyLongInt.o: reallyLongInt.hpp reallyLongInt.hpp
#	g++ -c reallyLongInt.cpp

ReallyLongInt.o: ReallyLongInt.hpp ReallyLongInt.cpp
	g++ -c ReallyLongInt.cpp


# reallyLongInt_TEST: reallyLongInt_TEST.cpp reallyLongInt.o catch.hpp
# 	g++ -o reallyLongInt_TEST reallyLongInt_TEST.cpp reallyLongInt.cpp
# 	./reallyLongInt_TEST

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.o catch.hpp
	g++ -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp
	./ReallyLongInt_TEST

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.o catch.hpp
	g++ -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp
	./numberTheory_TEST

tests: numberTheory_TEST ReallyLongInt_TEST # reallyLongInt_TEST

# testgcov_reallyLongInt: reallyLongInt_TEST
# 	g++ --coverage -o reallyLongInt_TEST reallyLongInt_TEST.cpp reallyLongInt.cpp 
# 	./reallyLongInt_TEST 
# 	gcov reallyLongInt.cpp 

# testlcov_reallyLongInt: testgcov_reallyLongInt
# 	lcov --directory ./ --zerocounters
# 	./reallyLongInt_TEST
# 	lcov --directory ./ --capture --output-file reallyLongInt_TEST.info
# 	genhtml --output-directory coverage reallyLongInt_TEST.info

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
	g++ --coverage -o numberTheory_TEST numberTheory_TEST.cpp numberTheory.cpp 
	./numberTheory_TEST 
	gcov numberTheory.cpp 

testlcov_numberTheory: testgcov_numberTheory
	lcov --directory ./ --zerocounters
	./numberTheory_TEST
	lcov --directory ./ --capture --output-file numberTheory_TEST.info
	genhtml --output-directory coverage numberTheory_TEST.info

clean:
	rm -R *.o *.gcda *.info *.gcno *.gcov *.dSYM encrypt decrypt numberTheory_TEST keygen coverage a.out reallyLongInt_TEST ReallyLongInt_TEST