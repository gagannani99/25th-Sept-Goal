# Backtracking in C++ — From Absolute Beginner to Interview Level

## 🎯 Goal

This guide teaches **backtracking from scratch**.

You do **not** need prior backtracking knowledge.

You should already know basic:
- C++
- functions
- arrays / vectors
- recursion

The goal is to understand **why backtracking works**, not to memorize templates.

---

# 1. What Is Backtracking?

Backtracking is a problem-solving technique where we:

1. Make a choice.
2. Explore what happens after that choice.
3. Undo the choice.
4. Try another choice.

The simplest way to remember it:

> **CHOOSE → EXPLORE → UNDO → TRY ANOTHER CHOICE**

Example:

```text
Choose 1
   ↓
Explore all possibilities after choosing 1
   ↓
Undo 1
   ↓
Try not choosing 1
```

The word **backtracking** comes from the fact that after exploring one path, we **go back** and try another path.

---

# 2. Why Do We Need Backtracking?

Imagine the question:

> Generate all possible binary strings of length 2.

At every position we have two choices:

```text
0
1
```

For the first position:

```text
0 OR 1
```

For the second position:

```text
0 OR 1
```

Therefore:

```text
00
01
10
11
```

The important observation is:

> At every step, we have multiple choices.

Whenever a problem asks us to explore **many possible choices**, recursion + backtracking is often useful.

---

# 3. Backtracking vs Normal Recursion

These concepts are related but not identical.

## Recursion

A function calls itself to solve a smaller version of a problem.

Example:

```cpp
int factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Here we are simply reducing the problem:

```text
factorial(5)
→ factorial(4)
→ factorial(3)
→ factorial(2)
→ factorial(1)
→ factorial(0)
```

There is no need to make multiple choices.

---

## Backtracking

Backtracking usually involves:

```text
Choice 1
    ↓
Explore
    ↓
Undo
    ↓
Choice 2
    ↓
Explore
    ↓
Undo
```

So:

> **Backtracking = recursion + systematic choice exploration + undoing choices**

---

# 4. The Most Important Pattern

Memorize the idea, not the exact code:

```text
MAKE A CHOICE
      ↓
EXPLORE
      ↓
UNDO THE CHOICE
      ↓
TRY THE NEXT CHOICE
```

In code, this often looks like:

```cpp
makeChoice();

solve();

undoChoice();

makeAnotherChoice();

solve();

undoChoice();
```

The exact implementation changes from problem to problem.

---

# 5. First Backtracking Problem: Binary Strings

## Problem

Generate all binary strings of length `2`.

Expected:

```text
00
01
10
11
```

At every position we have two choices:

```text
Choose 0
Choose 1
```

---

# 6. Recursion Tree

Let's visualize it.

Start with an empty string:

```text
                ""
              /    \
             0      1
           /  \    /  \
         00   01  10   11
```

Every level represents one position.

For length `2`:

```text
Level 0 → choose first character
Level 1 → choose second character
Level 2 → complete string
```

Once the length becomes `2`, we have a complete answer.

---

# 7. Code for Binary Strings

```cpp
#include <bits/stdc++.h>
using namespace std;

void generate(string &current, int n) {

    // Base case
    if (current.size() == n) {
        cout << current << endl;
        return;
    }

    // Choice 1: choose 0
    current.push_back('0');

    generate(current, n);

    // Undo choice
    current.pop_back();

    // Choice 2: choose 1
    current.push_back('1');

    generate(current, n);

    // Undo choice
    current.pop_back();
}

