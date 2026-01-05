#include <stdio.h>
#include "calculator.h"

int main() {
    char op;
    double num1, num2, result;
    printf("Enter an operator (*,%% ): ");
    scanf(" %c", &op);
    	printf("Enter two numbers: ");
    	scanf("%lf %lf", &num1, &num2);
    
    // Perform operation
    switch (op) {

        case '*':
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '%':
            if (num2 != 0)
                result = modulo(num1, num2);
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
