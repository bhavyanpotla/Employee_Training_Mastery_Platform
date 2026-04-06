# Employee_Training_Mastery_Platform
# Employee Training Mastery Platform (Minimal C Version)

A minimal, console-based C program that manages employee training records and lets you explore their data through multiple **data structure representations**: linked list, stack, queue, and binary search tree (BST).

## 🎯 Academic Purpose and Learning Objectives

This program is designed as an **educational project** to help students:

- Understand **CRUD operations (Create, Read, Update, Delete)** in C without using a database.
- Implement and visualize **linear data structures**:
  - Linked list (employee records),
  - Stack (LIFO, IDs),
  - Queue (FIFO, training waiting list).
- Implement and traverse a **non‑linear data structure**:
  - Binary Search Tree (BST) for sorted IDs.
- Practice **menu‑driven, interactive programming** in C using only `stdio.h`.
- Develop problem‑solving skills for:
  - Dynamic memory management (`malloc`),
  - Pointer manipulation,
  - Menu loops and nested control flow.

It is suitable for **DSA (Data Structures and Algorithms)** labs, assignments, and mini‑projects in undergraduate computer science courses.

---

## 📋 Core Features (From User Perspective)

- **Add Employee**
  - Input: ID, name, course, score (via terminal only).
- **View All Employees**
  - Displays all records as a **linked‑list view** (no hardcoded data).
- **Data Structures Representation Menu (Infinite Loop)**:
  - Stack: view IDs in **LIFO order** (top to bottom).
  - Queue: view IDs in **FIFO order** (front to rear).
  - BST: view IDs in **sorted order** (in‑order traversal).
  - Linked List: same as “View All Employees” (for comparison).
- Simple **text‑only interface** without emojis or special characters.

---

## 🖥️ How to Run

1. Save the code in a file named `employee_platform.c`.
2. Compile it with GCC:

   ```bash
   gcc employee_platform.c -o employee_platform
   ```

3. Run the program:

   ```bash
   ./employee_platform
   ```

4. Follow the menus:
   - Press `1` to **Add Employee** (ID, name, course, score).
   - Press `2` to **View All Employees** (linked‑list display).
   - Press `3` to enter the **Data Structures Menu**:
     - `1` – Stack representation (IDs, top to bottom)
     - `2` – Queue representation (IDs, front to rear)
     - `3` – BST representation (sorted IDs, in‑order)
     - `4` – Linked‑list view (same as “View All Employees”)
     - `5` – Back to main menu
   - Press `4` in the main menu to **Exit**.

There is **no file saving** in this version; all data resides in memory only.

---

## 📦 Project Structure

- `employee_platform.c` – main C file containing:
  - `struct Employee` linked list (core CRUD data).
  - Functions for:
    - `addEmp()` – create new employee,
    - `viewEmps()` – read all employees.
  - `struct StackNode` and stack functions (`stackPush`, `printStack`).
  - `struct QueueNode` and queue functions (`queueEnqueue`, `printQueue`).
  - `struct BSTNode` and BST functions (`bstInsert`, `printBSTInOrder`, `printBST`).
  - `buildStructures()` – rebuilds stack, queue, and BST from the current employee list.
  - Main menu loop and nested **infinite data‑structure menu**.

---

## 🧩 Technology Stack and Concepts

- **Language**: C (standard `stdio.h`, `stdlib.h`, `string.h`).
- **Input/Output**: `printf` and `scanf` only (no GUI, no external libraries).
- **Data Structures**:
  - **Linked List**: employee records (singly linked).
  - **Stack**: LIFO sequence of employee IDs (linked‑list based).
  - **Queue**: FIFO sequence of employee IDs (linked‑list based).
  - **Binary Search Tree (BST)**: sorted structure of IDs (used for efficient ordering and searching in extension).
- **Key C Concepts**:
  - Pointers and pointer arithmetic.
  - Dynamic memory allocation with `malloc`.
  - Linked‑list node insertion and traversal.
  - Recursive BST traversal (in‑order).
  - Menu‑driven, infinite loop handling (`while(1)` loops and `break` conditions).

---

## 🧠 Educational Use‑Cases

This project is useful for:

- **Labs in Data Structures & C Programming**
  - Students can modify operations:
    - Add **Delete** or **Update** in the main menu,
    - Extend `viewEmps()` into a **search‑by‑ID** function,
    - Add **sorting by score** or **filter by course**.
- **DSA Assignments**
  - Implement **queue/stack/BST operations** with real data (employee IDs).
  - Compare **time complexity** of:
    - Search in linked list: \(O(n)\),
    - Search in BST: \(O(\log n)\) on average.
- **Mini‑Project for Semesters**
  - Base project for building a **full employee training system** (add groups, certifications, attendance, etc.).

---

## 🚀 Interesting Side Topics (For Future Extensions)

### 1. File‑based Persistence
- Save/load employees to a text file:
  - Each line: `ID, Name, Course, Score`.
- Use `fopen`, `fprintf`, and `fscanf` to persist data between runs.

### 2. Performance Comparison
- Measure traversal time for:
  - Linked list (all employees),
  - BST (sorted IDs),
  - Stack and queue (ID sequences).
- Observe how **BST** gives faster access to ordered data vs linked list.

### 3. Advanced CRUD Features
- Add:
  - `searchById(int id)`: find and display an employee.
  - `updateById(int id)`: change name, course, or score.
  - `deleteById(int id)`: remove an employee and rebuild all structures.

### 4. Graph of Training Relationships
- Build a simple graph where:
  - Nodes = employees,
  - Edges = “X trains Y” relations.
- Use adjacency matrix or list to store and display training dependencies.

---

## 📚 Academic Notes

- This program emphasizes **implementation over abstraction**, suitable for **beginner to intermediate C/DSA students**.
- The **infinite inner menu** for data‑structure representations helps learners:
  - Switch between visualizations without restarting the program.
  - Reinforce understanding of how the **same data** can be organized differently.
- It follows **modular structure**:
  - Each data structure has its own node type and print function.
  - The `buildStructures()` function keeps all views in sync with the current employee list.

---

## Authors : Bhavyan Naidu | Deepak Reddy
