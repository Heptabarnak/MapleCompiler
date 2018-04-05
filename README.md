# MapleCompiler

MapleCompiler is a compiler for a subset of the C language.

It is written in C++.

## Authors

- Tom Bourret
- Julien Charles-Nicolas
- Marc-Antoine Fernandes
- Justin Gally
- Vincent Guillon
- Loïc Sérazin


## Compile

The project use `cmake` to compile.

## Usage
```
./mapleCompiler [-a] [-o] [-c] [-l] [-t <x64|msp430|java>] <file.c>
```

* `-a` for static analysis
* `-o` for optimisation
* `-c` to generate ASM
* `-l` to create the executable
* `-t` to select target with x86 as default value

## Subject Completion

- [x] 5.1: Generate an empty frame
- [x] 5.2: Understand activation registration and the ABI
- [x] 5.3: Compile a program which executes a `putchar()`
- [x] 5.4: Compile variable affectation
- [x] 5.5: Compile expressions
- [x] 5.6: Compile an `if ... else`block
- [x] 5.7: Compile `while`loops
- [x] 5.8: Compile value return
- [x] 5.9: Compile `lvalue` affectation with any value
- [x] 5.10: Compile arrays
- [x] 5.11: Compile function calls up to 6 arguments
- [x] 5.12: Compile `for` loops
- [x] 5.13: Complex programs testing (Collatz conjecture/Suite de Syracuse, Ackermann function, ...)
- [ ] 5.14: Correct handling of types (Work In Progress, 90%)
- [x] 5.15: Compile function callswith more than 6 arguments

## Differences with the subject

* For blocks are implemented in the front-end (not only in the back-end)
* Function declarations are implemented
* Array initialization for strings are implemented (no check for `char` type)
* During array initialization: We forbid a bigger list of values than the size of the array (e.g. `a[1]={1,2}` is not allowed)
* Arrays in arguments does not work
* We can assign a tab to an int by passing the address of the tab to value of the int. 
    * e.g. `int a = tab;` => `int a = (int)(tab);`
* We allow implicit casts
* Exponential values are implemented (e.g. `5e3` => 5000)
* Static analysis: a variable is never used / a variable is never read / a variable is used before affectation

## [License](./LICENSE)
