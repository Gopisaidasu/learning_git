#include "calculator.h"
/* Modulo */
int modulo(int a, int b) {
    if (b == 0)
        return 0;
    return ((unsigned int)a % b);
//    return (a % b);
}

/* Description function */
const char* description(void)
{
	return "MongoDB  web scale";
}

/* Multiplication: Changing whole multipication */
 int multiply(int a, int b)
{
    return a + b;
}


