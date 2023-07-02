# Assembly and C

## Basic Instruction

* `add_function_assembly.c`. Script that implements a function in Assembly to be able to do sum of two numbers.
* `assembly_instruction.c`. Script showing how to insert assembly code into a C program.

### `assembly_instruction`

Before script run

![](./Assembly_and_C/test_1/image/assembly_instruction_before_run.png)

After script run

![](./Assembly_and_C/test_1/image/assembly_instruction_after_run.png)

### Conditional Execution

| Flag | Description |
| --- | --- |
| negative flag (N) | set if the result of ALU is negative (i.e., bit[31] is 1), and is cleared otherwise |
| zero flag (Z) | set if the ALU result is zero, and is cleared otherwise |
| carry flag (C) | set if a carry occurs in unsigned addition, and is cleared otherwise. For unsigned subtraction, it is set if no borrow has occurred, |  cleared otherwise |
| overflow flag (V) | set if an overflow takes place when performing a signed addition or subtraction, and is cleared otherwise |
| saturation flag (Q) | set if an SSAT or USAT instruction causes saturation, and is cleared otherwise |

| Suffix | Description | Flags tested |
| --- | --- | --- |
| EQ | EQual | Z=1 |
| NE | Not Equal | Z=0 |
| CS/HS | unsigned Higher or Same | C=1 |
| CC/LO | unsigned LOwer | (=0 |
| MI | Minus (negative) | N=l |
| PL | Plus (positive or zero) | N=0 |
| vs | overflow Set | V=l |
| vc | o Verflow Clear | V=0 |
| HI | unsigned Higher | C=l&Z=0 |
| LS | unsigned Lower or Same | C=0orZ = l |
| GE | signed Greater or Equal | N=V |
| LT | signed Less Than | N !=V |
| GT | signed Greater Than | Z=0&N=V |
| LE | signed Less than or Equal | Z = 1 or N! = V |
| AL | AL ways

The CMP instruction "CMP r0, rl" is equivalent to the subtraction operation `r0 - r1` except the result is discarded.

### Branch Instruction

*Unconditional Branch*

| Instruction | Description | Flags tested |
| --- | --- | --- |
| B Label |  Branch to label | none

*Conditional Branch*

| Instruction | Description | Flags tested |
| --- | --- | --- |
| BEQ Label | Branch if EQual | Z=l
| BNE Label | Branch if Not Equal | Z =0
| BCS/BHS Label | Branch if unsigned Higher or Same | C=l
| BCC/BLO Label | Branch if unsigned LOwer | C=0
| BM! Label | Branch if Minus (Negative) | N =1
| BPL Label | Branch if Plus (Positive or Zero) | N=0
| BVS Label | Branch if o Verflow Set | V= l
| BVC Label | Branch if o Verflow Clear | V=0
| BHI Label | Branch if unsigned Higher | C =l&Z=0
| BLS Label | Branch if unsigned Lower or Same | C = 0 or Z = 1
| BGE Label | Branch if signed Greater or Equal | N=V
| BLT Label | Branch if signed Less Than | N !=V
| BGT Label | Branch if signed Greater Than | Z =0&N=V
| BLE Label | Branch if signed Less than or Equal | Z = 1 or N = !V


| Comparison | Signed | Unsigned |
| --- | --- | --- |
| == | BEQ | BEQ |
| != | BNE | BNE |
| >  | BGT | BHI |
| >= | BGE | BHS |
| <  | BLT | BLO |
| <= | BLE | BLS |

Example of this chapter are in:

* `assembly_if.c`
* `assembly_for.c`
* `assembly_while.c`
* `assembly_do_while.c`
* `assembly_continue_statement.c`
* `assembly_break.c`
