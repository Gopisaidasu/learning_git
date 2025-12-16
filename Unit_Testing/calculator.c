/* calculator */
int add(int a, int b) {
    	return a + b;
}

int sub(int a, int b) {
	if(a>b)
    	    return (a - b);
	else
	    return (b - a);
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
     if (b == 0)
        return 0;   
    return a / b;

}
