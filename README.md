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

## Differences with the subject

* For blocks are implemented in the front
* Function declarations are implemented
* Array initialization for strings are implemented (no check for `char` type)
* Tab in arguments does not work
* We can assign a tab to an int by passing the address of the pointer of the tab to value of the int. 
    * i.e, `int a = tab;` => `int *a = tab;`

## [License](./LICENSE)
