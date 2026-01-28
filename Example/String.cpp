#include "String.h"
#include<stddef.h>
#include<string.h>
#include<stdexcept>
#define TEMP_THRESHOLD 30


/* isEvenLength: Check characters in string are even numbered or odd*/
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

/* isEqual: Checking two strings are equal or not*/
int isEqual(const char *str1, const char *str2)
{
    if (!str1 || !str2)
        return -1;

    return (strcmp(str1, str2) == 0);
}
/* isLength: checking length */
int isLength(const char*str1)
{
	if(!str1 || str1[0] == '\0')
		return -1;
	return(strlen(str1));
}

/*isPalindrome: Checking given string is palindrome or not */
int isPalindrome(const char *str)
{
    if (!str)
        return -1;
    int left = 0;
    int right = 0;
    while (str[right] != '\0')
        right++;
    if (right == 0)
        return 1;
    right--;
    while (left < right) {
        if (str[left] != str[right])
            return 0;

        left++;
        right--;
    }
    return 1;
}
/* To check char in a string */
int isTrue(const char *str1, const char s2)
{
    if (!str1 || str1[0] == '\0'|| !s2)
        return -1;

    int ivar=0;
    for(ivar=0;str1[ivar]!='\0';ivar++)
	    if(str1[ivar]==s2)
		    return 1;
    return 0;
}
/* To check string in a string is present or not */
int isString(const char *str1,const char *str2)
{
	int i,j;
	if(!str1 || !str2 || str1[0]=='\0' || str2[0]=='\0')
	return -1;

	  /* substring search */
    for (i = 0; str1[i] != '\0'; i++)
    {
        j = 0;
        while (str1[i + j] != '\0' && str2[j] != '\0' &&
               str1[i + j] == str2[j])
        {
            j++;
        }

        /* full str2 matched */
        if (str2[j] == '\0')
            return 1;
    }

    return 0;
		
}
/*isTemperature: To check room temperature*/
int isTemperature(int t)
{
	if (t<0||t>100)
            throw std::out_of_range("Warning out of range");

        if(t >= TEMP_THRESHOLD)
	{		
            return 1;
	}
	else
	    return 0;

}



