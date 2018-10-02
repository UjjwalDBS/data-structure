#include <stdio.h>
#include <stdlib.h>

int *stack, size, top = -1;
void Push (int data) {
  if (top == size - 1) {
    printf("Stack Overflow!\n");
    return;
  }
  stack[++top] = data;
}
void Pop () {
  if (top < 0) {
    printf("Stack Underflow!\n");
    return;
  }
  printf("%d popped\n", stack[top--]);
}
void Peek ()  {
  if (top < 0) {
    printf("Stack is Empty!\n");
    return;
  }
  printf("%d\n", stack[top]); 
}
void Display () {
  if (top < 0) {
    printf("Stack is Empty!\n");
    return;
  }
  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}
int main() {
  printf("Enter the size of the stack : ");
  scanf ("%d", &size);
  stack = (int*) malloc (size * sizeof(int));
  while (1) {
    int choice, data;
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the data to Push : ");
        scanf ("%d", &data);
        Push(data);
        break;
      case 2:
        Pop();
        break;
      case 3:
        Peek();
        break;
      case 4:
        Display();
        break;
      default :
        return 0;
    }
  }
}