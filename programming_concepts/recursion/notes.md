## 📈 How to Use This Roadmap

1. **Start Small** (Basic tier) until you can mentally trace every call.
2. **Dry-Run & Debug**: write recursion trees on paper or use print statements.
3. **Analyze Complexity**: for each solution, derive its time/space cost.
4. **Add Memoization**: revisit basic problems (e.g. Fibonacci) and optimize.
5. **Mix in Challenges**: on days you feel confident, pick 1–2 advanced problems.

- Base Case: When to stop recursing.
- Recursive Case: How the problem reduces to a smaller subproblem.
- Call Stack Understanding: What happens under the hood when functions call themselves.

---

## 🟢 Basic Tier

Focus: understanding base vs. recursive case, call‐stack behavior, simple reductions.

| Category   | Problem          | Description                                                         |
| ---------- | ---------------- | ------------------------------------------------------------------- |
| **Math**   | Factorial        | Compute n! recursively.                                             |
|            | Fibonacci        | Return the nth Fibonacci number (naïve recursion).                  |
|            | Power            | Compute xᵏ recursively (exponentiation by repeated multiplication). |
| **Array**  | Sum of array     | Sum all elements in an array.                                       |
|            | Max/Min          | Find the maximum (or minimum) element.                              |
|            | Linear search    | Recursively search for a value’s index.                             |
| **String** | Reverse string   | Return the reversed string.                                         |
|            | Palindrome check | Determine if a string reads the same backward.                      |
| **Digits** | Sum of digits    | Sum all digits of an integer.                                       |
|            | Count digits     | Count how many digits are in an integer.                            |

---

## 🟡 Intermediate Tier

Focus: multi-branch recursion, simple backtracking, divide‐and‐conquer patterns.

| Category             | Problem               | Description                                         |
| -------------------- | --------------------- | --------------------------------------------------- |
| **Divide & Conquer** | Binary Search         | Implement binary search on a sorted array.          |
|                      | Merge Sort            | Sort an array by recursively splitting and merging. |
|                      | Quick Sort            | Implement quicksort’s partition + recursive sort.   |
| **String / Subsets** | Subsequences          | Print all subsequences (the power set) of a string. |
|                      | Generate parentheses  | Produce all valid n-pair parentheses strings.       |
| **Backtracking**     | Combination sum       | Find all combinations that sum to target.           |
|                      | Subset sum decision   | Decide if any subset sums to target.                |
| **Trees**            | Binary tree traversal | Inorder, preorder, postorder.                       |
|                      | Height of tree        | Compute the max depth.                              |
|                      | Count nodes           | Count total nodes in a tree.                        |
| **Math/Other**       | GCD (Euclid)          | Compute greatest common divisor.                    |
|                      | Decimal→Binary        | Convert an integer to its binary string.            |

---

## 🔴 Advanced Tier

Focus: complex backtracking, tree & graph recursion, recursion + memoization (DP).

| Category                         | Problem                        | Description                                           |
| -------------------------------- | ------------------------------ | ----------------------------------------------------- |
| **Backtracking**                 | N-Queens                       | Place N queens so none attack each other.             |
|                                  | Sudoku solver                  | Fill a 9×9 grid to satisfy Sudoku rules.              |
|                                  | Knight’s tour                  | Find a knight’s path covering all chessboard squares. |
|                                  | Word search                    | Find given words in a character grid.                 |
| **Trees**                        | Diameter of tree               | Find longest path between any two nodes.              |
|                                  | Lowest common ancestor         | Find LCA of two nodes in a binary tree.               |
|                                  | Serialize/deserialize          | Convert tree ↔ string.                                |
| **Graphs**                       | DFS connectivity               | Count connected components.                           |
|                                  | Detect cycle                   | In directed & undirected graphs.                      |
|                                  | Hamiltonian path               | Backtrack to find a path visiting every node once.    |
| **Recursion + Memoization (DP)** | Fibonacci (memoized)           | Optimize naive Fibonacci.                             |
|                                  | 0/1 Knapsack                   | Maximize value under weight constraint.               |
|                                  | Longest Increasing Subsequence | Classic DP via recursion+cache.                       |
|                                  | Word Break                     | Check if string can be segmented into dict words.     |
