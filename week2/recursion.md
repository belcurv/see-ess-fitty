# Recursion

https://www.youtube.com/watch?v=mz6tAJMVmfM

A recursive function calls itself as a part of its execution.

Example:

* The factorial function (_n!_) is defined over all positive integers
* _n!_ equals all of the positive integers less than or equal to _n_, multiplied together
* Thinking in therms of programming, we'll define the mathematical function _n!_ as `fact(n)`

```
5! = 5 * 4 * 3 * 2 * 1

fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2 * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1

// or //

fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)

// generalized: factorial of any number `n`:

fact(n) = n * fact(n - 1)
```

#### Two parts to a recursive function

1.  **base case** - when triggered, will terminate the recursive process. In the above, base case = `fact(1) = 1`
2.  **recursive case** - where the recursion will actually occur. Calls itself with a slight variation, making the problem slightly smaller.

#### In code

```C
int fact(int n)
{
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return n * fact(n - 1);   // fact(n) = n * fact(n - 1)
  }
}
```

In C, given single-line conditionals, you can omit the curly braces. This has the same functionality as above:

```C
int fact(int n)
{
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);   // fact(n) = n * fact(n - 1)
}
```

This also works: ternary expressions

```C
int fact_ternary(int n)
{
  return (n == 1) ? 1 : n * fact_ternary(n - 1);
}
```

#### Loops, wherefore art thou

In general, but not always, a recusive function can replace a loop in a non-recursive function. The iterative version of the above:

```C
int fact2(int n)
{
  int product = 1;
  while (n > 0)
  {
    product *= n;
    n--;
  }
  return product;
}
```

### COllatz Conjecture

Applies to positive integers and speculates that it is always possible to get back to 1 if you follow these steps:

1.  If _n_ is 1, stop.
2.  Otherwise, if _n_ is even, repeat this process on _n/2_
3.  Otherwise, if _n_ is odd, repeat this process on _3n + 1_

Challenge:

Write a recusive function `collatz(n)` that calculates how many steps it takes to get to 1 if you start from -n- and recurse as indicated above.

```
int collatz(int n)
{
  if (n == 1)
    return 0;
  else if (n % 2 == 0)
    return 1 + collatz(n / 2);
  else
    return 1 + collatz(3 * n + 1);
}
```
