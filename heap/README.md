# Heaps

## Use cases
* Priority Queues
* Block memory management

## Properties
* Maintains a "weak order" unlike a binary search tree which is strongly ordered
* Generally is used as a "min heap" or "max heap"

## Abstract Data Types used for implementation
* Using a dynamic array is the simplest implementation
* A linked tree can be used, but insertion becomes > O(log n) if you don't maintain state

## Main algorithms using heaps
* Heapify
* Heap sort

## Heapify
This algorithm's responsibility is to ensure that the heap property is met upon insertion or deletion of an element from the heap. It ensures that the "weak order" is maintained

# Heap Sort
This is a simple to implement and rather quick sorting algorithm. If it takes O(n) to build the heap it takes another O(nlogn) to sort

