### Week 1 Lecture notes

**C**

#### Comments

Just like JS, they start with double forward slashes: `//`

#### Data types:

1.  int
2.  float
3.  str
4.  char

Specify precision of floats by concatenating `.nnn` to the percent `%` placeholder:

```C
// no precision specified - get default:
printf("%f\n", 1.0 / 10.0);   // 0.100000

// precision to 10 digits:
printf("%.10f\n", 1.0 / 10.0);   // 0.1000000000
```

#### Quotation marks:

1.  use single quotes to wrap single characters `'Y'`
2.  use double quotes to wrap strings of multiple characters `"Yes"`

#### Comparison operators:

1. Use `==` double equals, not triple like JS strict equality
2. logical OR comparison uses double vertical bars like JS: `||`

#### Conditionals

`if` and `if ... else` work and look like JS.

```C
if (c == 'Y' || c == 'y')
{
  printf("yes\n";
}
else if (c == 'N' || c == 'n')
{
  printf("no\n");
}
```

Switches look like JS too:

```C
switch (c)
{
  case 'Y':
  case 'y':
    printf("yes\n");
    break;
  case 'N':
  case 'n':
    printf("no\n");
    break;
}
```

#### Functions:

Declarations look like JS, except you specify a **return type** during definition.

```C
#include <stdio.h>
#include <cs50.h>

// "prototype". Like declaration. Definition comes later
int square(int n);

// `int main(void)` should remain toward the top
int main(void)
{
  int x = get_int("x: ");
  printf(%i\n, square(x));
}

// finally, define `square` function
int square(int n)
{
  return n * n;
}
```

#### Compiling:

1.  `clang` compiler is built in, takes arguments
2.  easier to just use 'make' `make filename`

#### Libraries:

Import libs at the top using `#include`. Course uses a library they wrote: `cs50.h`

```C
#include <stdio.h>
#include <cs50.h>
```

#### Integer Overflow:

For a given memory register, a computer can only count so high. Ex. 8 bits. You can count from 0 to 255.

```
254 = 1 1 1 1 1 1 1 0
255 = 1 1 1 1 1 1 1 1
```
What happens when you count 1 more? Overflow:

```
256 = 0 0 0 0 0 0 0 0
```

Related: floating point imprecision:

```C
// division with precision to 55 digits:
printf("%.55f\n", 1.0 / 10.0);   // 0.1000000000000000555111512312578270
```

Why is 1 / 10 not 0.1? If you only have a finite amount of register space,
you can only permuteate them in a certain number of ways.

Subtraction can result in _underflow_: subtract 1 from zero.

### CS50 IDE

Cloud based IDE: cs50.io

`Ctrl-l` = clear terminal

Open (or create new) files from the cloud9 terminal: `c9 open <filename>`

### Week 1 (Continued) Lecture notes

#### Compiling

Source code --> Machine code

Steps:

1.  **Pre-processing** - any time there's a line of code starting with `#`, compiler goes and gets the referenced file and inserts its contents here. Like a find/replace operation.

2.  **Compile** - takes source code and converts to assembly code; not yet binary but closer to the metal.

3.  **Assembling** - converts assembly code to binary bytecode.

4.  **Linking** - merges in 3rd party libraries, our other libraries, etc.

`make` is not a compiler; it's a helper program to config and run a compiler.

#### Help

**Help with Errors**

CS50 tool: `help50 <program>` - highlights the 1st error found and tried to give advice.

Example for a compile-time error:

```
$ help50 clang -o hello hello.c
```

**Other Help Tools**

`check50` - evaluates code against psets

`style50` - suggest formatting improvements

#### Header Files

```C
#include <something.h>
```

The source code hashtag `#include` just teaches the compiler **that** something exists. Compiler needs extra step -- **linking** -- to actually _do_ the header file source code inclusion.

So if we want to `#include <cs50.h>`, we have to add a command-line argument to link it: `-l<lib name>` (no space in between the 'l' and the lib name)"

```
$ clang -o hello hello.c -lcs50
```

#### Variable Scoping

Curly braces define scope.

```C
int main(void)
{
  int n;  // declare variables in main's scope
  do
  {
    // do loop's scope -- has access to `n` in parent scope
    n = get_int("Give me a number: ");  \\ assignment OK
  }
  while (m <= 0);
}
```

#### Strings

Strings are basically arrays of `char`s followed by null terminator `\0`.

Using `#include <string.h>` header file, we gain access to string manipulation functions.
