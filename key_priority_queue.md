# Priority Queue Recognition - The One Rule

## Ask This Question

> Do I need to repeatedly find, remove, or maintain the current best element while the data is changing?

If YES, think:

```cpp
priority_queue
```

The "best" element could mean:

* Maximum
* Minimum
* Top K
* Highest priority
* Lowest cost
* Earliest finish time
* Closest point
* Largest profit

---

## Recognition Keywords

If the problem contains any of these phrases:

```text
largest K
smallest K
top K
kth largest
kth smallest
highest priority
minimum cost
maximum profit
closest
most frequent
merge k sorted
stream of data
running median
```

Your first thought should be:

```cpp
priority_queue
```

---

## The Mental Model

Heap is NOT for sorting everything.

Heap is for:

> "I only care about the current best candidate."

Example:

Instead of:

```text
Sort all students
Take topper
```

Think:

```text
Keep topper on top at all times
```

This is exactly what a heap does.

---

## The Four Most Common Heap Patterns

### 1. Top K Problems

Examples:

```text
K Largest Elements
Top K Frequent Elements
K Closest Points
Kth Largest Element
```

Recognition:

```text
Need only K best elements,
not the entire sorted order.
```

---

### 2. Merge K Sorted Sources

Examples:

```text
Merge K Sorted Lists
Twitter News Feed
Smallest Range from K Lists
```

Recognition:

```text
Multiple sorted sources
Need global best element.
```

---

### 3. Dynamic Best Choice

Examples:

```text
IPO
Maximum Performance of Team
Task Scheduling
```

Recognition:

```text
At every step,
pick the best available option.
```

---

### 4. Streaming Problems

Examples:

```text
Find Median from Data Stream
Kth Largest in Stream
```

Recognition:

```text
Data arrives continuously.
Need answer after each insertion.
```

---

## When NOT to Use Heap

If the question asks:

```text
Nearest Greater
Nearest Smaller
Previous Greater
Next Greater
```

Think:

```cpp
stack
```

not heap.

---

If the question asks:

```text
Contiguous subarray
Contiguous substring
Window
```

Think:

```cpp
sliding window
```

not heap.

---

If the question asks:

```text
Search in answer space
Minimum X satisfying condition
Maximum X satisfying condition
```

Think:

```cpp
binary search
```

not heap.

---

## Final Interview Shortcut

Whenever you hear:

> "Repeatedly give me the current best element."

Think:

```cpp
priority_queue
```

before considering any other data structure.
