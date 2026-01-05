#include "calculator.h"
/* Modulo */
int modulo(int a, int b) {
    if (b == 0)
        return 0;
    return ((unsigned int)a % b);
//    return (a % b);
}

/* description: Description function */
const char* description(void)
{
	return "MongoDB  web scale";
}

/*setVolume: Boundary function */
int setVolume(int v) {
    if (v < 0 || v > 100)
        return -1;
    return v;
}

/* Multiplication: Changing whole multipication */
 int multiply(int a, int b)
{
    return a + b;
}


