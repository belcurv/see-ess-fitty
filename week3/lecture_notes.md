# Week 3 Lecture

https://video.cs50.net/2017/fall/lectures/4

### Memory

Bytes in memory each have a location with some numerical address indicating its position. C programs have a structure to how that memory is used:

| Area                   | Description |
| ---------------------- |-------------|
| `text`                 | |
| `initialized data`     | |
| `uninitialized data`   | |
| `heap`                 | where memory for `malloc` comes from |
| `stack`                | chunks of memory - stack frames - for functions |
| `environment variables`| |

We're mainly concerned with the heap and the stack at this point. The stack is used for functions. For our C programs, the very bottom of the stack contains a chunk of memory for `main`, such as any local variables or arguments.

### Strings

`string` is not actually a real C type. That's a 'gift' from the CS50 Library (`cs50.h`). It turns out, `string` is just a synonym for `char *`.

```C
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get two strings
    char *s = get_string("s: ");  // <-- char *
    char *t = get_string("t: ");  // <-- char *

    // compare strings for equality
    if (strcmp(s, t) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}
```

When we previously wrote expressions like `string s = get_string("s: ");` we created a variable `s` in **one memory location**.

```
s[ ]
```

And then whatever the user typed in was stored in some bytes in **a different memory location**. `s` just stored the _memory address_ of the first character of the array (all trings are arrays) of those other bytes -- `100` in this case:

```
| S | t | e | l | i | o | s | \0 |
 100 101 102 103 104 105 106 107
```

In the above example, `s` will contain the value `100` -- **pointing** to the first character. We know where the string ends: `\0`.

This is why we can't use simple equality `==` operators when comparing strings. Comparing two strings `s == t` will always show that they’re different because `s` and `t` are not _actually_ strings, but are `char *`: the addresses of a specific character in memory. `s` might have a value like `100`, while `t` might have a value `300` -- those are obviously different.

In C, variables that store addresses of other variables are called **pointers**. (The * symbol indicates that a variable is a pointer to some other variable type, so we could have int * in addition to char * and others.)

### Copying Strings

```C
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");    // get a string
    if (!s)                         // make sure it's a valid string
    {
        return 1;                   // if not, exit with code 1
    }

    char *t = malloc((strlen(s) + 1) * sizeof(char));   // allocate memory for another string
    if (!t)                                             // check that t is not NULL;
    {                                                   // malloc could have failed.
        return 1;                                       // If it did, exit with code 1
    }

    for (int i = 0, n = strlen(s); i <= n; i++)         // iteratively copy string
    {
        t[i] = s[i];                                    // set each char 1 by 1
    }

    if (strlen(t) > 0)                                  // make sure the string has length
    {                                                   // ... then ...
        t[0] = toupper(t[0]);                           // capitalize first letter in copy
    }

    printf("s: %s\n", s);                               // print strings
    printf("t: %s\n", t);

    free(t);                                            // free memory
    return 0;                                           // clean exit
}
```

### Pointer Arithmetic

In stead of referencing `char`s using `[bracket]` notation, we can just add to the pointer, since it's really an address. Below we have to use the `*` notation (around that address) to get the value stored at the resulting address:

```C
for (int i = 0, n = strlen(s); i < n; i++)
{
    printf("%c\n", *(s + i));   // <-- adds integer `i` to the starting address each time
}
```

`scanf` is a function in C's `stdio.h` library that reads from the user’s keyboard. The arguments it takes are like `printf`'s, but instead of printing to the screen it stores values to variables.

```
#include <stdio.h>

int main(void)
{
    int x;                 // declare x
    printf("x: ");         // prompt user
    scanf("%i", &x);       // get keyboard input, store in x -- note the &
    printf("x: %i\n", x);  // output
}
```

Remember, when we initialize `x` it's like this:

```
int x [   ]
       500
```

So in the snippet above, `scanf` looks for `%i` (integer) input to store in `&x`. The `&` gets us **the address** of that variable. So we are passing _the address of `x`_ (eg, 500) to scanf, so it can store the input value into x.

### Images

Files are a sequence of bytes, where each byte has some offset from the beginning. To write a program that reads certain types of files, we need to find documentation on those standardized file types.

The JPEG file standard stipulates that every file starts with the same three bytes: 255 216 255.

Those values are commonly represented in hex. By convention we prefix hexadecimal values with `0x`:

| number |  binary   | hex  |
|--------|-----------|------|
|  255   | 1111 1111 | 0xff |
|  216   | 1101 1000 | 0xd8 |
|  255   | 1111 1111 | 0xff |

So the first three bytes of a JPEG file are `0xff` `0xd8` `0xff`.

Bitmap files, with the extension BMP, maps bits directly to pixels. Their headers are more complicated:

![bitmap header](https://github.com/belcurv/see-ess-fitty/blob/master/week3/bitmap_header.png)

Note that after the header is a repeating sequence of `RGBTRIPLE`s comprised of three bytes that each represent the colors red, green, and blue.

### `struct`

A keyword, `struct` lets us create more complicated data types by grouping any number of other data types together. For example, we might represent a `student` by two pieces of information: `string name` and `string dorm`:

```C
typedef struct
{
    string name;
    string dorm;
}
student;
```
