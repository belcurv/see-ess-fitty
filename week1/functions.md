# Functions

Functions, procedures, subroutines and methods all refer to the same thing.

Why use functions?

1.  Organization

2.  Simplification

3.  Reuse

### Syntax

**Declaration** - step 1 is to give the compiler a heads-up that a user-written functions appears in the code. Declartions should appear at very top of code.

Three parts to fucntions declaration:

1.  return type

2.  name

3.  argument list - needs type and name

```C
return-type name(argument-list);
```

Example

```C
float mult_two_floats(float a, float b);
```

**Definition** - the actual implementation of the function.

```C
float mult_two_floats(float a, float b)
{
  return a * b;
}
```

**Calling Functions** - to call a function, pass it appropriate arguments and assign its return value to something of the correct type.

**Misc**

If a function takes no inputs, declare it with `void`. If a function does not return anything, it's return type must also be `void`.

**Practice Problem** - `valid_triangle`

```C
// declaration
bool valid_triangle(double a, double b, double c);

// definition
bool valid_triangle(double a, double b, double c)
{
  if (a <= 0 || b <= 0 || c <= 0)
  {
    return false;
  }
  
  if (a >= (b + c) || b >= (a + c) || c >= (a + b))
  {
    return false;
  }
  
  return true;
}
```
