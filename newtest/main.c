#include <stdio.h>
#include "calculator.h"

int main() {
    char op;
    int i1,i2,result;
    // Ask user for input
    printf("Enter an operator (%%,* ): ");
    scanf(" %c", &op);
    if (op == '%') {
        printf("Enter two integers: ");
        scanf("%d %d", &i1, &i2);

        result = modulo(i1, i2);
        printf("%d %% %d = %d\n", i1, i2, result);
}
else if(op=='*')
{
        printf("Enter two integers: ");
        scanf("%d %d", &i1, &i2);

        result = multiply(i1, i2);
        printf("%d * %d = %d\n", i1, i2, result);
}
    return 0;
}
