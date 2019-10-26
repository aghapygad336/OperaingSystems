







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

printf("%d -> Size\n",lengthMatrix);
int firstArr[25];
for(int loop = 0; loop <lengthMatrix-1; loop++) {
     firstArr[loop] = integerArr[loop+2];
     printf("%d LOOP First MAtrix \t",loop);
   printf("%d\t", firstArr[loop]);
}

int stratMAtrixTwo =lengthMatrix+3;
printf("%d -> Start Matrix two Index \n",stratMAtrixTwo);
int rowOfMatrixTwo=integerArr[stratMAtrixTwo-2];
printf("%d -> row Matrix two \n",rowOfMatrixTwo);
int columnsofMatrixTwo=integerArr[stratMAtrixTwo-1];
printf("%d -> row Matrix two \n",columnsofMatrixTwo);


int lengthMatrix2= (columnsofMatrixTwo*rowOfMatrixTwo);

int secondArr[50];
int beginL=stratMAtrixTwo;
printf("BEGIN MAT 2 : %d\n",beginL);
int endArrIndex=beginL+lengthMatrix2-1;
printf("end MAT 2 : %d\n",endArrIndex);
printf("%d len :\n ",lengthMatrix2);
for(int loop2 = 0; loop2 <lengthMatrix2;loop2++) {
int copyIndex =loop2+beginL;
secondArr[loop2]=integerArr[copyIndex];
printf("***********************");
printf("   index taken from Array  %d  %d \n  ", secondArr[loop2],copyIndex);

      }

//now we have Mat 1 and Mat 2

 //prints the new array to ensure correct assignment
int twoArray[rowOfMatrixOne][rowOfMatrixOne];
	    int  counter = 0;
   for (int row = 0; row < rowOfMatrixOne; row++) {
   for (int column  = 0; column <lengthMatrix/rowOfMatrixOne; column++) {

	  twoArray[row][column] = firstArr[counter];
	  printf("%d %d%d Two D \n",twoArray[row][column],row,column);
	  counter++;
	    }


}
printf("^^^^^^^^^^^^^^^^^^^");
int twoArray_2[rowOfMatrixTwo][rowOfMatrixOne];
	      counter = 0;
   for (int row = 0; row < rowOfMatrixTwo; row++) {
   for (int column  = 0; column <lengthMatrix2/rowOfMatrixTwo; column++) {

	  twoArray_2[row][column] = firstArr[counter];
	  printf("%d %d%d Two D \n",twoArray_2[row][column],row,column);
	  counter++;
	    }


}









}

