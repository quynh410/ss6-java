#include<stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full, cannot add more elements.\n");
    } else {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop elements.\n");
        return -1; // Return an invalid value to indicate an error
    } else {
        return s->data[(s->top)--];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int num_elements;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &num_elements);

    if (num_elements > MAX_SIZE) {
        printf("Không thể thêm quá %d phần tử vào ngăn xếp.\n", MAX_SIZE);
    } else if (num_elements == 0) {
        printf("Ngăn xếp rỗng\n");
    } else {
        printf("Nhập các phần tử:\n");
        for (int i = 0; i < num_elements; i++) {
            int element;
            scanf("%d", &element);
            push(&stack, element);
        }

        if (isEmpty(&stack)) {
            printf("Ngăn xếp rỗng\n");
        } else {
            printf("Ngăn xếp không rỗng\n");
        }
    }

    return 0;
}
