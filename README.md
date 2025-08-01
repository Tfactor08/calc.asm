## calc.asm
Reverse Polish calculator from K&amp;R book with partial FASM implementation.

### Notation
Reverse Polish notation (postfix notation) is a mathematical notation in which operators follow their operands (e.g. + 34 35). \
It's easier to evaluate expression in postfix notation rather than one in normal infix notation (e.g. 34 + 35) since expressions can be read from left to right and immediately evaluated when proper number of operands are encountered. \
For example, the infix expression `17 * 2 + 35` becomes `17 2 * 35 +`.

### Build and Run
The calculator provides only basic arithmetic operations, which are written in Flat Asssembler (FASM). \
So, fasm assembler and C compiler are needed to compile the `ops.asm` and `main.c` programs:
```bash
./build.sh
./main
```
