#include <stdio.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int size = 0;

void insert(int num) {
    if (size == MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    list[size] = num;
    size++;
}

void printList() {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a number to insert: ");
    scanf("%d", &num);
    insert(num);
    printList();
    return 0;
}
