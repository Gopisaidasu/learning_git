#include <stdio.h>
#include "String.h"

int main() {

    const char *s1;
    const char *s2;

    if (isEvenLength(s1)) {
        printf("%s has even length\n", s1);
    }

    if (!isEvenLength(s2)) {
        printf("%s has odd length\n", s2);
    }
	
}
