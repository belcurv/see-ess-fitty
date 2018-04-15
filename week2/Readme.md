# Week 2 Lecture notes

https://docs.cs50.net/2017/fall/notes/3/lecture3.html

### Searching

Given some array of numbers, if we want to find a particular number we need an algorithm to search for it.

**Linear Search**

If the numbers are not sorted, there is no efficient to find any specific number. If we try each element, in order, until we find our number or exhaust the search space, the algorithm is called **linear search**. In the worst case, this would take n steps, where n was the number of numbers in our array, and in the best case, we would find it in the first step.

**Binary Search**

Alternately, if they **were** sorted smallest to largest, we could start at the middle: look at the value in the middle of the array, and then move to either the left or right half depending on whether the value we wanted to find is smaller or larger. This is **binary search** algorithm. This is much faster than linear search because we divide the search space in half each iteration.

### Sorting

A prerequisite requirement to being able to run binary search is having an array of sorted numbers.

**Insertion Sort**

Start a new collection.
Pick a pair of elements in the original collection, compare them and put them in order in the new collection.
Then continue by picking one element from the original collection and _inserting_ it where it belongs in the new collection.

Pseudocode:

```
for i from 1 to n-1
    call 0'th through i-1'th elements the "sorted side"
    remove i'th element
    insert it into sorted side in order
```

**Bubble Sort**

Has the effect of moving the largest values to the end of the collection. For each iteration, compare an adjacent pair of values & swap them if the are in the wrong order. After 1 pass, the largest value will be at the end. Repeat until the collection is completely sorted.

Pseudocode:

```
repeat until no swaps
    for i from 0 to n-2
        if i'th and i+1'th elements out of order
            swap them
```

**Selection Sort**

Has the effect of moving the smallest values to the start of the collection. For each iteration, look for the smallest number. Then move that number to the front of the collection, swapping it with whatever was originally at that position.

Pseudocode:

```
for i from 0 to n-1
    find smallest element between i'th and n-1'th
    swap smallest with i'th element
```

### Running Time

We're concerned with the _worst case_ number of steps required to solve some problem.

For bubble sort, if we have a collection with `n` elements, we would compare `(n - 1)` pairs in our first pass. After our first pass, the largest element will have been swapped all the way to the right. So in our second pass, we’ll only need `(n - 2)` comparisons. In total, we will make `(n - 1) + (n - 2) + ... + 1` comparisons. Or `n(n - 1)/2`. Which multiplies out to `(n^2 - n)/2`.

We generally just want the term with the biggest order of magnitude, since that’s the only one that really matters when `n` gets really big. And we can even get rid of the factor of 1/2. For example, given 1,000,000 numbers to sort, bubble sort will take

>`(n ^ 2 / 2) - (n / 2)` steps
>
>= `(1,000,000 ^ 2 / 2) - (1,000,000 / 2)` steps
>
>= `(500,000,000,000) - (500,000)` steps
>
>= `499,999,500,000` steps

Because `499,999,500,000` is so close to the 1st term (`500,000,000,000`) we can safely ignore the 2nd term. So for an expression like `(n2 - n)/2`, we can say it is **big O** notation of `O(n2)`.

Depending on the algorithm, we might see:

* `O(n^2)`
* `O(n log n)`
* `O(n)`
* `O(log n)`
* `O(1)` -- This last one takes one step, or ten steps, or a constant number of steps regardless of the size of the problem.

So, about those searching algorithms ...

1. **linear search** - given an unsorted list, running time = `O(n)`, since worst-case we might have to look at all `n` elements before we find the correct one.

2.  **binary search** - has logarithmic running time, `O(log n)`, since we are dividing the problem in half each time.

**Ω - Omega** 

The opposite of big O. If gig O is the running time of the worst-case scenario, big Omega is the lower bound, or the best case scenario.

Algorithms like _linear search_ or _binary search_ tend to have `Ω(1)`, since in the best case we get lucky and find our element on the first try.

_Bubble sort_ has `Ω(n)`, since we need to at least look at all `n` elements and can stop if we made no swaps.

_Selection sort_ has `Ω(n^2)`. Even if the list was already sorted, we wouldn’t know because we look for the smallest element in the rest of the list, one at a time, so we end up looking at about `n^2` elements.

**Θ - Theta**

Means the running time of an algorithm is the same in the worst-case (Ω) and the best-case (O).
