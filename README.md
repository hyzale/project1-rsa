# CPS222 project1—rsa

##  ----File Submitted----
catch.hpp  
decrypt.cpp  
encrypt.cpp  
keygen.cpp  
numberTheory.hpp  
numberTheory.tpp  
numberTheory_TEST.cpp  
ReallyLongInt.cpp  
ReallyLongInt.hpp  
ReallyLongInt_TEST.cpp  
Makefile  
README.md  

##  ----Introduction----
This project is a basic implementation of the RSA algorithm with the ability to handle large numbers for CPS222 2018Fall. Modules including programs for generating keys, encrypting and decrypting program with provided keys, and the class helping to handle large integers with unlimited number of digits. 

##  ----Instruction---
This project contains many components. The command ‘make all’ will compile the entire project. Alternatively, you may compile according to the directions below. 

### --- keygen ---
To compile: make keygen  
To run: ./keygen <number> <number> <filename for public key> <filename for private key>   
Description:  
The keygen program is a key generator that takes two prime numbers and generates the public and private key for encryption. The first number has to be prime numbers below 100000. Moreover, to successfully encrypt ASCII values, the product of the two prime numbers need to be larger than 256.

### --- encrypt ---
To compile: make encrypt  
To run: ./encrypt <filename for public key> <filename for file that needed to be encrypted> <filename for encrypted file>  
Description:   
The encrypt program encrypts file using public key generated by key generator (or any other valid RSA key pair). 

### --- decrypt ---
To compile: make decrypt  
To run: ./decrypt <filename for private key> <filename for file that needed to be decrypted> <filename for decrypted file>  
Description:    
The decrypt program decrypts file using private key generated by key generator (or any other valid RSA key pair).   

##  ----Known Issue----

 - The lcov report shows no coverage for end curly braces in operator overloading function with pointers as return type.   
 - Minor code duplication in ReallyLongInt constructors and functions.  
 
## ---- WARNING ----
If you are from F&M and taking CS3, DO NOT COPY CODE. Talvitie is watching you.



