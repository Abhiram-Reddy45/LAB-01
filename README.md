# Performance Profiling and Optimization using GPROF and PERF

# Objective

The objective of this experiment is to compare the performance of two sorting algorithms, Bubble Sort and Quick Sort, using Linux performance analysis tools. The experiment measures execution time, profiles the application using GPROF, collects hardware statistics using PERF, and analyzes the effect of compiler optimization levels (-O0, -O2, and -O3).

# Software Requirements

- Kali Linux / Ubuntu Linux
- GCC Compiler
- GNU GPROF
- Linux PERF

---

# Files


Lab01/
│── mysort.c
│── README.md
│── report.pdf
│── myreport.txt
│── report_O2.txt
│── report_O3.txt
│── screenshots/


---

# Compilation

## Without Optimization (-O0)

```bash
gcc -O0 -pg mysort.c -o mysort
```

## With Optimization (-O2)

```bash
gcc -O2 -pg mysort.c -o mysort_O2
```

## With Optimization (-O3)

```bash
gcc -O3 -pg mysort.c -o mysort_O3
```

---

# Program Execution

## Run Without Optimization

```bash
./mysort
```

## Run O2 Version

```bash
./mysort_O2
```

## Run O3 Version

```bash
./mysort_O3
```

---

# Measure Execution Time

```bash
time ./mysort
```

---

# Generate GPROF Report

For O2:

```bash
gprof mysort_O2 gmon.out > report_O2.txt
```

For O3:

```bash
gprof mysort_O3 gmon.out > report_O3.txt
```

---

# Collect Hardware Performance Statistics

Without Optimization

```bash
perf stat ./mysort
```

With O2

```bash
perf stat ./mysort_O2
```

With O3

```bash
perf stat ./mysort_O3
```

---

# Algorithms Used

## Bubble Sort

- Time Complexity:
  - Best Case: O(n)
  - Average Case: O(n²)
  - Worst Case: O(n²)

Bubble Sort repeatedly compares adjacent elements and swaps them until the array is sorted.

---

## Quick Sort

- Time Complexity:
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n²)

Quick Sort uses the divide-and-conquer approach by selecting a pivot and partitioning the array recursively.

---

# Performance Analysis

The experiment compares:

- Execution Time
- CPU Cycles
- Instructions
- Instructions Per Cycle (IPC)
- Cache References
- Cache Misses
- Branch Misses
- GPROF Hotspot Functions

---

# Expected Observation

- Quick Sort performs significantly faster than Bubble Sort.
- Bubble Sort consumes most of the execution time due to its O(n²) complexity.
- Compiler optimizations (-O2 and -O3) reduce execution time.
- GPROF identifies the most time-consuming functions.
- PERF provides detailed hardware performance statistics.

---

# Conclusion

This experiment demonstrates that Quick Sort is more efficient than Bubble Sort for sorting temperature datasets. Compiler optimizations improve execution speed, and Linux profiling tools such as GPROF and PERF help identify performance bottlenecks and analyze hardware-level execution characteristics.

---

# Author

Chamala Abhiram Reddy

B.Tech Computer Science and Engineering

Indian Institute of Information Technology Sri City
