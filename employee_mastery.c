#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_COURSE 100

// =========== 1. Employee (linked list) ===========

typedef struct Employee {
    int id;
    char name[MAX_NAME];
    char course[MAX_COURSE];
    int score;
    struct Employee* next;
} Employee;

Employee* empHead = NULL;

// Add employee (user‑only input)
void addEmp() {
    int id, score;
    char name[MAX_NAME], course[MAX_COURSE];

    printf("Enter employee ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter course: ");
    scanf(" %[^\n]", course);
    printf("Enter score (0-100): ");
    scanf("%d", &score);

    Employee* newEmp = (Employee*)malloc(sizeof(Employee));
    if (!newEmp) {
        printf("   Error: memory allocation failed.\n");
        return;
    }

    newEmp->id = id;
    strcpy(newEmp->name, name);
    strcpy(newEmp->course, course);
    newEmp->score = score;
    newEmp->next = empHead;
    empHead = newEmp;
    printf("   Employee with ID %d added.\n\n", id);
}

// View all employees (linked list)
void viewEmps() {
    printf("\nAll Employees (linked list view)\n");
    printf("================================\n");
    if (!empHead) {
        printf("   No employees.\n");
        return;
    }

    Employee* curr = empHead;
    while (curr) {
        printf("   ID: %d, Name: %s, Course: %s, Score: %d\n",
               curr->id, curr->name, curr->course, curr->score);
        curr = curr->next;
    }
}

// =========== 2. Stack from employee IDs ===========

typedef struct StackNode {
    int empId;
    struct StackNode* next;
} StackNode;

StackNode* stackTop = NULL;

void stackPush(int id) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) return;
    node->empId = id;
    node->next = stackTop;
    stackTop = node;
}

void printStack() {
    printf("\nStack representation (top to bottom):\n");
    if (!stackTop) {
        printf("   Stack is empty.\n");
        return;
    }

    StackNode* curr = stackTop;
    while (curr) {
        printf("   %d\n", curr->empId);
        curr = curr->next;
    }
}

// =========== 3. Queue from employee IDs ===========

typedef struct QueueNode {
    int empId;
    struct QueueNode* next;
} QueueNode;

QueueNode* qFront = NULL;
QueueNode* qRear = NULL;

void queueEnqueue(int id) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    if (!node) return;
    node->empId = id;
    node->next = NULL;

    if (!qFront) {
        qFront = qRear = node;
    } else {
        qRear->next = node;
        qRear = node;
    }
}

void printQueue() {
    printf("\nQueue representation (front to rear):\n");
    if (!qFront) {
        printf("   Queue is empty.\n");
        return;
    }

    QueueNode* curr = qFront;
    while (curr) {
        printf("   %d\n", curr->empId);
        curr = curr->next;
    }
}

// =========== 4. BST from employee IDs ===========

typedef struct BSTNode {
    int id;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* bstRoot = NULL;

BSTNode* bstInsert(BSTNode* root, int id) {
    if (!root) {
        BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
        if (!node) return NULL;
        node->id = id;
        node->left = node->right = NULL;
        return node;
    }

    if (id < root->id) {
        root->left = bstInsert(root->left, id);
    } else if (id > root->id) {
        root->right = bstInsert(root->right, id);
    }

    return root;
}

void printBSTInOrder(BSTNode* root) {
    if (root) {
        printBSTInOrder(root->left);
        printf("   %d\n", root->id);
        printBSTInOrder(root->right);
    }
}

void printBST() {
    printf("\nBST representation (in-order traversal):\n");
    if (!bstRoot) {
        printf("   BST is empty.\n");
        return;
    }
    printBSTInOrder(bstRoot);
}

// =========== 5. Build stack, queue, BST from current list ===========

void buildStructures() {
    // Clear old structures
    stackTop = NULL;
    qFront = qRear = NULL;
    bstRoot = NULL;

    // Rebuild from current employee list
    Employee* curr = empHead;
    while (curr) {
        stackPush(curr->id);
        queueEnqueue(curr->id);
        bstRoot = bstInsert(bstRoot, curr->id);
        curr = curr->next;
    }
}

// =========== 6. Main menu and infinite representation menu ===========

int main() {
    int choice;

    printf("Employee Training Mastery Platform (minimal)\n");
    printf("============================================\n");

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Show Data Structures Menu (stack/queue/BST/linked list)\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEmp();
            buildStructures();  // rebuild stack, queue, BST
            break;

        case 2:
            viewEmps();
            break;

        case 3:
            // Infinite data‑structure menu until user exits
            while (1) {
                printf("\nDATA STRUCTURE REPRESENTATIONS\n");
                printf("1. Stack (IDs)\n");
                printf("2. Queue (IDs)\n");
                printf("3. BST (sorted IDs)\n");
                printf("4. Linked List (same as View All Employees)\n");
                printf("5. Back to main menu\n");
                printf("Choose: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printStack();
                    break;
                case 2:
                    printQueue();
                    break;
                case 3:
                    printBST();
                    break;
                case 4:
                    viewEmps();
                    break;
                case 5:
                    printf("   Returning to main menu.\n");
                    break;
                default:
                    printf("   Invalid choice.\n");
                    continue;
                }

                if (choice == 5) break;  // exit inner (representation) loop
            }
            break;

        case 4:
            printf("   Exiting program.\n");
            return 0;

        default:
            printf("   Invalid choice. Please choose 1–4.\n");
        }
    }

    return 0;
}
