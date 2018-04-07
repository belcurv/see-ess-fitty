Unlike in PHP and JS, where we don't need to specify datatypes of variables to use them. In C, we have to sepc datatype of every variable we create.

#### `int`

* stores integers
* 32 bits (4 bytes) of addressing (memory space)
* range of values limited to what can fit in 32 bits of information - split into negative and positive values:

  -2^31 .... 0 .... 2^31-1

* 'unsigned integers' - doubles the positive range an int can take on, but can not take negatives. Basically uses all 32 bits for numeric info

#### `char`

* stores single string characters
* 8 bits (1 byte) of memory space
* values range from -128 ... 0 ... 127
* ASCII maps letter symbols to numeric values in the positive side of this range (A = 65, a = 97, 0 = 48)

#### `float`

* aka "real" numbers
* have a decimal
* 32 bits / 4 bytes of memory
* given 32 bits, some of which is used for the integer part of the number, the precision of the decimal part is limited to how many bits are left

#### `double`

* also used to store floating point aka real numbers.
* doubles are _double precision_ - they always take up 8 bytes (64 bits) of memory
* with additional 32 biots of precision, doubles all much more precise real numbers

#### `void`

* `void` is a type, but not a _data type_
* functions can have a `void` return type, meaning they do not return a value
* the parameter list of a function can also be `void`, meaning it takes no parameters
* this of `void` as a placeholder for "nothing".
* examples: `printf` (returns nothing), `main` (takes no params)

#### `bool`

* not a standard data type in C!
* provided by the `cs50.h` library
* used for variables that will store a Boolean value (either true or false)

#### `string`

* also not a standard data type in C?!
* provided by the `cs50.h` library
* collections of characters. Words, senences, paragraphs.

#### `structs`

* Allow you to combine two types into one unit - int and string.

#### `typedefs`

* Allow you to create your own data types

# Working with variables

Two things required: type and name. Two examples:

```C
int number;
char letter;
```

Can create multiple variables of the same time on single line:

```C
int height, width;
float sqrt2, sqrt3, pi;
```

After a variable is declared, don't need to specify its type again when using it.

Declaration, assignment and initialization - three related things:

```C
int number;         // declaration - needs data type
number = 17;        // assignment - omit data type
char letter = 'H';  // initialization - declaration and assignment in 1 step
```
