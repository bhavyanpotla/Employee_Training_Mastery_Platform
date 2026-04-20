#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_COURSE 100
#define DATA_FILE "training_data.dat"

// ======================================================
// 1. DATA STRUCTURE DEFINITIONS
// ======================================================

typedef struct Employee {
    int id;
    char name[MAX_NAME];
    char course[MAX_COURSE];
    int score;
    struct Employee* next;
} Employee;

typedef struct StackNode {
    int empId;
    struct StackNode* next;
} StackNode;

typedef struct QueueNode {
    int empId;
    struct QueueNode* next;
} QueueNode;

typedef struct BSTNode {
    int id;
    struct BSTNode *left, *right;
} BSTNode;

// Global Management Heads
Employee* empHead = NULL;
StackNode* stackTop = NULL;
QueueNode *qFront = NULL, *qRear = NULL;
BSTNode* bstRoot = NULL;

// ======================================================
// 2. UI & UTILITY FUNCTIONS
// ======================================================

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    printf("\n\tPress [Enter] to continue...");
    getchar(); getchar();
}

// ======================================================
// 3. MEMORY & HIERARCHY MANAGEMENT
// ======================================================

void freeBST(BSTNode* root) {
    if (root) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

void resetStructures() {
    while(stackTop) { StackNode* t = stackTop; stackTop = t->next; free(t); }
    while(qFront) { QueueNode* t = qFront; qFront = t->next; free(t); }
    qRear = NULL;
    freeBST(bstRoot);
    bstRoot = NULL;
}

BSTNode* bstInsert(BSTNode* root, int id) {
    if (!root) {
        BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
        node->id = id; node->left = node->right = NULL;
        return node;
    }
    if (id < root->id) root->left = bstInsert(root->left, id);
    else if (id > root->id) root->right = bstInsert(root->right, id);
    return root;
}

void buildStructures() {
    resetStructures();
    Employee* curr = empHead;
    while (curr) {
        StackNode* sn = (StackNode*)malloc(sizeof(StackNode));
        sn->empId = curr->id; sn->next = stackTop; stackTop = sn;

        QueueNode* qn = (QueueNode*)malloc(sizeof(QueueNode));
        qn->empId = curr->id; qn->next = NULL;
        if (!qFront) qFront = qRear = qn;
        else { qRear->next = qn; qRear = qn; }

        bstRoot = bstInsert(bstRoot, curr->id);
        curr = curr->next;
    }
}

// ======================================================
// 4. CORE FEATURES (CRUD & PERSISTENCE)
// ======================================================

void saveFile() {
    FILE* fp = fopen(DATA_FILE, "wb");
    if (!fp) return;
    Employee* curr = empHead;
    while (curr) {
        fwrite(curr, sizeof(Employee), 1, fp);
        curr = curr->next;
    }
    fclose(fp);
}

void loadFile() {
    FILE* fp = fopen(DATA_FILE, "rb");
    if (!fp) return;
    Employee temp;
    while (fread(&temp, sizeof(Employee), 1, fp)) {
        Employee* n = (Employee*)malloc(sizeof(Employee));
        *n = temp; n->next = empHead; empHead = n;
    }
    fclose(fp);
    buildStructures();
}

void addEmployee() {
    clearScreen();
    printf("\n\t[ ADD NEW RECORD ]\n");
    Employee* n = (Employee*)malloc(sizeof(Employee));
    printf("\tEnter ID: "); scanf("%d", &n->id);
    printf("\tEnter Name: "); scanf("%s", n->name);
    printf("\tEnter Course: "); scanf(" %[^\n]", n->course);
    printf("\tEnter Score: "); scanf("%d", &n->score);
    
    n->next = empHead;
    empHead = n;
    saveFile();
    buildStructures();
    printf("\n\t[Success] Entry created and structures updated.\n");
    pause();
}

void deleteEmployee() {
    clearScreen();
    int targetId;
    printf("\n\t[ DELETE RECORD ]\n");
    printf("\tEnter Employee ID to remove: ");
    scanf("%d", &targetId);

    Employee *curr = empHead, *prev = NULL;

    while (curr != NULL && curr->id != targetId) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("\n\t[Error] Employee with ID %d not found.\n", targetId);
    } else {
        if (prev == NULL) empHead = curr->next;
        else prev->next = curr->next;
        
        free(curr);
        saveFile();
        buildStructures();
        printf("\n\t[Success] Employee %d deleted. Memory freed.\n", targetId);
    }
    pause();
}

