# Algorithms Summary

#### Sorting

| Algorithm      | Concept | O | Ω |
| ---------------| --------|---|---|
| Selection Sort | Find the **smallest** unsorted element in an array and swap it with the **first** unsorted element of that array | O(n^2) | Ω(n^2) |
| Bubble Sort    | **Swap adjacent pairs** of elements if they are out of order, effectively "bubbling" larger elements to the right and smaller ones to the left | O(n^2) | Ω(n) |
| Insertion Sort | Proceed once through array, left-to-right, **shifting** elements as necessary to insert each element into its correct place | O(n^2) | Ω(n) |
| Merge Sort     | **Split** the full array into subarrays, the **merge** those subarrays back together in the correct order | O(n log n) | Ω(n log n) |

#### Searching

| Algorithm      | Concept | O | Ω |
| ---------------| --------|---|---|
| Linear Search  | **Iterate** across the array once, left to right, trying to find the target element | O(n) | Ω(1) |
| Binary Search  | Given a _sorted array_, **divide and conquer** by systematically eliminating half of the remaining elements in the search for the target element | O(log n) | Ω(1) |