int main() {

    string current = "";

    generate(current, 2);

    return 0;
}
```

Output:

```text
00
01
10
11
```

---

# 8. Understand `push_back()` and `pop_back()`

This is one of the most important ideas in beginner backtracking.

Suppose:

```cpp
current = "";
```

Choose `0`:

```cpp
current.push_back('0');
```

Now:

```text
current = "0"
```

We explore everything possible after choosing `0`.

Eventually we finish that branch.

Now we need to return to:

```text
current = ""
```

So:

```cpp
current.pop_back();
```

This is the **undo** step.

Then we choose `1`.

```cpp
current.push_back('1');
```

Now:

```text
current = "1"
```

And we explore that branch.

---

# 9. The Most Important Mental Model

Think of `current` as your current decision path.

Example:

```text
current = "01"
```

means:

> "So far, I have chosen 0 and then 1."

When the branch is finished:

```cpp
current.pop_back();
```

means:

> "Forget my last decision. I want to try a different decision."

This is backtracking.

---

# 10. Your First Exercise

Modify the previous program to generate binary strings of length `3`.

Expected:

```text
000
001
010
011
100
101
110
111
```

How many answers?

```text
2^3 = 8
```

---

# 11. Why Are There 2^N Answers?

Suppose there are `N` positions.

At every position:

```text
2 choices
```

Therefore:

```text
2 × 2 × 2 × ... × 2
```

`N` times.

So:

```text
Number of possibilities = 2^N
```

This is why many subset/backtracking problems have exponential complexity.

---

# 12. Choose / Don't Choose Pattern

Now we move to the most important beginner pattern.

Suppose:

```text
nums = [1, 2, 3]
```

For every element, we have two choices:

```text
TAKE
DON'T TAKE
```

For `1`:

```text
Take 1
Don't take 1
```

For `2`:

```text
Take 2
Don't take 2
```

For `3`:

```text
Take 3
Don't take 3
```

This generates every subset.

---

# 13. Subsets

A subset is a selection of zero or more elements.

For:

```text
[1,2]
```

the subsets are:

```text
[]
[1]
[2]
[1,2]
```

There are:

```text
2^2 = 4
```

subsets.

For:

```text
[1,2,3]
```

there are:

```text
2^3 = 8
```

subsets.

---

# 14. Recursion Tree for Subsets

For:

```text
[1,2]
```

the decision tree is:

```text
                    []
                  /    \
              TAKE 1   SKIP 1
                [1]       []
               /  \       /  \
           TAKE2 SKIP2 TAKE2 SKIP2
           [1,2] [1]   [2]    []
```

The leaves are the final subsets:

```text
[1,2]
[1]
[2]
[]
```

---

# 15. Subset Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(
    int index,
    vector<int>& nums,
    vector<int>& current
) {

    // Base case
    if (index == nums.size()) {

        for (int x : current)
            cout << x << " ";

        cout << endl;

        return;
    }

    // --------------------
    // Choice 1: TAKE
    // --------------------

    current.push_back(nums[index]);

    solve(index + 1, nums, current);

    // Undo
    current.pop_back();

    // --------------------
    // Choice 2: DON'T TAKE
    // --------------------

    solve(index + 1, nums, current);
}

int main() {

    vector<int> nums = {1, 2, 3};

    vector<int> current;

    solve(0, nums, current);

    return 0;
}
```

---

# 16. Understand This Code Slowly

Don't memorize it.

Understand these four lines:

```cpp
current.push_back(nums[index]);

solve(index + 1, nums, current);

current.pop_back();

solve(index + 1, nums, current);
```

They mean:

```text
TAKE
 ↓
EXPLORE
 ↓
UNDO
 ↓
DON'T TAKE
 ↓
EXPLORE
```

That is the heart of the choose/don't-choose technique.

---

# 17. Why `index + 1`?

Because after making a decision about:

```text
nums[index]
```

we move to the next element.

Example:

```text
index = 0 → nums[0]
index = 1 → nums[1]
index = 2 → nums[2]
```

Eventually:

```text
index == nums.size()
```

which means:

> We have made a decision about every element.

So we store the current answer.

---

# 18. Backtracking Trace

For:

```text
nums = [1,2]
```

Start:

```text
index = 0
current = []
```

Take `1`:

```text
current = [1]
```

Take `2`:

```text
current = [1,2]
```

Reached the end.

Store:

```text
[1,2]
```

Backtrack:

```text
current = [1]
```

