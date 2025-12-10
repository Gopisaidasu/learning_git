   #include<stdio.h>
   char* fun(char ch,float f);
   int main()
   {
          
           char* (*fp)(char,float);
           fp = fun;
           char *p = fp('A',4.5);
            printf("In main(), p = %s\n",p);
  }
  char* fun(char ch,float f)
  {
          printf("test function...\n");
          printf("ch = %c f = %f\n",ch,f);
          return "vector";
  }
