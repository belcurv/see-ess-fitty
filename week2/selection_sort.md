# Selection Sort

Basic idea: find the smallest unsorted element and add it to the end of the sorted list. Builds a sorted list from left to right (aka top to bottom).

Pseudocode:

* Repeat until no unsorted elements remain:
  * Search the unsorted part of the data to find the smallest value
  * Swap the smallest found value with the first element of the unsorted part

What's the worst-case scenario? We have to iterate over each of the `n` elements of the array to find the smallest unsorted element, and we must repeat this process `n` times, since only 1 element gets sorted on each pass.

And best-case scenario? The same as worst-case! No way to guarantee the array is sorted until we go through this process for all elements.

Computational complexity = O(n^2)
