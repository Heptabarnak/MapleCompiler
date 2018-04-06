# MapleCompiler

MapleCompiler is a compiler for a subset of the C language.

It is written in C++ and uses [antlr4](http://www.antlr.org/) for parsing.


## Authors

- Tom Bourret
- Julien Charles-Nicolas
- Marc-Antoine Fernandes
- Justin Gally
- Vincent Guillon
- Loïc Sérazin


## Compile

The project use `cmake` to compile.

To build an executable:
```bash
mkdir build
cd build
cmake ..
cmake --build . --target MapleCompiler -- -j 2
```

## Testing

You can launch tests with:

```bash
ctest -V # -V to see cout
```

If you want to see some errors,
programs are available in `/tests` directory.

## Usage
```
./mapleCompiler [-a] [-o] [-c] [-l] [-t <x64|msp430|java>] <file.c>
```

* `-a` for static analysis
* `-o` for optimisation
* `-c` to generate ASM
* `-l` to create the executable
* `-t` to select target with x86 as default value


## Current state

### Language used

The subset include:

- Types for variables: `char`, `int32_t`, `int64_t`
- Initialization at declaration for variables
- One dimension arrays
- Function definition: functions without return type will use the type `void`
- Control structure: `if`, `else`, `while`
- Block structure with `{` and `}`
- Expressions: Every operators available in C including affectation
- Declaration of variables are always in the beginning of the function (before instructions)
- Global variables
- Global functions `putchar` and `getchar` for I/O
- A constant char like `'a'`
- Only one source file with no pre-processing (will ignore every pre-processor directives)

Everything was implemented and is working, 
so we added some new things:

- `for` control structure
- String initialization as an array of `char` (or anything actually)
- Exponential notation like `5e2` (casted to an `int64_t`, so errors can appear!)
- Function declaration (to allow recursion between two functions)

### Other changes

- During array initialization: We forbid a bigger list of values than the size of the array (e.g. `a[1]={1,2}` is not allowed)
- Arrays in arguments does not work as it implies pointers (it will not fail, but will be false!)
- We can assign an array to an int by passing the address of the tab to value of the int. 
   - e.g. `int a = tab;` => `int a = (int)(tab);`
- Everything is cast without any checks!

### Static analysis

Static analysis detect 3 potentials errors:
- If a variable is never used
- If a variables is never read
- If a variables is used before affectation


### Back-end completion

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
- [ ] 5.14: Correct handling of types (90%) -> Available on the branch [`type-size`](https://github.com/Heptabarnak/MapleCompiler/tree/type-size)
- [x] 5.15: Compile function callswith more than 6 arguments


## [License](./LICENSE)
