#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Traversing in In-order
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, value;
    
    do {
        printf("\nBinary Search Tree Operations:");
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 7);

    return 0;
}