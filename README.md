# ASSIGNMENT 4: Routing Protocols (DVR & LSR)

## Authors: Ekansh Bajpai (220390), Pulkit Dhayal (220834)

## Course: CS425 - Computer Networks  
**Instructor:** Adithya Vadapalli  
**TAs In-Charge:** Rishit and Yugul

---

## Overview
This assignment simulates two fundamental routing algorithms in C++:

1. **Distance Vector Routing (DVR)**  
   - Nodes exchange routing tables with neighbors.
   - Iterative updates lead to shortest paths via distributed computation.

2. **Link State Routing (LSR)**  
   - Each node knows the full network.
   - Computes shortest paths using Dijkstra’s algorithm.

Both algorithms are tested on a given network topology represented as an **adjacency matrix**.

---

## Input Format


The input is read from a file. Format:

- First line: An integer `n`, the number of nodes.
- Next `n` lines: An `n × n` adjacency matrix of space-separated integers.
  - `0`: No direct link.
  - `9999`: Infinite cost (unreachable).

### Example: `input1.txt`
---

## 🛠️ Compilation and Execution

### 🔧 Compile

```bash
g++ routing_sim.cpp -o routing_sim
```
### OR
```bash
make
```
---

## Usage Instructions
### Run
```bash
./routing_sim input*.txt
```

---


## File Structure

```
A4/
│── routing_sim.cpp       # C++ code implementing the routing algorithms
│── input*.txt            # Input files for testing 
│── README.md             # Documentation
```

---
