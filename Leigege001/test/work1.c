#include <stdio.h>
#include <assert.h>

#define MAX_LEN 10000

int q[MAX_LEN], head, tail;

void init() {
    head = 0;
    tail = -1;
}

void push(int element) {
    assert(tail + 1 < length);
    tail++;
    q[tail] = element;
}
void output() {
    for (int i = head; i <= tail; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}
int front() {
    assert(head <= tail);
    return q[head];
}
void pop() {
    assert(head <= tail);
    head++;
}

int main() {
    init();
    for (int i = 1; i <= 10; i++) {
        push(i);
    }
    output();
    printf("%d\n", front());
    pop();
    output();
    return 0;
}
