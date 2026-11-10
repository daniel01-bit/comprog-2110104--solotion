# comprog-2110104--solotion

# 💻 C++ Algorithms & Data Structures Portfolio

Welcome to my C++ algorithmic problem-solving repository! This collection features **15 selected solutions** from my Computer Programming coursework (`2110104` at Chulalongkorn University, CEDT) and competitive programming practice. 

Each implementation focuses on optimal **Time & Space Complexity**, effective use of the **C++ Standard Template Library (STL)**, graph traversal, and mathematical modeling.

---

## 🛠️ Tech Stack & Core Concepts
- **Language:** C++ (C++17 / GNU GCC)
- **Key STL Containers:** `std::multiset`, `std::map`, `std::set`, `std::deque`, `std::vector`, `std::tuple`
- **Algorithmic Paradigms:** Depth-First Search (DFS), Binary Search (`lower_bound`), Custom Comparators, Operator Overloading, Recursion, and Mathematical Optimization.

---

## 📂 Directory Structure & Problem Breakdown

### 1. 📊 Data Structures & STL Optimization (`/Data_Structures_STL`)

| File Name | Problem & Algorithmic Approach | Key Concepts / STL | Time Complexity |
| :--- | :--- | :--- | :---: |
| **`drone_frequency_jammer.cpp`** | **Dynamic Nearest-Frequency Search:** Processes real-time `SUPPLY` and `INTERCEPT` queries to match target frequencies within a tolerance range. Uses binary search over a balanced BST to find the closest element (`*lower_bound` vs `*prev`) and dynamically removes matched nodes. | `std::multiset`, `lower_bound`, `std::prev` | $O(M \log N)$ |
| **`bidder.cpp`** | **Multi-Item Auction Engine:** Simulates a competitive bidding system tracking highest valid bids, chronological tie-breaking, and invalid/spam bid penalties. Aggregates final user metrics and ranks winners using negated tuple keys for descending order. | `std::map`, `std::tuple`, Custom Sorting | $O(N \log N)$ |
| **`dept_select.cpp`** | **Quota Allocation System:** Assigns students to academic departments based on scores and prioritized preferences (4 choices). Implements a custom `struct` with `operator<` overloading to sort candidates before executing a greedy quota-matching pass. | `struct`, Operator Overloading, `std::map` | $O(M \log M)$ |
| **`shaabu.cpp`** | **Restaurant Queue Simulation:** Manages seating and waiting lines for small (`S`) and large (`L`) table capacities. Utilizes double-ended queues to handle FIFO customer arrivals, queue size limits (walk-aways), and instant seat-filling upon table departures. | `std::deque`, `std::pair`, Simulation | $O(K)$ |
| **`scholarship.cpp`** | **Multi-Tier Applicant Filtering:** Categorizes applicants into *Qualified*, *Waiting List*, and *Unqualified* pools based on GPA, financial need, and activity hours. Applies distinct multi-criteria comparator functions to each pool. | `struct`, Custom Comparators (`std::sort`) | $O(N \log N)$ |
| **`word_freq.cpp`** | **Text Tokenizer & Frequency Analyzer:** Parses raw multiline text streams, normalizes case, and filters valid tokens (length $\ge 2$). Ranks the top-$N$ words by frequency (descending), word length (descending), and lexicographical order using `std::make_tuple`. | `std::map`, String Parsing, Tuple Comparators | $O(W \log W)$ |
| **`company_department.cpp`** | **In-Memory Relational State Manager:** Simulates employee transfers and department mergers. Leverages nested associative containers to guarantee unique, alphabetically sorted employee lists per department with fast lookup and deletion. | `std::map<string, std::set<string>>` | $O(V \cdot D \log E)$ |

---

### 2. 🌐 Graph Traversal, Grids & Recursion (`/Graph_and_Recursion`)

