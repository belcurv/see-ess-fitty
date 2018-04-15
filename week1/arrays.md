# Arrays

Arrays hold values **of the same time**, at contiguous memory locations. Each location is an identically-sized block of space ("element").

Access elements by index number, just like JS, indexed starting form zero.

C is very lenient. It will not prevent you from going "out of bounds" of your array. So, for an array `myArr` of length 50, if you try to access `myArr[100]` your probram will compile, but you'll get either garbage value back or a segmentation fault at runtime.

**Declaration**

Three parts:

```
type name[size];
```

1.  `type` is what kind of variable each element of the array will be
2.  `name` is what you want to call your array
3.  `size` is how many elements you want your array to contain

Ex.

```
double menu_prices[8];
```

**Assignment**

Works as expected, using index location:

```C
bool truthtable[10];
truthtable[2] = false;
```

**Access**

Works as expected, using index location:

```C
bool truthtable[10];
if (truthtable[7] == true)
{
  printf("TRUE\n");
}
```

**Initialization = Declaration + Assignment in 1 step**

Special syntax when _initializing_ arrays with starting values. This is most practical for smaller arrays.

```C
// instantiation syntax
bool truthtable[3] = { false, true, true };

// same as individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

When using this instantiation syntax, you don't actualy need to declare the size of the array beforehand. The C compiler will calculate the size based on the number of elements within the curly brackets. So we can do:

```C
bool truthtable[] = { false, true, true };
```

**Multiple Dimensional Arrays**

Arrays can consist of more than a single dimension by adding more size specifiers:

```C
bool battleship[10][10]  // 10 x 10 "board"
```

In memory, this is really just a 100-element one-dimensional array.

**Copying Arrays**

While we can treat individual elements of arrays as variables, we cannot treat entire arrays themselves as variables. We cannot, for example, assign one array to another using the assignment operator. That is not legal C. Instead, we must use a loop to copy over the elements one at a time.

So this does not work:

```C
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];
bar = foo;
```

Instead, you have to do this:

```C
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

for (int i = 0; i < 5; i++)
{
  bar[i] = foo[i];
}
```

**Pass by Reference**

Primitive variables in C are passed by value (they are copied). Arrays are passed by reference. The callee receives **the actual array**, not a copy of it. If the callee then manipulates the array, the original is modified and that can affect other pieces of code that use that array.

```C
void set_array(int array[4]);
void set_in(int x);

int main(void)
{
  int a = 10;
  int b[4] = { 0, 1, 2, 3 };
  set_int(a);
  set_array(b);
  printf("%d %d \n", a, b[0]);  // == prints 10, 22 ==
}

void set_array(int array[4])  // array - passed by reference
{
  array[0] = 22;
}

void set_in(int x)  // int - passed by value
{
  x = 22;
}
```
