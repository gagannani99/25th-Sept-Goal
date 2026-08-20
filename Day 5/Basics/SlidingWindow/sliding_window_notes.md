# Sliding Window Algorithm

## When Should I Use Sliding Window?

Use the **Sliding Window** technique when a problem involves a **contiguous/continuous part of an array or string** and you need to find something about that range efficiently.

### Main Signals

If you see words like:

- **subarray**
- **substring**
- **contiguous**
- **consecutive**
- **window of size K**
- **longest/shortest subarray satisfying a condition**
- **maximum/minimum sum of K consecutive elements**

think about **Sliding Window**.

### Quick Recognition Trick

Ask yourself:

> **"Am I looking at a contiguous section and moving that section from left to right?"**

If yes, Sliding Window is a strong candidate.

---

# Types of Sliding Window

There are two main types:

1. **Fixed-Size Sliding Window**
2. **Variable-Size Sliding Window**

---

# 1. Fixed-Size Sliding Window

Use this when the **window size K is given**.

## Typical Structure

```cpp
int left = 0;
int sum = 0;

for(int right = 0; right < n; right++) {
    sum += nums[right];

    if(right - left + 1 == k) {
        // calculate/update answer

        sum -= nums[left];
        left++;
    }
}
```

## Pattern

```text
Expand right
     ↓
Window reaches K
     ↓
Calculate/update answer
     ↓
Remove left element
     ↓
Move left
```

### Example

**Problem:** Find the maximum sum of any K consecutive elements.

```text
Array = [2, 1, 5, 1, 3, 2]
K = 3
```

Windows:

```text
2 1 5 → 8
1 5 1 → 7
5 1 3 → 9  ← maximum
1 3 2 → 6
```

Instead of calculating every window from scratch, Sliding Window:

- adds the new right element
- removes the old left element
- maintains the current window result

This gives **O(N)** time instead of **O(N × K)**.

---

# 2. Variable-Size Sliding Window

Use this when the **window size is not fixed** and the problem gives you a **condition**.

## Typical Structure

```cpp
int left = 0;

for(int right = 0; right < n; right++) {

    // Add nums[right]

    while(condition is invalid) {
        // Remove nums[left]
        left++;
    }

    // Calculate/update answer
}
```

## Pattern

```text
Expand right
     ↓
Condition becomes invalid
     ↓
Shrink from left
     ↓
Condition becomes valid
     ↓
Calculate/update answer
```

### Example

**Problem:** Find the longest subarray with sum ≤ K.

```cpp
int left = 0;
int sum = 0;
int ans = 0;

for(int right = 0; right < n; right++) {
    sum += nums[right];

    while(sum > k) {
        sum -= nums[left];
        left++;
    }

    ans = max(ans, right - left + 1);
}
```

Here:

- `right` expands the window
- if the condition becomes invalid, `left` moves forward
- once the condition is valid again, update the answer

---

# Fixed vs Variable Sliding Window

| Type | When to Use | Main Condition |
|---|---|---|
| **Fixed** | Window size `K` is given | `right - left + 1 == K` |
| **Variable** | Window size depends on a condition | `while(condition is invalid)` |

## Easy Memory Trick

**Fixed → `if`**

```cpp
if(right - left + 1 == k)
```

**Variable → `while`**

```cpp
while(condition is invalid)
```

---

# Important DSA Recognition Rule

When you see:

> **subarray/substring + contiguous + longest/shortest/max/min**

immediately consider **Sliding Window**.

But if the problem asks about **any two or three elements**, such as:

- Two Sum
- Three Sum

Sliding Window is usually **not** the right technique.

---

# Complexity

For a properly implemented Sliding Window:

**Time Complexity: O(N)**

The reason is that both `left` and `right` move forward through the array. Each element is generally added and removed at most once.

**Space Complexity:** Usually **O(1)**, unless an additional data structure such as a frequency map/set is required.

---

# Summary

```text
Contiguous range?
      ↓
     YES
      ↓
Is K fixed?
   ↙       ↘
 YES        NO
  ↓          ↓
Fixed      Variable
Window      Window
  ↓          ↓
  if       while
```

### Remember

- **Fixed Window:** size is known → maintain exactly `K` elements.
- **Variable Window:** size changes → expand/shrink according to a condition.
- Both use **two pointers: `left` and `right`**.
- The goal is usually to reduce a nested-loop solution to **O(N)**.