| File Name | Problem & Algorithmic Approach | Key Concepts / STL | Time Complexity |
| :--- | :--- | :--- | :---: |
| **`island.cpp`** | **Connected Components on 2D Grid:** Counts the total number of distinct islands and computes the maximum island area on an $N \times M$ binary grid. Implements recursive 4-directional Depth-First Search (DFS) with in-place state mutation (`'1'` $\rightarrow$ `'0'`) to avoid auxiliary `visited` arrays. | 2D Grid DFS, Flood Fill, Recursion | $O(N \times M)$ |
| **`bts.cpp`** | **Transit Network Reachability (2-Hop):** Models a bidirectional skytrain network from raw text streams. Computes all stations reachable within a 2-hop radius from a starting station using adjacency lists and set-based BFS/expansion. | `std::map<string, vector<string>>`, `std::set`, `stringstream` | $O(V + E)$ |
| **`tiling_puzzle.cpp`** | **Sliding Puzzle Solvability Verifier:** Determines whether an $N \times N$ sliding tile puzzle can reach the solved state. Flattens the 2D board into a 1D sequence to compute the **Inversion Count** and combines it with the blank tile's row parity. | Inversion Count, Parity Invariants, 2D Arrays | $O(N^4)$ |
| **`ghost_leg.cpp`** | **Amidakuji (Ghost Leg) Simulator:** Traces permutation paths across $N$ vertical lines and $M$ horizontal rungs, linking participants to prizes and scores. Supports both rank-based and name-based lookup queries. | Pass-by-Reference, `std::tuple`, Simulation | $O(N \cdot M + N \log N)$ |
| **`recursive1.cpp`** | **Grid Pathfinding with Obstacles:** Calculates the total number of valid paths from the top-left corner $(0,0)$ to the bottom-right corner $(N-1, N-1)$ moving only right and down while avoiding blocked cells. | Recursion, Backtracking, 2D `std::vector` | $O(2^{2N})$ |

---

### 3. 📈 Mathematics & Statistical Modeling (`/Math_and_Stats`)

| File Name | Problem & Algorithmic Approach | Key Concepts / STL | Time Complexity |
| :--- | :--- | :--- | :---: |
| **`simple_linear_regression.cpp`** | **Ordinary Least Squares (OLS) Estimator:** Computes the slope ($m$) and y-intercept ($b$) for a given dataset of 2D coordinates $(x_i, y_i)$ using closed-form statistical formulas: $m = \frac{n\sum xy - \sum x \sum y}{n\sum x^2 - (\sum x)^2}$. Formats output as either raw parameters or a clean algebraic equation ($y = mx + b$). | Statistical Modeling, Floating-Point Precision | $O(N)$ |
| **`number_of_digits.cpp`** | **Logarithmic Digit Counting:** Computes the total number of digits written when listing all integers in the interval $[M, N]$ (up to $10^{18}$). Bypasses $O(N)$ brute-force iteration by grouping numbers by their order of magnitude ($[10^k, 10^{k+1}-1]$) and applying prefix-subtraction: $\text{count}(N) - \text{count}(M-1)$. | Combinatorics, Prefix Range Query, `long long` | $O(\log_{10} N)$ |
| **`decimal_2_fraction.cpp`** | **Repeating Decimal to Irreducible Fraction:** Converts a repeating decimal (given as integer, non-repeating, and repeating parts) into its simplest fraction $\frac{P}{Q}$. Constructs the algebraic denominator ($99\dots900\dots0$) and simplifies the ratio using the recursive **Euclidean Algorithm (`gcd`)**. | Number Theory, Euclidean Algorithm (`gcd`), String-to-Int | $O(\log(\min(P, Q)))$ |

---

## 🚀 How to Compile and Run

All solutions are standalone C++ files optimized with fast I/O (`std::ios_base::sync_with_stdio(false); cin.tie(NULL);`). To compile and run any file locally using `g++`:

```bash
# Compile with C++17 standard and O2 optimization
g++ -std=c++17 -O2 Data_Structures_STL/drone_frequency_jammer.cpp -o solution

# Run the executable
./solution
