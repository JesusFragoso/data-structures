#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next_node;
};

struct Stack {
    struct Node *node;
};

void initialize_stack(struct Stack **double_stack_ptr);
void push(struct Stack **double_stack_ptr, int data);
int pop(struct Stack **double_stack_ptr);

int main() {

    struct Stack *my_stack;

    initialize_stack(&my_stack);

    for (int i=1; i<=10; i++) {
        push(&my_stack, i);
    };

    int data_returned;

    for (int i=0; i<=10; i++) {
        data_returned = pop(&my_stack);
        printf("The data returned is: %d\n", data_returned);
    };

    if (data_returned == 0) {
        printf("\n\nThe stack is empty! ⭕️ \n\n");
    };

    return 0;
};  

void initialize_stack(struct Stack **double_stack_ptr) {
    (*double_stack_ptr)->node = NULL;
};

void push(struct Stack **double_stack_ptr, int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data = data;
    
    if ((*double_stack_ptr)->node == NULL) {
        new_node->next_node = NULL;
    }
    else {
        new_node->next_node = (*double_stack_ptr)->node;
    }

    (*double_stack_ptr)->node = new_node;
};

int pop(struct Stack **double_stack_ptr) {
    struct Node* aux_node_ptr = (struct Node*) malloc(sizeof(struct Node));

    if((*double_stack_ptr)->node == NULL) {
        return 0;
    }
    
    int data_to_return = (*double_stack_ptr)->node->data;
    
    aux_node_ptr = (*double_stack_ptr)->node;
    (*double_stack_ptr)->node = (*double_stack_ptr)->node->next_node;
    
    free(aux_node_ptr);
    
    return data_to_return;
};