### CPU Task Scheduling Program

---

#### **Introduction**
This program demonstrates three CPU scheduling algorithms: 
1. **First Come First Serve (FCFS)**
2. **Shortest Job First (SJF)**
3. **Round Robin (RR)**

The program uses a variety of data structures to efficiently implement these algorithms and simulate the task scheduling process. Below, we explain the data structures used and their roles.

---

#### **Data Structures Used**

1. **Vector (`vector`):**
     - Used to store the durations of processes entered by the user.
     - Dynamic resizing makes it suitable for storing input of arbitrary size.
     - Simple indexing allows easy traversal for scheduling logic.

2. **Queue (`queue`):**
     - Used in the FCFS and Round Robin algorithms to manage processes in the order they arrive or need further execution.
     - FIFO (First-In-First-Out) nature of `queue` aligns with the behavior required for these algorithms.

3. **Priority Queue (`priority_queue`):**
     - Used in the SJF algorithm to sort processes by their execution time, with the shortest job prioritized.
     - Ensures that the shortest available job is always selected for execution next.
     - A custom comparator `comparesjf` is defined to override the default max-heap behavior and implement a min-heap.

4. **Struct (`proc`):**
     - Represents a process with its execution time (`ptime`) and entry order (`entry`).
     - Provides a way to associate metadata (e.g., process order) with each process, crucial for correct output formatting.

---

#### **Explanation of Algorithms**

1. **First Come First Serve (FCFS):**
     - Processes are executed in the order they arrive.
     - A simple queue is used to store and process jobs sequentially.
     - Displays the start and end times for each process.

2. **Shortest Job First (SJF):**
     - Processes with the shortest execution time are prioritized.
     - A priority queue, implemented as a min-heap, sorts jobs based on their durations.
     - Displays the order of execution, along with start and end times.

3. **Round Robin (RR):**
     - Processes are executed in a cyclic order with a fixed time slice (quantum).
     - Two queues (`q1` and `q2`) are alternated to manage processes waiting for their turn.
     - Displays how processes share CPU time and the time intervals for each execution.

---

#### **How to Run**

1. Compile the program using a C++ compiler:
   ```bash
   g++ -o CPU_Scheduler CPU_Task_Sheduler.cpp
   ```
2. Run the executable:
   ```bash
   ./CPU_Scheduler
   ```
3. Follow the prompts to:
   - Enter the number of processes and their durations.
   - Specify the quantum time for the Round Robin algorithm.

---

#### **Sample Output**

```
CPU TASK SCHEDULING

Enter the number of processes: 3
Enter duration of process 1: 5
Enter duration of process 2: 3
Enter duration of process 3: 7

Enter quantum for Round Robin: 4

First Come First Serve Schedule:
Process 1 starts at 0, ends at 5
Process 2 starts at 5, ends at 8
Process 3 starts at 8, ends at 15

Shortest Job First Schedule:
Process 2 starts at 0, ends at 3
Process 1 starts at 3, ends at 8
Process 3 starts at 8, ends at 15

Round Robin Schedule:
Process 1 starts at 0, ends at 4
Process 2 starts at 4, ends at 7
Process 3 starts at 7, ends at 11
Process 1 starts at 11, ends at 12
Process 3 starts at 12, ends at 15

```
