#include "calculator.h"
#include<iostream>
/* Addition: return value is int instead of double */
int add(double a, double b) {
    return (a + b);
}

/* Subtraction: Changing subtraction*/
double subtract(double a, double b) {
	if(a>b)
    		return (a - b);
	else
    		return (b - a);
		
//	return a-b;
}

/* Multiplication */
double multiply(double a, double b) {
    		return (int)(a*b);
}

/* Division: Returning int and changing division */
double divide(double a, double b) {
   if (b == 0) throw std::runtime_error("Divide by zero"); 
   else if(a>b)
    	return (int)(a / b);
    else
	return (int)(b/a);
    
/*   if (b == 0) return 0; 
   else
	return a/b;
   	
*/
}
/* Modulo */
int modulo(int a, int b) {
    if (b == 0)
        return 0;
    return ((unsigned int)a % b);
//    return (a % b);
}
