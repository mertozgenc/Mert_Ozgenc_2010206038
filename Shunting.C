#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack tanımı
char stack[MAX];
int top = -1;

// Stack fonksiyonları
void push(char c) {
    if (top == MAX - 1)
        return;
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Operatör önceliği
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    char ch;

    printf("Infix ifadeyi girin: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // Operand ise postfix'e ekle
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // '(' ise stack'e at
        else if (ch == '(') {
            push(ch);
        }
        // ')' ise '(' görünceye kadar pop et
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // '(' sil
        }
        // Operatör ise
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Stack'te kalanları postfix'e ekle
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix ifade: %s\n", postfix);

    return 0;
}
