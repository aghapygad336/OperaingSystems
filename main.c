







#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{


  FILE* file = fopen ("input.txt", "r");
  int i = 0;
int integerArr[25];
int count =0;
  fscanf (file, "%d", &i);
  while (!feof (file))

    {     integerArr[count]=i;
          printf ("%d\t",  integerArr[count]);
          fscanf (file, "%d", &i);

      count ++;
    }
  fclose (file);
int rowOfMatrixOne =integerArr[0];
printf("%d -> row \n",rowOfMatrixOne);
int columnsOfMatrixOne =integerArr[1];
printf("%d -> Columns\n",columnsOfMatrixOne);
int lengthMatrix= (columnsOfMatrixOne*rowOfMatrixOne)+1;

printf("%d -> Size\n",lengthMatrix-1);
int firstArr[25];
for(int loop = 0; loop <lengthMatrix-1; loop++) {
     firstArr[loop] = integerArr[loop+2];
     printf("%d LOOP First MAtrix \t",loop);
   //  printf("%d\t", firstArr[loop]); }
}

int stratMAtrixTwo =lengthMatrix+3;
printf("%d -> Start Matrix two Index \n",stratMAtrixTwo);
int rowOfMatrixTwo=integerArr[stratMAtrixTwo-2];
printf("%d -> row Matrix two \n",rowOfMatrixTwo);
int columnsofMatrixTwo=integerArr[stratMAtrixTwo-1];
printf("%d -> row Matrix two \n",columnsofMatrixTwo);


int lengthMatrix2= (columnsofMatrixTwo*rowOfMatrixTwo);

int secondArr[20];
int beginL=stratMAtrixTwo;
printf("BEGIN MAT 2 : %d\n",beginL);
int endArrIndex=beginL+lengthMatrix2-1;
printf("end MAT 2 : %d\n",endArrIndex);
printf("%d len :\n ",lengthMatrix2);
for(int loop2 = 0; loop2 <lengthMatrix2-1;loop2++) {
int copyIndex =loop2+beginL;
secondArr[loop2]=integerArr[copyIndex];
printf(" LOOP  MAtrix2 , Loop :%d %d \n  ",secondArr[loop2],loop2);

      }
}