// ======================================================
// 5. VISUALIZATION LAB (ALL DATA STRUCTURES)
// ======================================================

void visualizeLinkedList() {
    clearScreen();
    printf("\n\t[ LINKED LIST: PHYSICAL NODE CHAIN ]\n\n\t");
    Employee* curr = empHead;
    if (!curr) printf("[ EMPTY ]");
    else {
        while (curr) {
            printf("[ID:%d|%s]", curr->id, curr->name);
            if (curr->next) printf(" ---> ");
            else printf(" ---> NULL");
            curr = curr->next;
        }
    }
    printf("\n\n\t[ TABULAR VIEW ]\n\t------------------------------------------------------------\n");
    printf("\t%-10s | %-15s | %-20s | %-5s\n", "ID", "Name", "Course", "Score");
    printf("\t------------------------------------------------------------\n");
    curr = empHead;
    while(curr) {
        printf("\t%-10d | %-15s | %-20s | %-5d\n", curr->id, curr->name, curr->course, curr->score);
        curr = curr->next;
    }
    pause();
}

void visualizeStack() {
    clearScreen();
    printf("\n\t[ STACK: LIFO BUCKET ]\n\n");
    StackNode* curr = stackTop;
    if (!curr) printf("\t|  EMPTY  |\n");
    else {
        printf("\t   |  TOP  |\n");
        while (curr) {
            printf("\t   |-------|\n\t   |  %3d  |\n", curr->empId);
            curr = curr->next;
        }
        printf("\t   |_______|\n\t    (BASE)\n");
    }
    pause();
}

void visualizeQueue() {
    clearScreen();
    printf("\n\t[ QUEUE: FIFO PIPE ]\n\n\t(EXIT) ");
    QueueNode* curr = qFront;
    if (!curr) printf("[ EMPTY ]");
    else {
        while (curr) {
            printf("[%d]", curr->empId);
            if (curr->next) printf(" <--- ");
            curr = curr->next;
        }
        printf(" (ENTRY)\n");
    }
    pause();
}

void drawBST(BSTNode* root, int space) {
    if (root == NULL) return;
    space += 8;
    drawBST(root->right, space);
    printf("\n");
    for (int i = 8; i < space; i++) printf(" ");
    printf("[%d]\n", root->id);
    drawBST(root->left, space);
}

void visualizeBST() {
    clearScreen();
    printf("\n\t[ BST: HIERARCHY TREE ]\n\n");
    if (!bstRoot) printf("\t[ EMPTY ]\n");
    else drawBST(bstRoot, 0);
    pause();
}

void dsMenu() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n\t*********************************************\n");
        printf("\t* DATA STRUCTURE REPRESENTATION MENU        *\n");
        printf("\t*********************************************\n");
        printf("\t 1. Linked List (Chain & Table)\n");
        printf("\t 2. Stack (Vertical Visual)\n");
        printf("\t 3. Queue (Horizontal Flow Visual)\n");
        printf("\t 4. BST   (Tree Map Visual)\n");
        printf("\t 5. Back to Main Menu\n");
        printf("\t*********************************************\n");
        printf("\t Selection: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch(choice) {
            case 1: visualizeLinkedList(); break;
            case 2: visualizeStack(); break;
            case 3: visualizeQueue(); break;
            case 4: visualizeBST(); break;
        }
    }
}

// ======================================================
// 6. MAIN SYSTEM
// ======================================================

int main() {
    loadFile();
    int choice;
    while (1) {
        clearScreen();
        printf("\n\t================================================\n");
        printf("\t       EMPLOYEE TRAINING MASTERY PLATFORM       \n");
        printf("\t================================================\n");
        printf("\t 1. Register Employee\n");
        printf("\t 2. View Registry (Linked List Table)\n");
        printf("\t 3. Data Structure Visualizations\n");
        printf("\t 4. Delete Employee Record\n");
        printf("\t 5. Exit System\n");
        printf("\t------------------------------------------------\n");
        printf("\t Choice > ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // Clear buffer on bad input
            continue;
        }
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: visualizeLinkedList(); break;
            case 3: dsMenu(); break;
            case 4: deleteEmployee(); break;
            case 5: saveFile(); exit(0);
        }
    }
    return 0;
}