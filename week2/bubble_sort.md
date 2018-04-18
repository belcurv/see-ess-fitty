# Bubble Sort

Basic idea: move higher valued elements to the right, and lower valued elements to the left. Effectively builds sorted array from right (largest) to left (smallest).

In pseudocode:

* Set a swap counter to a non-zero value
* Repeat until the swap counter is 0:
  * Reset swap counter to 0
  * Look at each adjacent pair
    * If two adjacent elements are not in order, swap them and add 1 to the swap counter
    
Basically, once swap counter stays 0, it means every element was in order.

Worst-case scenario: the array is in completely reverse order, and we have to bubble each each of the `n` elements all the way across the array. And since we can only bully bubble 1 element into position per pass, we must do this `n` times. Computational complexity: O(n^2).

Best-case scenario: the array is already perfectly sorted, and we make no swaps on 1st pass. Ω(n) -- only have to look at each elements once.
