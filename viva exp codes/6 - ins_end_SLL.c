#include <stdio.h>
#include <stdlib.h>

 struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* NewNode = malloc(sizeof(struct node));
    NewNode->data = value;
    NewNode->next = NULL;
    return NewNode;
}

struct node* insert_End(struct node* head, int value) {
    struct node* NewNode = createNode(value);
    if (head == NULL) {
        return NewNode;
    }
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = NewNode;
    return head;
}

void display(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. display all the elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insert_End(head, value);
                break;
            case 2:
                display(head);
                break;
    }
    }  while (choice != 3);

    return 0;
}