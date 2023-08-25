#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node *next_node;
};

struct Queue {
    struct Node *first_node;
    struct Node *last_node;
};

void initialize_queue(struct Queue **double_ptr_queue);

void push(struct Queue **double_ptr_queue, int number);

int pop(struct Queue **double_ptr_queue);

int main() {

    struct Queue *my_queue;

    initialize_queue(&my_queue);

    push(&my_queue, 1);
    push(&my_queue, 2);
    push(&my_queue, 3);

    int data_returned;

    while (my_queue->first_node != NULL) {
        data_returned = pop(&my_queue);
        printf("\nThe data returned is: %d\n\n", data_returned);
    };

    return 0;
};

void initialize_queue(struct Queue **double_ptr_queue) {
    (*double_ptr_queue)->first_node = NULL;
    (*double_ptr_queue)->last_node = NULL;
};

void push(struct Queue **double_ptr_queue, int number) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->number = number;
    new_node->next_node = NULL;

    if ((*double_ptr_queue)->first_node == NULL && (*double_ptr_queue)->last_node == NULL) {
        (*double_ptr_queue)->first_node = new_node;
        (*double_ptr_queue)->last_node = new_node;
    }
    else {
        //* Replace the NULL value of the "next_node" field that the actual "last_node" is pointing to,
        //* with the value of the new node created.
        (*double_ptr_queue)->last_node->next_node = new_node;
        (*double_ptr_queue)->last_node = new_node;
    };
};

int pop(struct Queue **double_ptr_queue) {
    int number;
    struct Node *aux_node;

    //* Condition to be met if both of the nodes of the queue point to NULL. 
    if ((*double_ptr_queue)->first_node == NULL && (*double_ptr_queue)->last_node == NULL) {
        return -1;
    } 
    else if ((*double_ptr_queue)->first_node == (*double_ptr_queue)->last_node) {
        aux_node = (*double_ptr_queue)->first_node;
        
        (*double_ptr_queue)->first_node = NULL;
        (*double_ptr_queue)->last_node = NULL;
    }
    else {
        aux_node = (*double_ptr_queue)->first_node;
        (*double_ptr_queue)->first_node = (*double_ptr_queue)->first_node->next_node;
    };
    
    number = aux_node->number;
    free(aux_node);

    return number;
};