#include "calculator.h"

int main() {
    Calculator calc;
    
    ifstream inputFile("commands.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream out(line);
        string command, operand1, operand2;
        int shift; 

        out >> command; 

        if (command == "ADD") {
            out >> operand1 >> operand2;
            calc.ADD(operand1, operand2);
        }
        else if (command == "ADDS"){
            out >> operand1 >> operand2;
            calc.ADDS(operand1, operand2);
        }
        else if (command == "AND"){
            out >> operand1 >> operand2;
            calc.AND(operand1,operand2);
        }
        else if (command == "ANDS"){
            out >> operand1 >> operand2;
            calc.ANDS(operand1, operand2); 
        }
        else if (command == "SUB"){
            out >> operand1 >> operand2;
            calc.SUB(operand1, operand2);
        }
        else if (command == "SUBS"){
            out >> operand1 >> operand2;
            calc.SUBS(operand1, operand2);  
        }
        else if (command == "ASR"){
            out >> operand1 >> shift;
            calc.ASR(operand1,shift);
        }
        else if (command == "ASRS"){
            out >> operand1 >> shift; 
            calc.ASRS(operand1, shift); 
        }
        else if (command == "LSR"){
            out >> operand1 >> shift;
            calc.LSR(operand1,shift);
        }
        else if (command == "LSRS"){
            out >> operand1 >> shift;
            calc.LSRS(operand1,shift); 
        }
        else if (command == "LSL"){
            out >> operand1 >> shift;
            calc.LSL(operand1,shift); 
        }
        else if (command == "LSLS"){
            out >> operand1 >> shift; 
            calc.LSLS(operand1,shift); 
        }
        else if (command == "NOT"){
            out >> operand1;
            calc.NOT(operand1); 
        }
        else if (command == "NOTS"){
            out >> operand1;
            calc.NOTS(operand1); 
        }
        else if (command == "XOR"){
            out >>  operand1 >> operand2;
            calc.XOR(operand1, operand2); 
        }
        else if (command == "XORS"){
            out >>  operand1 >> operand2;
            calc.XORS(operand1,operand2); 
        }
        else if (command == "ORR"){
            out >> operand1 >> operand2;
            calc.ORR(operand1,operand2); 
        }
        else if (command == "ORRS"){
            out >> operand1 >> operand2;
            calc.ORRS(operand1, operand2);
        }
    }

    inputFile.close();

    return 0;
}