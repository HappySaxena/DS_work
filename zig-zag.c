#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure for level order traversal
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

// Queue implementation
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a node
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a node
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return node;
}

// Function to check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to print zigzag level order traversal
void zigzagLevelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);
    int leftToRight = 1;

    while (!isEmpty(queue)) {
        int size = 0;
        struct QueueNode* temp = queue->front;
        
        // Count nodes in the current level
        while (temp) {
            size++;
            temp = temp->next;
        }

        int* levelNodes = (int*)malloc(size * sizeof(int));
        int i;
        for (i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(queue);
            int index = leftToRight ? i : (size - 1 - i);
            levelNodes[index] = node->val;

            if (node->left)
                enqueue(queue, node->left);
            if (node->right)
                enqueue(queue, node->right);
        }

        // Print the level
        for (i = 0; i < size; i++) {
            printf("%d ", levelNodes[i]);
        }
        printf("\n");

        free(levelNodes);
        leftToRight = !leftToRight;
    }

    free(queue);
}

// Driver code
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Zigzag Level Order Traversal:\n");
    zigzagLevelOrder(root);

    return 0;
}