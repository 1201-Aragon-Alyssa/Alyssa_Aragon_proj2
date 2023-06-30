#include "calculator.h"

Calculator::Calculator(){
    Hex1 = "0A";
    Hex2 = "0A";
}
Calculator::Calculator(string num1, string num2){
    Hex1 = num1; 
    Hex2 = num2; 
}

Calculator::Calculator(const Calculator &rhs){
    Hex1 = rhs.Hex1;
    Hex2 = rhs.Hex2; 
}

void Calculator::setHex1(const string& hex) {
    Hex1 = hex;
}

void Calculator::setHex2(const string& hex) {
    Hex2 = hex;
}

string Calculator::getHex1() const {
    return Hex1;
}

string Calculator::getHex2() const {
    return Hex2;
}

void Calculator::ADD(const string num1,const string num2){
    string hex1 = num1.substr(2);
    string hex2 = num2.substr(2);

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t sum = value1 + value2; 
    cout << "ADD " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << sum << endl;

    printFlagStatus(0,0);


} 

void Calculator::ADDS(const string num1, const string num2){
    string hex1 = num1.substr(2);
    string hex2 = num2.substr(2);

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t sum = value1 + value2; 
    cout << "ADDS " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << sum << endl;

    bool N = ((sum >> 31) & 1) == 1;
    bool Z = sum == 0;
    printFlagStatus(N, Z);

}

void Calculator::SUB(const string num1, const string num2) {
    string hex1 = num1.substr(2);
    string hex2 = num2.substr(2);

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1 - value2;
    cout << "SUB " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0);
    
}

void Calculator::SUBS(const string num1, const string num2) {
    string hex1 = num1.substr(2);
    string hex2 = num2.substr(2);

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1 - value2;
    cout << "SUBS " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = ((result >> 31) & 1) == 1;
    bool Z = result == 0;
    printFlagStatus(N, Z);
    
}

void Calculator::AND(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1 & value2;

    cout << "AND " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0);
}

void Calculator::ANDS(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1 & value2;

    cout << "ANDS " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = (result & 0x80000000) != 0;
    bool Z = (result == 0);

    printFlagStatus(N, Z);
    
}

void Calculator::ASR(const string num1, const int shift){
    string hex1 = num1.substr(2); 

    uint32_t value = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value;

    int32_t signedValue = static_cast<int32_t>(value);
    int32_t result = signedValue >> shift;

    cout << "ASR " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0); 
}

void Calculator::ASRS(const string num1, const int shift){
    string hex1 = num1.substr(2); 

    uint32_t value = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value;

    int32_t signedValue = static_cast<int32_t>(value);
    uint32_t result = signedValue >> shift;

    cout << "ASRS " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = (result < 0);
    bool Z = (result == 0);
    printFlagStatus(N, Z);
}

void Calculator::LSR(const string num1, const int shift){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = value >> shift;

    cout << "LSR " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0);
}

void Calculator::LSRS(const string num1, const int shift){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = value >> shift;

    cout << "LSRS " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0, (result == 0));
}

void Calculator::LSL(const string num1, int shift){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = value << shift;

    cout << "LSL " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0);
}

void Calculator::LSLS(const string num1, int shift){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = value << shift;

    cout << "LSLS " << num1 << " " << shift << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = ((result & 0x80000000) != 0); 
    bool Z = (result == 0); 

    printFlagStatus(N, Z);
}

void Calculator::NOT(const string num1){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = ~value;

    cout << "NOT " << num1 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0); 
}

void Calculator::NOTS(const string num1){
    string hex1 = num1.substr(2);
    uint32_t value = 0;

    stringstream ss;
    ss << hex << hex1;
    ss >> value;

    uint32_t result = ~value;

    cout << "NOTS " << num1 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = ((result & 0x80000000) != 0);
    bool Z = (result == 0); 

    printFlagStatus(N, Z); 
}

void Calculator::ORR(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1|value2;

    cout << "ORR " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0);
}

void Calculator::ORRS(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1|value2;

    cout << "ORRS " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = ((result & 0x80000000) != 0);
    bool Z = (result == 0); 

    printFlagStatus(N, Z);
}

void Calculator::XOR(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1^value2;

    cout << "XOR " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    printFlagStatus(0,0); 
}

void Calculator::XORS(const string num1, const string num2){
    string hex1 = num1.substr(2); 
    string hex2 = num2.substr(2); 

    uint32_t value1 = 0; 
    uint32_t value2 = 0; 

    stringstream ss1;
    ss1 << hex << hex1;
    ss1 >> value1;

    stringstream ss2;
    ss2 << hex << hex2;
    ss2 >> value2;

    uint32_t result = value1^value2;

    cout << "XORS " << num1 << " " << num2 << ": ";
    cout << "0x" << setw(8) << setfill('0') << hex << uppercase << result << endl;

    bool N = ((result & 0x80000000) != 0); 
    bool Z = (result == 0);
    
    printFlagStatus(N,Z); 
}

void Calculator::printFlagStatus(bool N, bool Z){

    cout << "N: " << (N ? "1" : "0") << " Z: " << (Z ? "1" : "0") << endl ;

}