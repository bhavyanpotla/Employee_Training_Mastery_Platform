
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

## 📊 Sample Output Screenshots
```
<img width="694" height="344" alt="image" src="https://github.com/user-attachments/assets/d89f7977-0de0-4286-a647-a6e8d4839909" />

<img width="664" height="314" alt="image" src="https://github.com/user-attachments/assets/a82fba4f-d089-46dc-a9ce-c7a12a3abfed" />

<img width="875" height="430" alt="image" src="https://github.com/user-attachments/assets/d03a2afc-b78f-4168-80de-cc52c31ebcb1" />

<img width="650" height="344" alt="image" src="https://github.com/user-attachments/assets/63e9ffef-3af6-47fa-89fd-fbb5a165aa4f" />

<img width="1480" height="165" alt="image" src="https://github.com/user-attachments/assets/51dbd34e-0a57-4c48-980d-e9d9c52f641c" />

<img width="467" height="647" alt="image" src="https://github.com/user-attachments/assets/4e41eb37-6832-4037-b748-d8f37aff9ad2" />

<img width="1151" height="212" alt="image" src="https://github.com/user-attachments/assets/02c08001-a639-4b4d-b9c5-bb1d1434dcb4" />
        
<img width="593" height="549" alt="image" src="https://github.com/user-attachments/assets/8a6c801a-6fe7-449a-ac87-0ad077ff8844" />
    
<img width="660" height="244" alt="image" src="https://github.com/user-attachments/assets/0bc7d6e8-069a-428f-bc35-26192b53b0ca" />

<img width="870" height="373" alt="image" src="https://github.com/user-attachments/assets/774f04c7-40de-41aa-b79f-4da112af45a9" />
        
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
