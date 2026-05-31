# Stack & Queue Pattern Recognition Cheat Sheet

---

# STACK

## Core Idea

Stack is used when you need:

```text
Last In First Out (LIFO)
```

or

```text
Need information about previous elements
```

or

```text
Need to remove useless elements dynamically
```

---

# Recognition Patterns for STACK

If you see words like:

```text
Nearest
Previous
Next
Greater
Smaller
Closest
Span
Valid Parenthesis
Monotonic
Expression Evaluation
Undo
Backtracking
```

Think:

```text
STACK
```

---

# Pattern 1: Next Greater / Smaller Element

Keywords:

```text
Next Greater Element
Previous Greater Element
Next Smaller Element
Previous Smaller Element
Nearest Greater
Nearest Smaller
```

Examples:

```cpp
739. Daily Temperatures
496. Next Greater Element I
503. Next Greater Element II
84. Largest Rectangle Histogram
```

---

## Observation

Whenever current element can invalidate previous elements:

```cpp
while(!st.empty() && st.top() < arr[i])
```

we pop.

---

## Template

```cpp
for(int i=0;i<n;i++){

    while(!st.empty() && st.top() < arr[i]){
        st.pop();
    }

    answer...

    st.push(arr[i]);
}
```

---

# Pattern 2: Monotonic Stack

Maintain stack in sorted order.

Types:

```text
Increasing Stack
Decreasing Stack
```

---

## Increasing Stack

```cpp
while(!st.empty() && st.top() > curr)
    st.pop();
```

Stack:

```text
1 2 4 7
```

---

## Decreasing Stack

```cpp
while(!st.empty() && st.top() < curr)
    st.pop();
```

Stack:

```text
9 8 5 3
```

---

## Recognition

Question asks:

```text
Nearest Greater
Nearest Smaller
Previous Greater
Previous Smaller
```

Usually:

```text
Monotonic Stack
```

---

# Pattern 3: Stock Span

Keywords:

```text
Consecutive previous elements
span
continuous range
```

Example:

```cpp
901. Online Stock Span
```

---

## Trick

Store:

```cpp
{price,index}
```

Pop all smaller prices.

Answer:

```cpp
currIndex - previousGreaterIndex
```

---

# Pattern 4: Largest Rectangle Histogram

Keywords:

```text
Maximum rectangle
Histogram
Area
Width determined by boundaries
```

Think:

```text
Previous Smaller
Next Smaller
```

using stack.

---

## Formula

```cpp
width = rightSmaller - leftSmaller - 1

area = height * width
```

---

# Pattern 5: Parentheses Problems

Keywords:

```text
Valid Parentheses
Balanced
Bracket Matching
Remove Invalid Parentheses
```

Think:

```text
STACK
```

---

## Typical

```cpp
(
[
{
```

Push opening.

For closing:

```cpp
check top
pop
```

---

# Pattern 6: Expression Conversion

Keywords:

```text
Infix
Postfix
Prefix
Expression Evaluation
```

Think:

```text
Operator Stack
```

---

Examples:

```cpp
Infix -> Postfix
Postfix Evaluation
Prefix Evaluation
```

---

# Pattern 7: Remove K Digits

Keywords:

```text
Lexicographically Smallest
Remove K
Make Number Minimum
```

Think:

```text
Monotonic Increasing Stack
```

Example:

```cpp
402. Remove K Digits
```

---

# Pattern 8: String Elimination

Keywords:

```text
Adjacent Duplicate
Remove Duplicates
Cancel Neighbors
```

Examples:

```cpp
1047 Remove Adjacent Duplicates
```

---

Idea:

```cpp
if(top == curr)
    pop
else
    push
```

---

# Pattern 9: Recursive Simulation

Sometimes recursion behaves like stack.

Keywords:

```text
Undo
Backtracking
DFS
Expression Parsing
```

---

# Stack Questions Checklist

Ask:

```text
1. Need nearest greater/smaller?
2. Need previous information?
3. Need monotonic ordering?
4. Need bracket matching?
5. Need span/range?
6. Need element removal dynamically?
```

If yes:

```text
STACK
```

---

---

# QUEUE

## Core Idea

Queue is:

```text
First In First Out (FIFO)
```

Used when processing things in arrival order.

---

# Recognition Patterns for QUEUE

Keywords:

```text
Level
Breadth First
Minimum Steps
Shortest Path
Simulation
Order Processing
Streaming
Window
```

Think:

```text
QUEUE
```

---

# Pattern 1: BFS

Most important Queue pattern.

Keywords:

```text
Minimum steps
Shortest path
Unweighted graph
Moves
Transformations
Grid traversal
```

Examples:

```cpp
Jump Game IV
Word Ladder
Rotting Oranges
01 Matrix
Binary Tree Level Order
```

---

## Template

```cpp
queue<int> q;

q.push(start);

while(!q.empty()){

    auto node = q.front();
    q.pop();

    for(neighbor){

        if(not visited){

            visited=true;

            q.push(neighbor);
        }
    }
}
```

---

# Pattern 2: Level Order Traversal

Keywords:

```text
Level by level
Depth
Distance
Tree levels
```

Think:

```text
QUEUE
```

---

Template:

```cpp
int sz=q.size();

for(int i=0;i<sz;i++){
}
```

One loop = one level.

---

# Pattern 3: Multi Source BFS

Keywords:

```text
All sources simultaneously
Nearest distance
Rot spread
Fire spread
Infection
```

Examples:

```cpp
Rotting Oranges
Walls and Gates
01 Matrix
```

---

## Trick

Push all starting points first.

```cpp
for(all sources)
    q.push(source);
```

---

# Pattern 4: Sliding Window Maximum

Keywords:

```text
Maximum in window
Minimum in window
Window queries
```

Think:

```text
Deque
```

not normal queue.

Example:

```cpp
239 Sliding Window Maximum
```

---

# Pattern 5: First Negative in Window

Keywords:

```text
Window
Need first occurrence
Need order
```

Think:

```text
Queue
```

Store candidates.

---

# Pattern 6: Stream Problems

Keywords:

```text
Incoming data
Online queries
Stream
Real-time
```

Examples:

```cpp
First Non-Repeating Character
Moving Average
Recent Counter
```

---

# Pattern 7: Topological Sort

Keywords:

```text
Dependencies
Courses
Build Order
DAG
```

Think:

```text
Indegree + Queue
```

Example:

```cpp
Course Schedule
```

---

# Queue Questions Checklist

Ask:

```text
1. Minimum steps?
2. Shortest path in unweighted graph?
3. BFS?
4. Level order traversal?
5. Simulation of events?
6. Stream processing?
7. Dependency ordering?
```

If yes:

```text
QUEUE
```

---

# Deque Recognition

Use Deque when:

```text
Need insertion/removal from both ends
Need window maximum/minimum
Need monotonic queue
```

Examples:

```cpp
Sliding Window Maximum
Shortest Subarray with Sum >= K
```

---

# Fast Recognition Summary

STACK:

```text
Nearest Greater/Smaller
Previous/Next
Span
Histogram
Parentheses
Expression Parsing
Duplicate Removal
Monotonic Problems
```

QUEUE:

```text
BFS
Minimum Steps
Shortest Path
Level Order
Simulation
Streaming
Topological Sort
```

DEQUE:

```text
Sliding Window Maximum
Sliding Window Minimum
Monotonic Queue
```
