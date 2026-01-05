#include "String.h"
#include <stddef.h>
bool isEvenLength(const char *str)
{
    int length = 0;

    if (str == NULL)
        return false;

    while (str[length] != '\0') {
        length++;
    }

    return (length % 2) == 0;
}

