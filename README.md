
# 🛡️ Employee Training Mastery Platform (ETMP)
**An Enterprise-Grade C Implementation of Multi-Structural Data Management**

An advanced C-based **Data Management Engine** that orchestrates **Multiple Data Structures** over a **single persistent data layer**. This platform manages employee records with real-time visual mapping across linear and non-linear architectures.

## 👥 Team Information
| **Member** | **Name** | **Institution** |
|------------|----------|-----------------|
| Member 1 | Bhavyan Naidu | B.Tech 2nd Sem, Sai University |
| Member 2 | Deepak Reddy | B.Tech 2nd Sem, Sai University |

## 📝 Problem Statement
In corporate training environments, tracking employee progress across various courses requires a system that is both **persistent** and capable of representing data in **multiple logical formats** (chronological entry, priority stacks, sorted hierarchies). This project delivers a **unified management system** implementing full **CRUD operations** using C with binary persistence for data integrity.

## 🏗️ Data Structures Used
1. **Singly Linked List** - Primary "Master Registry" for dynamic storage
2. **Stack (LIFO)** - Recent training activity visualization
3. **Queue (FIFO)** - "First-Come, First-Served" training queue
4. **Binary Search Tree (BST)** - Sorted hierarchical employee ID organization

## 🚀 Key Technical Features
1. **Dual-Layer Persistence**
   - **Serialized Storage**: Records saved in compact binary format (`.dat`)
   - **Automatic Hydration**: `loadFile()` reads binary stream and rebuilds structures

2. **Multi-Structural Synchronization Engine**
   - **Single Source of Truth (SSOT)**: Singly Linked List as primary database
   - **Shadow Views**: `buildStructures()` synchronizes Stack, Queue, and BST

3. **Advanced Visualization Suite**
   - **Recursive Tree Mapping**: 2D recursion renders BST hierarchy
   - **Buffer-Safe UI**: Custom `clearScreen()` + input buffer handling

## 🛠️ Algorithm Explanation
**Synchronized Structural Update Algorithm:**
1. **Node Creation**: `malloc()` allocates Employee struct, prepends to Linked List
2. **Persistence**: `saveFile()` writes memory block to `training_data.dat`
3. **Rebuild Logic**: `buildStructures()` clears (iterative/recursive freeBST) then repopulates all views via single Linked List traversal
4. **Deletion**: Pointer-redirection unlinks target ID node and `free()`

## 📊 Core DSA Concepts Implemented
| **Concept** | **Implementation** | **Educational Value** |
|-------------|-------------------|----------------------|
| **Singly Linked List** | Employee nodes with `next` pointers | Dynamic memory & traversal |
| **LIFO (Stack)** | `StackNode` top-insertion | Push-down storage |
| **FIFO (Queue)** | `QueueNode` Front/Rear pointers | Flow control |
| **Binary Search Tree** | `BSTNode` recursive `bstInsert` | \(O(\log n)\) hierarchy |
| **Persistence** | `fread()`/`fwrite()` struct blocks | Physical vs. virtual storage |

## 🏗️ System Architecture & Memory Flow
```
Add Employee Command Flow:
┌─────────────────┐    ┌──────────────────┐    ┌──────────────────┐
│ 1. malloc()     │───▶│ 2. Pointer Link  │───▶│ 3. File Sync     │
│ New Employee    │    │ empHead Chain    │    │ training_data.dat│
└─────────────────┘    └──────────────────┘    └──────────────────┘
                                                          │
                                                          ▼
┌──────────────────┐    ┌──────────────────┐    ┌──────────────────┐
│ 4a. Stack Push   │    │ 4b. Queue Enqueue│    │ 4c. BST Insert   │
│ Recent Activity  │    │ Processing Order │    │ Search Hierarchy │
└──────────────────┘    └──────────────────┘    └──────────────────┘
```

## ✅ Implementation Requirements Checklist
- ✅ **C Language Only**
- ✅ **Use of struct**
- ✅ **Dynamic Memory Allocation** (`malloc`, `free`)
- ✅ **Modular Programming** (Functions)
- ✅ **Menu-driven Interface**
- ✅ **CRUD Operations** (Add, Display, Delete)

## 🛠️ Compilation & Usage
### Prerequisites
- C compiler (GCC, Clang, or MSVC)

```bash
# Compile
gcc main.c -o training_platform

# Run
./training_platform
```

## 📊 Sample Output
```
[ ADD NEW RECORD ]
Enter ID: 101
Enter Name: Bhavyan
Enter Course: Data_Structures
Enter Score: 95

[Success] Entry created and structures updated.

[ BST: HIERARCHY TREE ]
        
    
        
```

## 🧪 Evaluation Points (For Evaluators)
- **Memory Leak Prevention**: `resetStructures()` frees before rebuilds
- **Recursive Logic**: BST visualization depth-tracking recursion
- **Data Integrity**: Binary mode preserves struct padding

## 🚀 Proposed Optimizations
1. **Search**: BST-based `deleteEmployee` (\(O(\log n)\))
2. **Sort**: Merge Sort Linked List by Score
3. **Generic**: `void*` pointers for Stack/Queue

## 🔗 Project Links
- **Demo Video**: [Google Drive Link - Restricted Access]
- **Project Report**: [docs/project_report.pdf]
- **Presentation**: [ppt/presentation.pptx]

## 📁 Repository Structure
```
project-name/
├── src/
│   └── main.c           # Full CRUD logic
├── docs/
│   └── project_report.pdf
├── ppt/
│   └── presentation.pptx
├── README.md
└── sample_output.txt
```

---
