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
./mapleCompiler [-a] [-o] [-c] [-t <x64|msp430|java>] <file.c>
```

## Differences with the subject

* For blocks are implemented in the front
* Function declarations are implemented
* Array initialization for strings are implemented (no check for `char` type)

## [License](./LICENSE)
