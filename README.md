Notes and coursework for Harvard's CS50x

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
