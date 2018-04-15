# Merge Sort

Cool visualization: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

Before we implement merge sort, see example of iteratively summing integers in `sigma0.c`. The program adds up all the numbers from 1 to the number provided as input, using a function `sigma`, that in turn uses a for loop to make a sum.

Contrast with `sigma1.c` which uses recursion to achieve the same.

```C
int sigma(int m)
{
    if (m <= 0)    // base case or exit plan. Return 0 and exit
    {
        return 0;
    }
    else
    {
        return (m + sigma_recr(m - 1));
        
        // In effect, the above says
        //   "return `m` + the sum of everything below it."
        // For ex when `m` = 3:
        //    = return 3 + (sigma(2) which ...)
        //    = return 2 + (sigma(1) which ...)
        //    = return 1 + (sigma(0) which ...)
        //    = return 0
        //    ... then "unwind" all the returns ...
        //    = return 3 + 2 + 1 + 0  // = 6
    }
}
```

Function `sigma` calls itself, but changes the argument to `m - 1`, since the sum of the numbers from `1` through `m` is the sum of the numbers from `1` through `m - 1`, plus `m`. Essentially, we can use the same algorithm to solve the rest of the problem, after we solved some part of it. Eventually, these partial solutions will add up to solve the problem completely.

We also have a condition for a _base case_, where the function no longer calls itself, and instead returns a value in the most basic case, which is where `m` is `0` or smaller. That will end the recursion.

### Merge Sort Pseudocode

```
on input of n elements
  if n < 2
    return
  else
    sort left half of elements
    sort right half of elements
    merge sorted halves
```

* The base case (where `n < 2`) means that there’s nothing for us to do, since by definition if there are less than 2 elements, "they" (aka, 1 element) will already be sorted.
* Otherwise, we sort both halves by recursively using merge sort on those halves, and then we merge them together by taking the smallest one from each of the lists, one at a time.

Need enough memory to manage 2 lists: the original and the result.

Dividing the problem in half each time, we reduce the problem to something logarithmic with `log n` layers. And at each layer, we looked at all `n` elements to merge them. So intuitively, we can estimate that this algorithm takes `O(n log n)` time.

We can even look at the pseudocode to analyze running time:

```
on input of n elements
  if n < 2
    // 1st condition
    // O(1) steps to return, a constant number. time to solve a problem of size n, is O(1)
    return
  else
    // 2nd condition
    // sorting each half requires the running time of each half, plus the time it takes to merge the two halves.
    // Mathematically, this series actually sums up to be O(n log n)
    sort left half of elements   // T(n/2)
    sort right half of elements  // T(n/2)
    merge sorted halves          // O(n)
```