Don't take `2`.

Store:

```text
[1]
```

Backtrack again:

```text
current = []
```

Don't take `1`.

Take `2`:

```text
current = [2]
```

Store:

```text
[2]
```

Finally:

```text
current = []
```

Store:

```text
[]
```

Therefore:

```text
[1,2]
[1]
[2]
[]
```

---

# 19. The `current` Vector Is Shared

Notice:

```cpp
vector<int>& current
```

The `&` means we pass the same vector by reference.

Why?

Because we want:

```text
choose → modify current
explore → use current
undo → restore current
```

If we copied the vector unnecessarily at every step, we would use more memory.

---

# 20. What Does "Backtrack" Actually Mean?

Suppose we're exploring:

```text
[1,2,3]
```

and currently have:

```text
[1,3]
```

We finish that branch.

Then:

```cpp
current.pop_back();
```

gives:

```text
[1]
```

We are literally going backward in our decision path.

That is why:

```text
BACKTRACK
```

means:

> **Undo the last decision and try another possibility.**

---

# 21. Backtracking Template

A common template is:

```cpp
void solve(...) {

    if (base_case) {
        save_answer();
        return;
    }

    // Make a choice

    solve(...);

    // Undo the choice

    // Make another choice

    solve(...);

    // Undo again
}
```

But remember:

> **Templates are not the concept.**

The concept is:

```text
CHOICE
→ EXPLORE
→ UNDO
→ NEXT CHOICE
```

---

# 22. Subsets Using a Loop

There is another important backtracking style.

For combination-type problems, you will often see:

```cpp
void solve(int start,
           vector<int>& nums,
           vector<int>& current) {

    // current is one valid answer

    for (int i = start; i < nums.size(); i++) {

        current.push_back(nums[i]);

        solve(i + 1, nums, current);

        current.pop_back();
    }
}
```

This style is extremely important for:

- combinations
- Combination Sum
- Combination Sum II
- subsets with duplicates

Don't worry about mastering it immediately.

First master:

```text
TAKE / DON'T TAKE
```

---

# 23. Subsequence vs Subset

These are often confused.

## Subsequence

Order matters.

You can remove elements, but you cannot rearrange the remaining elements.

Example:

```text
[1,2,3]
```

Valid subsequences include:

```text
[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```

But:

```text
[3,1]
```

is not a subsequence because the original order was:

```text
1 → 2 → 3
```

---

## Subset

A mathematical set doesn't care about order.

In coding problems, subsets are usually represented while preserving input order, so the same choose/don't-choose recursion is often used.

For interview purposes, focus on the problem's exact definition.

---

# 24. Subarray vs Subsequence vs Subset

## Subarray

Contiguous.

```text
[1,2,3,4]
```

Examples:

```text
[1,2]
[2,3]
[3,4]
[1,2,3]
```

But:

```text
[1,3]
```

is NOT a subarray.

---

## Subsequence

Not necessarily contiguous, but order is preserved.

```text
[1,3]
```

is a subsequence.

---

## Subset

Selection of elements where order generally isn't the defining property.

---

# 25. Permutations

Subsets ask:

> Should I take this element?

Permutations ask:

> Which element should I place next?

For:

```text
[1,2,3]
```

permutations are:

```text
123
132
213
231
312
321
```

There are:

```text
3! = 6
```

---

# 26. Permutation Recursion Tree

For:

```text
[1,2,3]
```

first choose:

```text
1
```

Then choose from:

```text
2,3
```

Then choose the remaining element.

Tree idea:

```text
              ""
          /    |    \
         1     2     3
       /  \   / \   / \
     12   13 21 23 31 32
     |     |  |   | |   |
    123   132 213 231 312 321
```

The key difference:

> **Subsets:** each element has take/skip decisions.

> **Permutations:** choose which unused element comes next.

---

# 27. Tracking Used Elements

A common permutation approach uses:

```cpp
vector<bool> used(nums.size(), false);
```

Example:

```text
nums = [1,2,3]

used:
false false false
```

