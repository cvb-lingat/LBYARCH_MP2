# LBYARCH MP2 x86 to C Programming Project

Made By:
* Donaire, Lorenzo Lyon
* Lingat, Carl Vincent Blix
  
Section: S11A

## (IMPORTANT) How to Run

* Make sure that data.txt, DAXPY_ASM.asm, and MP2_Main.c are in the same folder
* Do the normal Compile, Assemble, and Run for interfacing x86-64 and C

Note: Inputs must be placed in data.txt in the following format:

size of vectors

A

elements of vector X

elements of vector Y


## Comparative Execution Time and Short Analysis of Performance of Kernels

Both kernel execution times were run together 30 times to compare and compute their average runtime.

Average Run Time of Assembly and C with a 2^20 Input:

Assembly: 2.43 ms

C: 4.4 ms

Dividing Avg C runtime (4.4) by Avg ASM runtime (2.43) roughly equals 1.811, indicating that Assembly, on average, is 1.81 times faster than C. Assembly is consistently lower than or equal to the runtime of C in every iteration of the average runtime computation, where Assembly runtimes are between 1 - 3ms and C runtimes are between 3 - 6ms. On most runs, Assembly is 1 - 2 units faster than C.

C runtimes show that the C version of the DAXPY function is slower and more variable, as it peaks at even 6ms in some of the runs. Overall, Assembly's runtime is more consistent, stable, and faster than C in comparison.

## Program Screenshots
* Main Menu:
<img width="376" height="92" alt="image" src="https://github.com/user-attachments/assets/d94263b3-2bad-419b-9274-07c4d8a69849" />

* Assembly:
<img width="344" height="286" alt="image" src="https://github.com/user-attachments/assets/ab98edb3-99c6-4ad1-a3c4-11cd4d7611f0" />

 
* C:
<img width="321" height="280" alt="image" src="https://github.com/user-attachments/assets/65ee27dd-d8ba-43b4-9e75-c1c698de0626" />

* Assembly and C with Sanity Check:
<img width="534" height="315" alt="image" src="https://github.com/user-attachments/assets/1589919c-0714-4145-a4e8-41b9e034ef00" />

## Program Demo Video
https://youtu.be/HurWfGxq1jY
