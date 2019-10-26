#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128
#define RSIZ 10
int toString(char []);
int convert;
int main(void)
{
    char line[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;

int arrIntegers [100];
    fptr = fopen("input.txt", "r");
    while(fgets(line[i], LSIZ, fptr))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file %s  are :\n",fname);
    for(i = 0; i < tot; ++i)
    {char *found;
   found = strtok(line[i]," ");
    if( found==NULL)
    {
        printf("\t'%s'\n",line[i]);
        puts("\tNo separators found");
        return(1);
    }
    while(found)
    {int iteratorArr=0;
           convert= toString(found);
           printf("%d",convert);
           found = strtok(NULL," ");
           arrIntegers[iteratorArr]=convert;
           iteratorArr++;


    }
    }
    for(int o=0; o <35;o++){
    printf("%d\n",arrIntegers[o]);
    }


    }

int toString(char a[]) {
  int c, sign, offset, n;

  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }

  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }

  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1) {
    n = -n;
  }
  return n;
}


