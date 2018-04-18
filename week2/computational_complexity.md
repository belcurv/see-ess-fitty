# Computational Complexity

To make the most effective use of our resources (CPU, RAM, money, etc), we need to analyze the complexity of algorithms. This enables us to estimate how well an algorithm will scale given larger and larger data sets.

Generally when we talk about the complexity of an algorithm, we care about the **worst-case** scenario. This is referred to as "big O".  We sometimes also care about the **best-case** scenario (referred to as Ω).

**What is a dataset?** -- depends on context. For an algorithm that processes strings, the dataset could be the length of a string. For an algorithm that processes files, we could be talking about how many kB file size. For arrays, it could be number of elements.

We can measure the time or resource complexity of an algorithm based on how it handles the input dataset. We call this measure _f(n)_. We don't actually care about what _f(n)_ is precisely; rather, we care about its **tendency** as the dataset gets bigger, which is dictated by its highest-order term (terms with lower exponents start to become irrelevant).

Comparing the following

```
f(n) = (n ^ 3)
f(n) = (n ^ 3) + (n ^ 2)
f(n) = (n ^ 3) - (8 * n ^ 2) + 20n
```

As `n` gets very large (say, 1 million) each algorithm takes approx 1.0 x 10 ^ 18 "resources". So we can say all three are on the order of `n ^ 3`, or, `O(n^3)`. 

### Big O

From fastest (top) to slowest (bottom):

|     O      | Description   |
| -----------| ------------- |
| O(1)       | constant time  |
| O(log n)   | logarithmic time (ex. binary search) |
| O(n)       | linear time  |
| O(n log n) | linearithmic time  |
| O(n^2)     | quadratic time  |
| O(n^c)     | polynomial time  |
| O(c^n)     | exponential time |
| O(n!)      | factorial time |
| O(∞)       | infinite Cell (ex: "stupid sort") |

#### O(1) -- Constant time

Always takes a fixed number of operations in the worst case.

```C
int four_for_you(int array[1000])
{
  return 4;
}
```

```C
int add_two_nums(int a, int b)
{
  return a + b;
}
```

#### O(n) -- Linear Time

Always takes `n` operations in the worst case. `n` grows linearly with input.

Imagine trying to randomly find some value (`5`) in the following array:

```
[1, 2, 3, 4, 5]
```

It could take up to 5 steps. For a similar 7-element array, it could take up to 7 steps. There might not even be a `5` in the array; worst-case, we still have to look at all `n` elements.

### Examples

What's the runtime complexity of the following snippets?

```C
for (int j = 0; j < m; j++)
{
  // loop body runs in O(1)
}
```

_Answer: O(m) -- it's linear. Worst-case, we iterate over every `j < m`._

How about a loop inside of a loop:

```C
for (int j = 0; j < p; j++)
{
  for (int k = 0; k < p; k++)
  {
    // loop body runs in O(1)
  }
}
```

_Answer: O(p^2) -- quadratic time._
