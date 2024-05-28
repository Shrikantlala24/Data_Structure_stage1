#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = value;
    NewNode->next = NULL;
    return NewNode;
}

struct node* insert_Beg(struct node* head, int value) {
    struct node* NewNode = createNode(value);
    NewNode->next = head;
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

struct node* insert_After(struct node* head, int value, int target) {
    struct node* NewNode = createNode(value);
    struct node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            NewNode->next = current->next;
            current->next = NewNode;
            break;
        }
        current = current->next;
    }
    return head;
}

struct node* delete_First(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* delete_Last(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

struct node* delete_After(struct node* head, int target) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == target && current->next != NULL) {
            struct node* temp = current->next;
            current->next = temp->next;
            free(temp);
            break;
        }
        current = current->next;
    }
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
    int choice, value, target;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specified node\n");
        printf("4. Delete the first node\n");
        printf("5. Delete the last node\n");
        printf("6. Delete a node after a specified node\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insert_Beg(head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insert_End(head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target node value: ");
                scanf("%d", &target);
                head = insert_After(head, value, target);
                break;
            case 4:
                head = delete_First(head);
                break;
            case 5:
                head = delete_Last(head);
                break;
            case 6:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                head = delete_After(head, target);
                break;
            case 7:
                display(head);
                break;
        }
    } while (choice != 8);

    return 0;
}
