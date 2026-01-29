#include "calculator.h"
#include<stdexcept>
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
/* division */
int divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("divide by zero");
    return a / b;
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


