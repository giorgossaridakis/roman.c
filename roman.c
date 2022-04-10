// Roman numerals converter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// constants
#define MAXCALC 100001
enum { DECIMALTOROMAN, ROMANTODECIMAL };
typedef long int li;
struct ROMANNUMERALS {
 const char Numeral[3];
 const int Decimal;
} NUMERALS[] = {  { "M", 1000 },
                                { "CM", 900 },
                                { "D", 500  },
                                { "CD", 400 },
                                { "C", 100  },
                                { "XC", 90  },
                                { "L", 50   },
                                { "XL", 40  },
                                { "X", 10   },
                                { "IX", 9   },
                                { "V", 5    },
                                { "IV", 4   },
                                { "I", 1    }
                 };
#define size 13

// routine declarations
char* decimaltoroman(char *text);
char* romantodecimal(char *text);
char* ctos(char c);
void showusage();

int main(int argc, char *argv[]) 
{
   if (argc!=2)
    showusage();
    
    printf("%s\n", (atol(argv[1])) ? decimaltoroman(argv[1]) : romantodecimal(argv[1]));

 return 0;
}

// Decimal digits to Roman numerals
char* decimaltoroman(char *text)
{
  li num=atol(text);
  int i;
  static char roman[MAXCALC];
  roman[0]='\0';
  
   while (num && strlen(roman)<MAXCALC-1) {
    
    for (i=0;i<size;i++) {
     if (num>=NUMERALS[i].Decimal) {
      strcat(roman, NUMERALS[i].Numeral);
      num-=NUMERALS[i].Decimal;
      break;
     }
    }
   }
   
  return &roman[0];
}

// Roman numerals to decimal
char* romantodecimal(char *text)
{
   li total=0;
   int d[MAXCALC]= { 0 }, i, i1, length=strlen(text);
   static char decimal[MAXCALC];
   
    for (i=0;i<length && i<MAXCALC-1;i++) {
     for (i1=0;i1<size;i1++) {
      if (!strcmp(ctos(toupper(text[i])), NUMERALS[i1].Numeral)) {
       d[i]=NUMERALS[i1].Decimal;
       break;
      }
     }
    }
   
    for(i=0;i<length;i++) {      
     if( i == length-1 || d[i] >= d[i+1])
      total += d[i];
     else
      total -= d[i];
   }

   sprintf(decimal, "%ld", total);
   
 return &decimal[0];
}

// char to string
char* ctos(char c)
{
  static char text[2];
  
   text[0]=c;
   text[1]='\0';
   
 return &text[0];
}

// show converter usage
void showusage()
{
  printf("Usage:\n roman <decimal or Roman> \n\nA Roman<->decimal numerals converter.\n\nOptions:\n      --help\tdisplay this help\n\nDistributed under the GNU Public licence.\n");
  exit (-1);
}

