#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Structure for Queue Node
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue structure for level-order traversal
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a tree node
void enqueue(struct Queue* queue, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue a tree node
struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) return NULL;
    struct QueueNode* temp = queue->front;
    struct Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return treeNode;
}

// Function to find the largest value in each level of the binary tree
void findLargestInEachLevel(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        int levelSize = 0;
        struct QueueNode* temp = queue->front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }

        int maxVal = INT_MIN;
        for (int i = 0; i < levelSize; i++) {
            struct Node* current = dequeue(queue);
            if (current->data > maxVal)
                maxVal = current->data;
            
            if (current->left)
                enqueue(queue, current->left);
            if (current->right)
                enqueue(queue, current->right);
        }

        printf("%d ", maxVal);
    }
}

// Main function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(9);
    root->right->left = newNode(7);
    root->left->right->left = newNode(6);

    printf("Largest values in each level: ");
    findLargestInEachLevel(root);

    return 0;
}