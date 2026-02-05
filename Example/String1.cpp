#include "String.h"
#include<stddef.h>
#include<string.h>
#include<stdexcept>
#define TEMP_THRESHOLD 30


/*isTemperature: To check room temperature*/
int isTemperature(int t)
{
	if (t<=0)
            throw std::out_of_range("Warning lower range");
	if (t>=100)
            throw std::out_of_range("Warning High range");

        if(t >= TEMP_THRESHOLD)
	{		
            return 1;
	}
	else
	    return 0;

}

