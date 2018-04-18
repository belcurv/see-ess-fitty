# Insertion Sort

Build sorted array in place, shifting elements out of the way if necessary as you go to make room.

In pseudocode:

* Call the 1st element of the array "sorted"
* Repeat until all elements are sorted:
  * Look at the next unsorted element. Insert into the "sorted" portion by shifting the requisite number of elements.

Note that you only traverse the array one time.

Worst case scenario: the array is in reverse order; we have to shift each of the `n` elements `n` positions each time we make an insertion. Computational complexity = `n` elements * `n` positions = O(n^2)

Best-case scenario: the array is already perfectly sorted, and we simple keep moving the line between "unsorted" and "sorted" as we examine each element.  `n` positions = Ω(n)
