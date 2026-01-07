#include <stdio.h>
#include "String.h"

int main() {

	const char *s1="ABC";
	const char *s2="ABC";
	const char *str="ABA";
	int index;
	printf("Enter an string operation\n");
	printf ("case 1: To check string has even char or odd char\n");
	printf("case 2: To compare strings are equal or not\n");
	printf("case 3: To Check length of string \n");
	printf("case 4: To check given string is palindrome or not\n");


	scanf("%d",&index);	
	switch(index)
	{
		case 1:

			if (isEvenLength(s1)) {
				printf("%s has even length\n", s1);
			}

			if (!isEvenLength(s1)) {
				printf("%s has odd length\n", s1);
			}
			break;
		case 2:

			if(isEqual(s1,s2)){
				printf("Strings are equal\n");}
			else{
				printf("Strings are not Equal\n");}
			break;
		case 3:

			if(isLength(s1)==3)
				printf("String Lengths are equal\n");
			else
				printf("not equal\n");
			break;
		case 4:

			if(isPalindrome(str))
				printf("palindrome string\n");
			else
				printf("not a palindrome\n"); 
			break;
		default:
			printf("invalid operation\n");

	}
	return 0;
}
