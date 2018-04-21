# Call Stacks

When you call a function, the system sets asid a space in memory for that function to do its necessary work. We call suck chunks of memory **stack frames** or **function frames**.

More than one function's stack fram may exist in memory at a given time. If `main()` calls `move()` which then calls `direction()`, all three functions have open frames.

These frames are arranged in a **stack**. The frame for the most-recently called function is always at the top of the stack. When a new function is called, a new frame is **pushed** onto the top of the stack and becomes the active frame. When a function completes, its frame is **popped** off of the stack, and the frame immediately below it becomes the new active function on the top of the stack. This function picks up immediately where it left off.

So ...

```
Step 1:         Step 2:         Step 3:           Step 4:
push on main    push on move    push direction    pop off direction
                                                  move is now active
---------------------------------------------------------------------
>                               > direction()
>               > move()        > move()          > move()
> main()        > main()        > main()          > main()
```

### Call Stacks and Recursion

Consider the factorial function:

```C
int fact(int n)
{
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int main(void)
{
  printf("%i \n", fact(3));
}
```

Call stack over time:

```
Step 1:   Step 2:    Step 3:    Step 4:   Step 5:    Step 6:    Step 7:    Step 8:    Step 9:
---------------------------------------------------------------------------------------------

                                          fact(1)
                                fact(2)   fact(2)    fact(2)
                     fact(3)    fact(3)   fact(3)    fact(3)    fact(3)
          printf()   printf()   printf()  printf()   printf()   printf()   printf()
main()    main()     main()     main()    main()     main()     main()     main()     main()
```

