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

### **1. Main Menu Interface**
### Clean console menu showing all CRUD operations (1-Add, 2-Display List, 3-Structures Menu, 4-Exit) with professional borders and clear numbering.
![Main Menu](https://github.com/user-attachments/assets/d89f7977-0de0-4286-a647-a6e8d4839909) 
 

### **2. Add Employee Screen**
### Employee input form collecting ID, Name, Course Name, and Training Score with input validation and confirmation prompt.
![Add Employee](https://github.com/user-attachments/assets/a82fba4f-d089-46dc-a9ce-c7a12a3abfed) 
 

### **3. Tabular View Registry**
### Complete employee registry in tabular format showing ID, Name, Course, and Score for all stored records from linked list master database.
![BST Tree](https://github.com/user-attachments/assets/d03a2afc-b78f-4168-80de-cc52c31ebcb1)


### **4. Data Structure Representation Menu**
### Secondary menu for viewing data through different structures (1-Stack, 2-Queue, 3-BST, 4-Back) demonstrating multi-view architecture.
![Stack View](https://github.com/user-attachments/assets/63e9ffef-3af6-47fa-89fd-fbb5a165aa4f) 
 

### **5. Linked List Vew**
### Forward traversal of master singly linked list showing complete employee records in chronological insertion order.
![Queue View](https://github.com/user-attachments/assets/51dbd34e-0a57-4c48-980d-e9d9c52f641c) 


### **6.  Stack (LIFO) Display**
### LIFO stack visualization showing most recent employees at top (reverse chronological order) with clear stack formatting.
![Delete Employee](https://github.com/user-attachments/assets/4e41eb37-6832-4037-b748-d8f37aff9ad2) 


### **7. Queue (FIFO) View**
### FIFO queue showing processing order (first-come-first-served) from front to rear pointer traversal.
<img width="1151" height="212" alt="image" src="https://github.com/user-attachments/assets/6ff45b76-b433-4f6c-99ea-9405c8c06c04" />
 

### **8.  BST Tree Visualization**
### Binary Search Tree hierarchy rendered with recursive indentation showing sorted employee IDs in in-order traversal.
![File Operations](https://github.com/user-attachments/assets/8a6c801a-6fe7-449a-ac87-0ad077ff8844) 
 

### **9. Delete Employee Operation**
### Employee deletion by ID with confirmation, successful removal message, and updated record count display.
![Search Results](https://github.com/user-attachments/assets/0bc7d6e8-069a-428f-bc35-26192b53b0ca) 


### **10. RE-VISIT Registry**
### Program restart showing successful file load from training_data.dat with all previous records automatically restored.
![Full Demo](https://github.com/user-attachments/assets/774f04c7-40de-41aa-b79f-4da112af45a9) 
 

## 🧪 Evaluation Points (For Evaluators)
- **Memory Leak Prevention**: `resetStructures()` frees before rebuilds
- **Recursive Logic**: BST visualization depth-tracking recursion
- **Data Integrity**: Binary mode preserves struct padding

## 🚀 Proposed Optimizations
1. **Search**: BST-based `deleteEmployee` (\(O(\log n)\))
2. **Sort**: Merge Sort Linked List by Score
3. **Generic**: `void*` pointers for Stack/Queue

## 🔗 Project Links
- **Demo Video**: [https://drive.google.com/file/d/1Hbt-YsjRjVAEU-vnRVprAtlYrEcLGKqC/view?usp=sharing]
- **Project Report**: [https://docs.google.com/document/d/1teE1_fbL5vXUR3kveKzuXCrVpyuw_-3w/edit?usp=sharing&ouid=104059422446434721101&rtpof=true&sd=true]
- **Presentation**: [https://docs.google.com/presentation/d/1I3-bIHyoqhZ_Us0m2epYE_GNDNbJUEYy/edit?usp=sharing&ouid=104059422446434721101&rtpof=true&sd=true]

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
