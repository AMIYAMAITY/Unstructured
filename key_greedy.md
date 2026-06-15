# 🧠 Greedy Cheat Sheet

## 1. Identify Problem

Ask:

```text
Can I make the best decision NOW
without needing to reconsider later?
```

If YES:

```text
Think Greedy
```

If NO:

```text
Think DP / Backtracking
```

---

## 2. Core Question (MOST IMPORTANT)

```text
Can a local optimal choice
lead to a global optimal solution?
```

If YES:

```text
Greedy ✅
```

If NOT SURE:

```text
Need proof
```

Usually:

```text
Exchange Argument
or
Stays Ahead Argument
```

---

## 3. Recognition Signals

### 🔹 Repeatedly Choose Best Candidate

Words like:

```text
Largest
Smallest
Highest
Lowest
Earliest
Latest
```

Often means:

```text
Heap
Sorting
Greedy
```

Examples:

* Connect Ropes
* Huffman Coding
* Fractional Knapsack

---

### 🔹 Leave Maximum Room For Future

Recognition:

```text
Intervals
Scheduling
Activities
Meetings
```

Ask:

```text
Which choice leaves
the most options later?
```

Usually:

```text
Sort by ending time
```

Examples:

* Activity Selection
* Non-overlapping Intervals

---

### 🔹 Maximum Overlap Problems

Recognition:

```text
Intervals
Platforms
Meeting Rooms
Concurrent events
```

Think:

```text
Sweep Line
Min Heap
```

Examples:

* Train Platforms
* Meeting Rooms II

---

### 🔹 Fraction Allowed

Recognition:

```text
Can break item?
Can take partial?
```

If YES:

```text
Sort by ratio
```

Examples:

* Fractional Knapsack

---

### 🔹 Sort Then Scan

Many greedy solutions become obvious after sorting.

Common sorts:

```text
End Time
Start Time
Profit
Cost
Ratio
```

Recognition:

```text
Need best ordering
before making decisions
```

---

## 4. Most Common Greedy Strategies

### End Time Greedy

```text
Pick interval ending earliest
```

Used in:

* Activity Selection
* LC 435

---

### Ratio Greedy

```text
Pick highest value/weight
```

Used in:

* Fractional Knapsack

---

### Min Cost First

```text
Pick smallest cost now
```

Used in:

* Connect Ropes
* Huffman Coding

---

### Earliest Available

```text
Process event that finishes first
```

Used in:

* Scheduling
* Resource Allocation

---

## 5. Exchange Argument (KEY INSIGHT)

Ask:

```text
Suppose optimal solution
didn't pick my greedy choice.

Can I swap their choice
with mine and not make
the answer worse?
```

If YES:

```text
Greedy likely works
```

---

### Example

Intervals:

```text
[1,4]
[2,3]
```

Keeping:

```text
[2,3]
```

never reduces future options compared to:

```text
[1,4]
```

Therefore:

```text
earliest ending interval
is always safe
```

---

## 6. Heap vs Greedy Recognition

### Pure Greedy

```text
Sort once
Scan once
```

Examples:

* Activity Selection
* Fractional Knapsack

---

### Greedy + Heap

Recognition:

```text
Need current best element
multiple times
```

Think:

```text
Priority Queue
```

Examples:

* Connect Ropes
* Meeting Rooms
* Train Platforms

---

## 7. When Greedy Usually Fails

### 🚨 Take / Skip Pattern

Recognition:

```text
For every item:

Take?
or
Skip?
```

Think:

```text
DP
```

Examples:

* 0/1 Knapsack
* Subset Sum
* House Robber

---

### 🚨 Future Decisions Depend On Current Choice

Recognition:

```text
Current choice changes
future possibilities heavily
```

Think:

```text
DP
```

---

### 🚨 Arbitrary Coin Systems

Example:

```text
Coins = [1,3,4]
Amount = 6
```

Greedy:

```text
4 + 1 + 1
```

3 coins

Optimal:

```text
3 + 3
```

2 coins

Greedy fails.

---

## 8. Final Decision Flow

```text
Optimization Problem?
        ↓
Can I make best choice now?
        ↓
Need revisit later?
        ↓ YES → DP

        ↓ NO
Can I prove local optimum
leads to global optimum?
        ↓
      YES
        ↓
      Greedy
        ↓
Sort?
Heap?
Ratio?
End Time?
```

---

## 🔥 One-line Memory Hooks

```text
Intervals + Max Activities
    → Sort by End Time

Intervals + Active Count
    → Sweep Line / Heap

Fraction Allowed
    → Ratio Greedy

Repeated Best Choice
    → Heap

Take / Skip
    → DP

Need Future State
    → DP

Greedy Proof
    → Exchange Argument
```
