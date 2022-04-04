// Roman numerals converter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum { DECIMALTOROMAN=0, ROMANTODECIMAL };
#define MAXCALC 115

char* decimaltoroman(char *text);
char* romantodecimal(char *text);
void showusage();

int main(int argc, char *argv[]) 
{
   int option;

   if (argc!=2)
    showusage();
   option=(atol(argv[1])) ? DECIMALTOROMAN : ROMANTODECIMAL;
    
    printf("%s\n", (option==DECIMALTOROMAN) ? decimaltoroman(argv[1]) : romantodecimal(argv[1]));

   
 return 0;
}

// Decimal digits to Roman numerals
char* decimaltoroman(char *text)
{
  int num=atol(text), i=0;
  static char roman[MAXCALC];
  
   while(num != 0 && i<MAXCALC - 3)
    {

      if (num >= 1000)       // 1000 - m
        {
           roman[i++]='M';
           num -= 1000;
        }

        else if (num >= 900)   // 900 -  cm
        {
           roman[i++]='C';
           roman[i++]='M';
           num -= 900;
        }        

        else if (num >= 500)   // 500 - d
        {           
           roman[i++]='D';
           num -= 500;
        }

        else if (num >= 400)   // 400 -  cd
        {
           roman[i++]='C';
           roman[i++]='D';
           num -= 400;
        }

        else if (num >= 100)   // 100 - c
        {
           roman[i++]='C';
           num -= 100;                       
        }

        else if (num >= 90)    // 90 - xc
        {
           roman[i++]='X';
           roman[i++]='C';
           num -= 90;                                              
        }

        else if (num >= 50)    // 50 - l
        {
           roman[i++]='L';
           num -= 50;                                                                     
        }

        else if (num >= 40)    // 40 - xl
        {
           roman[i++]='X';
           roman[i++]='L';           
           num -= 40;
        }

        else if (num >= 10)    // 10 - x
        {
           roman[i++]='X';
           num -= 10;           
        }

        else if (num >= 9)     // 9 - ix
        {
           roman[i++]='X';
           num -= 9;                         
        }

        else if (num >= 5)     // 5 - v
        {
           roman[i++]='V';
           num -= 5;                                     
        }

        else if (num >= 4)     // 4 - iv
        {
           roman[i++]='I';
           roman[i++]='V';
           num -= 4;                                                            
        }

        else if (num >= 1)     // 1 - i
        {
           roman[i++]='I';
           num -= 1;                                                                                   
        }

    }
    
   roman[i]='\0';
   
  return &roman[0];
}

// Roman numerals to decimal
char* romantodecimal(char *text)
{
   int deci=0;
   int d[MAXCALC]= { 0 }, i, length=strlen(text);
   static char decimal[MAXCALC];
 
    for(i=0;i<length && i<MAXCALC;i++){
    
      switch(text[i]){
         case 'm':
         case 'M': d[i]=1000; break;
         case 'd':
         case 'D': d[i]= 500; break;
         case 'c':
         case 'C': d[i]= 100; break;
         case 'l':
         case 'L': d[i]= 50; break;
         case 'x':
         case 'X': d[i]= 10; break;;
         case 'v':
         case 'V': d[i]= 5; break;
         case 'i':
         case 'I': d[i]= 1;
       break;
      }
      
    }
   
    for(i=0;i<length;i++){
      if(i==length-1 || d[i]>=d[i+1])
         deci += d[i];
      else
         deci -= d[i];
   }
   sprintf(decimal, "%d", deci);
   
 return &decimal[0];
}

// show converter usage
void showusage()
{
  printf("Usage:\n roman <decimal or Roman> \n\nA Roman<->decimal numerals converter.\n\nOptions:\n      --help\tdisplay this help\n\nDistributed under the GNU Public licence.\n");
  exit (-1);
}
