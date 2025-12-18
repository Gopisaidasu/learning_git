#include "calculator.h"

int add(double a, double b) {
    return (a + b);
}

double subtract(double a, double b) {
	if(a>b)
    		return (a - b);
	else
    		return (b - a);
}

double multiply(double a, double b) {
    		return (a*b);
}

double divide(double a, double b) {
   if (b == 0) return 0; 
   else if(a>b)
    	return (int)(a / b);
    else
	return (int)(b/a);

}
/* Modulo */
int modulo(int a, int b) {
    if (b == 0)
        return 0;
//    return ((unsigned int)a % b);
    return (a % b);
}
