# Alyssa_Aragon_proj2
*Hexadecimal Calculator Program*

This program is designed to perform operations on hexadecimal numbers. It reads input commands from a text file, performs the operation on the provided hexadecimal numbers, and displays the result on the terminal.

*Working Process*
The calculator program processes the command-line arguments to determine the operation and the input numbers. It performs the requested operation and prints the result along with the flag status.

Each operation is implemented using appropriate C++ operators and functions. The input hexadecimal numbers are converted to 32-bit unsigned integers for arithmetic operations and logical operations. The result of each operation is then converted back to a hexadecimal string for printing.

*Flag Status*
The program determines the flag status (N and Z) based on the result of the operation. The flag status represents the state of the negative (N) and zero (Z) flags after the operation. The negative flag (N) is set when the result is negative, and the zero flag (Z) is set when the result is zero. The flag status is determined after each operation and printed along with the result.

*Command Explanations*
The program reads the following commands from commands.txt:

ADDS: Performs addition of two numbers with flag updates.
ADD: Performs addition of two numbers without flag updates.
ANDS: Performs bitwise AND of two numbers with flag updates.
AND: Performs bitwise AND of two numbers without flag updates.
ASRS: Performs arithmetic shift right of a number with flag updates.
ASR: Performs arithmetic shift right of a number without flag updates.
LSRS: Performs logical shift right of a number with flag updates.
LSR: Performs logical shift right of a number without flag updates.
LSL: Performs logical shift left of a number without flag updates.
LSLS: Performs logical shift left of a number with flag updates.
NOT: Performs bitwise NOT of a number without flag updates.
NOTS: Performs bitwise NOT of a number with flag updates.
ORR: Performs bitwise OR of two numbers without flag updates.
ORRS: Performs bitwise OR of two numbers with flag updates.
SUB: Performs subtraction of two numbers without flag updates.
SUBS: Performs subtraction of two numbers with flag updates.
XOR: Performs bitwise XOR of two numbers without flag updates.
XORS: Performs bitwise XOR of two numbers with flag updates.
