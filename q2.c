#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    if (rear == MAX_SIZE) {
        printf("Queue overflow\n");
        return;
    }
    queue[rear++] = node;
}


struct Node* dequeue() {
    if (front == rear) {
        return NULL; 
    }
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int count = rear - front;

        printf("[");
        for (int i = 0; i < count; i++) {
            struct Node* curr = dequeue();
            printf("%d", curr->data);
            if (i != count - 1) printf(", ");

            if (curr->left != NULL) enqueue(curr->left);
            if (curr->right != NULL) enqueue(curr->right);
        }
        printf("]\n");
    }
}

int main() {
   
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Level order traversal:\n");
    levelOrderTraversal(root);

    return 0;
}
