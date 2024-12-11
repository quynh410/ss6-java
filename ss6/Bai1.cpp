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

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Thêm phần tử vào ngăn xếp\n");
        printf("2. Hiển thị ngăn xếp\n");
        printf("3. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập phần tử: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                printf("\nCác phần tử trong ngăn xếp từ trên xuống dưới:\n");
                display(&stack);
                break;
            case 3:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 3);

    return 0;
}
