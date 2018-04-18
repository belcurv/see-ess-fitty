# Binary Search

https://www.youtube.com/watch?v=T98PIp4omUA

The idea of binary search algorithm: divide the search area in half each time, trying to find the target number. However, this algorithm requires a sorted array to work.

In pseudocode:

* Repeat until the (sub) array is of size 0:
  * Calculate the mid-point of the current (sub) array
  * If the target is at the middle, you found it -- stop
  * Otherwise, if the target is less than what's at the middle, repeat, changing the end point to tbe just to the left of the middle.
  * Otherwise, if the target is greater than what's at the middle, repeat, changing the start point to be just to the right of the middle.

Does this search algo work if the target is not in the array? Yes. Eventually you'll get to a point where the start and end indixes cross and you have a subarray of size zero. That guarantees that the target is not in the array.

Need to keep track of `target`, `start_index`, `end_index`, and `middle_index` variables.

Worst-case scenario: We have to divide the list of `n` elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division or it doesn't exist in the array at all. Complexity = O(log n)

Best-case scenario: The target element is at the midpoint of the full array, so we can stop looking immediately after we start. Ω(1) (constant time).