Choose `1`:

```text
used:
true false false
```

Explore.

Then undo:

```text
used:
false false false
```

Then try `2`.

Again:

```text
CHOOSE → EXPLORE → UNDO
```

---

# 28. Basic Permutation Code

```cpp
void solve(
    vector<int>& nums,
    vector<bool>& used,
    vector<int>& current
) {

    if (current.size() == nums.size()) {

        for (int x : current)
            cout << x << " ";

        cout << endl;

        return;
    }

    for (int i = 0; i < nums.size(); i++) {

        if (used[i])
            continue;

        // Choose
        used[i] = true;
        current.push_back(nums[i]);

        // Explore
        solve(nums, used, current);

        // Undo
        current.pop_back();
        used[i] = false;
    }
}
```

Notice the same idea again:

```text
used[i] = true
push_back()
      ↓
solve()
      ↓
pop_back()
used[i] = false
```

---

# 29. Combination Sum

Now we're ready for a famous interview problem.

Given:

```text
candidates = [2,3,6,7]
target = 7
```

Find combinations whose sum is `7`.

Answer:

```text
[2,2,3]
[7]
```

Why can we use `2` multiple times?

Because the problem says an element can be reused.

This changes the recursion.

If we choose `2`, we may continue from the same index.

Conceptually:

```text
choose 2
→ choose 2 again
→ choose 3
→ sum = 7
```

---

# 30. Pruning

Backtracking can explore an enormous number of possibilities.

We can sometimes stop exploring a branch early.

This is called:

> **Pruning**

Example:

```text
target = 7
current sum = 10
```

There is no point continuing.

So:

```cpp
if (sum > target)
    return;
```

We cut off that branch.

This saves work.

---

# 31. Why Sorting Helps With Pruning

Suppose:

```text
candidates = [2,3,6,8]
target = 7
```

If the array is sorted and:

```text
current_sum + candidates[i] > target
```

then every later element will also be too large.

So we can:

```cpp
break;
```

This is one reason sorting is powerful in backtracking.

---

# 32. Duplicate Combinations

Consider:

```text
[1,1,2]
```

Different recursion paths could produce the same combination.

We don't want:

```text
[1,2]
[1,2]
```

We want:

```text
[1,2]
```

A common technique is:

```cpp
sort(nums.begin(), nums.end());
```

Then skip duplicates at the same recursion level:

```cpp
if (i > start && nums[i] == nums[i - 1])
    continue;
```

Don't memorize this yet.

Understand the reason:

> **At the same decision level, don't start two identical branches.**

---

# 33. Recursion Tree vs Decision Tree

You will often hear both terms.

A recursion tree shows:

```text
which recursive calls happen
```

A decision tree emphasizes:

```text
which choices are being made
```

For backtracking, decision-tree thinking is extremely useful.

Before coding, ask:

> What choices exist at each level?

---

# 34. How to Recognize Backtracking Problems

Look for phrases like:

- Generate all possible...
- Find all combinations...
- Find all permutations...
- Generate all subsets...
- Choose `k` elements...
- Find all valid arrangements...
- Find all ways...
- Place elements in every possible position...
- Try every possible configuration...

These often suggest backtracking.

But don't assume blindly.

---

# 35. Backtracking Complexity

Backtracking is often exponential.

For subsets:

```text
2^N
```

For permutations:

```text
N!
```

Why?

Because the number of possible answers itself can be enormous.

If a problem asks you to output all `2^N` subsets, you cannot realistically have a solution faster than the amount of output you must produce.

---

# 36. Common Beginner Mistakes

## Mistake 1 — Forgetting the base case

Without:

```cpp
if (...)
    return;
```

recursion can continue forever.

---

## Mistake 2 — Forgetting to undo

Wrong:

```cpp
current.push_back(x);
solve(...);
```

Correct backtracking usually needs:

```cpp
current.push_back(x);
solve(...);
current.pop_back();
```

---

## Mistake 3 — Undoing before recursion

Wrong:

