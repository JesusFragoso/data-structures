#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node *next_node;
};

struct List {
    struct Node *head;
};

void initialize_list(struct List **double_list_ptr);
void insert_element(struct List **double_list_ptr, int number);
void show_list_elements(struct List **double_list_ptr);

int main() {

    struct List *my_list;

    initialize_list(&my_list);

    insert_element(&my_list, 2);
    insert_element(&my_list, 1);
    insert_element(&my_list, 10);
    insert_element(&my_list, 8);
    insert_element(&my_list, 3);

    show_list_elements(&my_list);
    
    return 0;
}

void initialize_list(struct List **double_list_ptr) {
    (*double_list_ptr)->head = NULL;
}

void insert_element(struct List **double_list_ptr, int number) {
    
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    if ((*double_list_ptr)->head == NULL) {
        new_node->number = number;
        new_node->next_node = (*double_list_ptr)->head;
        
        (*double_list_ptr)->head = new_node;
    } 
    else {
        if ((*double_list_ptr)->head->number > number) {
            new_node->number = number;
            new_node->next_node = (*double_list_ptr)->head;
            (*double_list_ptr)->head = new_node;
            return;
        };

        struct Node *actual_node = (*double_list_ptr)->head;
        struct Node *previous_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->number = number;

        while(actual_node != NULL && (actual_node->number) < new_node->number) {
            previous_node = actual_node;
            actual_node = actual_node->next_node;
        };

        previous_node->next_node = new_node;
        new_node->next_node = actual_node;
    };
};

void show_list_elements(struct List **double_list_ptr) {
    struct Node *current_node = (*double_list_ptr)->head;

    while (current_node != NULL) {
        printf("The list inside the element is: %d\n\n", current_node->number);
        current_node = current_node->next_node;
    };
};