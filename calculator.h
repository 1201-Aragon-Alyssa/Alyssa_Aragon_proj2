#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
using namespace std;

class Calculator{
string Hex1, Hex2; 
public: 
    Calculator(); 
    Calculator(string, string); 
    Calculator(const Calculator &rhs); 

    void setHex1(const string&); 
    string getHex1() const; 
    void setHex2(const string&); 
    string getHex2() const; 

    void ADD(const string, const string);
    void ADDS(const string, const string); 
    void SUB(const string, const string); 
    void SUBS(const string, const string); 
    void AND(const string, const string); 
    void ANDS(const string, const string);
    void ASR(const string, const int); 
    void ASRS(const string, const int); 
    void LSR(const string, const int); 
    void LSRS(const string, const int); 
    void LSL(const string, const int); 
    void LSLS(const string, const int); 
    void NOT (const string); 
    void NOTS(const string); 
    void ORR (const string, const string); 
    void ORRS(const string, const string); 
    void XOR(const string, const string); 
    void XORS(const string, const string); 
    void printFlagStatus(bool, bool); 
};
#endif