```cpp
current.push_back(x);
current.pop_back();
solve(...);
```

You removed the choice before exploring it.

---

## Mistake 4 — Passing the wrong index

Be clear about what `index` means.

Usually:

> `index` = the next element/position we need to make a decision about.

---

## Mistake 5 — Memorizing templates

Don't memorize:

```cpp
if (...)
continue;
```

without understanding why.

In interviews, the exact recursion structure changes.

---

# 37. The Backtracking Checklist

Whenever you get a new problem, ask:

### Step 1
What is my current state?

Example:

```text
index
current vector
current sum
used array
```

### Step 2
What choices can I make?

Example:

```text
take / don't take
choose one of many elements
```

### Step 3
What is my base case?

Example:

```text
index == n
```

or:

```text
current.size() == n
```

or:

```text
sum == target
```

### Step 4
What do I do when I reach a valid answer?

```cpp
ans.push_back(current);
```

### Step 5
What must I undo?

Examples:

```cpp
current.pop_back();
used[i] = false;
sum -= nums[i];
```

This checklist will help enormously in interviews.

---

# 38. Beginner Learning Path

Do NOT jump directly into hard problems.

Follow this order:

```text
1. Recursion
       ↓
2. Binary strings
       ↓
3. Choose / Don't Choose
       ↓
4. Subsets
       ↓
5. Subsequences
       ↓
6. Permutations
       ↓
7. Combination Sum
       ↓
8. Duplicate handling
       ↓
9. Pruning
       ↓
10. Advanced Backtracking
```

---

# 39. Your Practice Mission

## Level 1 — Must Do

### Problem 1
Generate binary strings of length `2`.

### Problem 2
Generate binary strings of length `3`.

### Problem 3
Generate all subsets of:

```text
[1,2]
```

### Problem 4
Generate all subsets of:

```text
[1,2,3]
```

---

## Level 2

### Problem 5
Generate all subsequences of:

```text
"abc"
```

### Problem 6
Find whether a subset with a given sum exists.

### Problem 7
Count subsets having a given sum.

---

## Level 3

### Problem 8
Generate all permutations of:

```text
[1,2,3]
```

### Problem 9
Generate all string permutations of:

```text
"abc"
```

---

## Level 4

### Problem 10
Combination Sum.

### Problem 11
Combination Sum II.

---

## Boss Fight

### Problem 12
Generate all **unique subsets** when duplicates exist.

Example:

```text
[1,2,2]
```

Expected:

```text
[]
[1]
[2]
[1,2]
[2,2]
[1,2,2]
```

---

# 40. Final Mental Model

If you remember only one diagram from this document, remember this:

```text
                 START
                   |
              Make a choice
                   |
                EXPLORE
                   |
              Make progress
                   |
            Is branch complete?
              /           \
            YES            NO
             |              |
        Save answer      Continue
             |
          BACKTRACK
             |
        Undo the choice
             |
       Try another choice
```

And the core code pattern:

```cpp
// CHOOSE
current.push_back(x);

// EXPLORE
solve(...);

// UNDO
current.pop_back();
```

That is the heart of backtracking.

---

# 🫡 Final Takeaway

Do not think:

> "Backtracking is complicated."

Think:

> **"I have a decision to make. I'll try one option, recursively explore it, undo it, and try the next option."**

Once that idea becomes natural, problems like:

- Subsets
- Subsequences
- Permutations
- Combination Sum
- N-Queens
- Sudoku

become variations of the same fundamental idea.

---

# 🇮🇳 DAY 7 TRAINING ORDER

For your current DSA preparation, do these in exactly this order:

```text
Binary Strings
      ↓
Choose / Don't Choose
      ↓
Subsets
      ↓
Subsequences
      ↓
Permutations
      ↓
Combination Sum
      ↓
Unique Subsets
      ↓
Advanced Backtracking
```

**Do not rush. Understanding the first three properly is more valuable than copying ten advanced backtracking solutions.**

**JAI HIND! 🇮🇳🫡**
