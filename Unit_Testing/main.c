#include<stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int a, b;
    char op;

    printf("Enter operation (+ - *): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (op == '+') 
	    printf("Result = %d\n", add(a, b));
    else if (op == '-') 
	    printf("Result = %d\n", sub(a, b));
    else if (op == '*') 
	    printf("Result = %d\n", mul(a, b));
    else if (op == '/') 
	    printf("Result = %d\n", div(a, b));
    else
        printf("Invalid operation\n");
    return 0;
}

