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

* For blocks are implemented in the front-end (not only in the back-end)
* Function declarations are implemented
* Array initialization for strings are implemented (no check for `char` type)
* During Array initialization: We forbid a bigger list of values than the size of the array (e.g. a[1]={1,2} is not allowed)
* Arrays in arguments does not work
* We can assign a tab to an int by passing the address of the tab to value of the int. 
    * e.g. `int a = tab;` => `int a = (int)(tab);`

## [License](./LICENSE)
