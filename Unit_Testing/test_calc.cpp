#include <assert.h>

int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );

int main() {
    /* Test addition */
    assert(add(2, 3) == 5);
    assert(add(0, 0) == 0);

    /* Test subtraction */
    assert(sub(5, 3) == 2);
    assert(sub(3, 5) == 2);

    /* Test multiplication */
    assert(mul(4, 3) == 12);
    assert(mul(0, 5) == 0);

    /* Test Division */
    assert(div(10, 2) == 5);
    assert(div(10, 0) == 0);
    return 0; 
}

