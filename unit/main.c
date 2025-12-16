#include <stdio.h>
#include "calculator.h"

int main() {
    char op;
    double num1, num2, result;

    // Ask user for input
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Perform operation
    switch (op) {
        case '+':
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0)
                result = divide(num1, num2);
            else {
                printf("Error! Division by zero.\n");
                return 1;
            }
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;

        default:
            printf("Error! Operator not recognized.\n");
            return 1;
    }

    return 0;
}
