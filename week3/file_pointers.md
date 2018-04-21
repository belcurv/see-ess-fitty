# File Pointers

C gives us file pointers, `FILE*`. File pointers and pointers, while interrelated, are not exactly the same thing.

The file manipulation functions all live in `stdio.h`. All of them accept `FILE*` as one of their paramters, except for the function `fopen()`, which is used to _get_ a file pointer in the first place.

Some of the most common file input/output functions are:

1. `fopen()` - opens a file and returns a file pointer to it. **Always** check the return value to make sure you don't get back `NULL`. Takes 2 arguments: file name (string) and operation (string).

    ```C
    // Syntax:
    //   FILE* ptr = fopen(<filename>, <operation>);
    
    FILE* ptr1 = fopen("file1.txt", "r");  // <-- "r" = "read"
    FILE* ptr2 = fopen("file2.txt", "w");  // <-- "r" = "write", overwrites existing files
    FILE* ptr3 = fopen("file2.txt", "a");  // <-- "r" = "append", adds to the end of existing file
    ```

2. `fclose()` - accepts 1 argument, a file pointer, and closes the file

    ```C
    // Syntax:
    //   fclose(<file pointer>);
    
    fclose(ptr1);
    ```

3. `fgetc()` - Reads and return the next character from the file pointed to. Note: the file pointer passed in as a parameter must have been opened for reading (`"r"`), or you will suffer an error.

    ```C
    // Syntax:
    //   char c = fgetc(<file pointer>);
    
    FILE* ptr1 = fopen("file1.txt", "r");  // <-- "read"
    char ch = fgetc(ptr1);
    ```

4. `fputc()` - Writes or appends the specified character to the pointed-to file. Note: the file pointer passed in as a parameter must have been opened for writing (`"w"`) or appending (`"a"`), or you will suffer an error.

    ```C
    // Syntax:
    //   fputc(<character>, <file pointer>);
    
    FILE* ptr2 = fopen("file2.txt", "w");  // <-- "write"
    fputc('Z', ptr2);
    ```

5. `fread()` - a more generic version of `fgetc()` that allows us to get any amount of information instead of just 1 character at a time. Reads <qty> units of <size> from the file pointed to and stores them in memory as a buffer (usually an array) pointed to by <buffer>. Note: the file pointer passed in as a parameter must have been opened for reading (`"r"`), or you will suffer an error.

    ```C
    // Syntax:
    //   fread(<buffer>, <size>, <qty>, <file pointer>)

    int arr[10];  // <-- statically allocate memory on the stack
    FILE* ptr1 = fopen("file1.txt", "r");
    fread(arr, sizeof(int), 10, ptr1);
    
    // * `arr` = <buffer> = pointer to the location we're going to store in
    // * `sizeof(int)` = <size> = how large each unit of info will be
    // * `10` = <qty> = how many of those units we want to acquire
    // * `ptr1` = <file pointer> = pointer to the file we're getting above units from
    ```
    
    Another ex
    
    ```C
    FILE* ptr2 = fopen("file2.txt", "r");
    double* arr2 = malloc(sizeof(double) * 80); // <-- dynamically allocate memory on the heap
    fread(arr2, sizeof(double), 80, ptr2);
    ```

    Can also treat `fread()` like `fgetc()`. But, unlike the above examples where our <buffer> was an array (the name of an array **is already a pointer**), when using variables for single chars we have to pass in `&c`, the address where we want to store this 1 byte of information:
    
    ```C
    char c;
    fread(&c, sizeof(char), 1, ptr);  // <-- pointer to address of `c`
    ```

6. `fwrite()` - Writes <qty> units of <size> to the file pointed to by reading them from a buffer (usually an array) pointed to by <buffer>. Note: the file pointer passed in as a parameter must have been opened for writing (`"w"`) or appending (`"a"`), or you will suffer an error.

    ```C
    // Syntax:
    //   fwrite(<buffer>, <size>, <qty>, <file pointer>)

    int arr[10];
    FILE* ptr3 = fopen("file3.txt", "w");
    fwrite(arr, sizeof(int), 10, ptr3);
    ```
    
    Another ex using the heap
    
    ```C
    FILE* ptr2 = fopen("file2.txt", "a");
    double* arr3 = malloc(sizeof(double) * 80); // <-- dynamically allocated
    fwrite(arr3, sizeof(double), 80, ptr2);
    ```

### Duplicating some linux commands!

The ability to get single characters from files, if wrapped in a loop, means we could read all the characters from a file and print them to the screen, one-by-one, essentially. This is basically what the linux command "cat" does:

```C
char ch;
while((ch = fgetc(prt)) != EOF)
{
  printf("%c", ch);
}
```

We can read and write characters to/from files. Extending the example above, instead of printing characters to the screen we can write them, one-by-one, to a second file. This is similar to how the linux command "cp" works:

```C
char ch;
while((ch = fgetc(prt1)) != EOF)  // get from pointer 1
{
  fputc(ch, ptr2);                // put to pointer 2
}
```

### OTher Useful `stdio.h` file functions

`fgets()` - Reads a full string from a file.

`fputs()` - Writes a full string to a file.

`fprintf()` - Writes a formatted string to a file instead of the screen.

`fseek()` - Allows you to rewind or fast-forward within a file.

`ftell()` - Tells you at what (byte) position you are at within a file.

`feof()` - Tells you whether you've read to the end of a file.

`ferror()` - Indicates whether an error has occirred in working with a file.
