#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include <time.h>
int row , row2, column, column2,xx,yy;
int r,k,n,a;
int twoArray[20][20];
int twoArray_2[20][20];
int resultRow;
int sumRow;
int resultColumn;
int resultArr[20][20];
int columnArrayCopy[25];
int  rowArrayCopy[25];
int firstArr[25];
int sizeThreads;
int elementMove,sizeThreadsCell;
void *multiplyCell(void* param);
void *multiplyRowResult(void *data);
void main()
{
    pthread_t *threadPointer;

    FILE* file = fopen ("input.txt", "r");
    int i = 0;
    int integerArr[50];
    int count =0;
    fscanf (file, "%d", &i);
    while (!feof (file))

    {
        integerArr[count]=i;
       // printf ("%d\t",  integerArr[count]);
        fscanf (file, "%d", &i);

        count ++;
    }
    fclose (file);
    int rowOfMatrixOne =integerArr[0];
   // printf("%d -> row \n",rowOfMatrixOne);
    int columnsOfMatrixOne =integerArr[1];
   // printf("%d -> Columns\n",columnsOfMatrixOne);
    int lengthMatrix= (columnsOfMatrixOne*rowOfMatrixOne)+1;

    //printf("%d -> Size\n",lengthMatrix);
    for(int loop = 0; loop <lengthMatrix-1; loop++)
    {
        firstArr[loop] = integerArr[loop+2];
        //printf("%d LOOP First MAtrix \t",loop);
       // printf("%d\t", firstArr[loop]);
    }

    int stratMAtrixTwo =lengthMatrix+3;
   // printf("%d -> Start Matrix two Index \n",stratMAtrixTwo);
    int rowOfMatrixTwo=integerArr[stratMAtrixTwo-2];
  //  printf("%d -> row Matrix two \n",rowOfMatrixTwo);
    int columnsofMatrixTwo=integerArr[stratMAtrixTwo-1];
  //  printf("%d -> row Matrix two \n",columnsofMatrixTwo);


    int lengthMatrix2= (columnsofMatrixTwo*rowOfMatrixTwo);

    int secondArr[50];
    int beginL=stratMAtrixTwo;
    //printf("BEGIN MAT 2 : %d\n",beginL);
    int endArrIndex=beginL+lengthMatrix2-1;
    //printf("end MAT 2 : %d\n",endArrIndex);
  // printf("%d len :\n ",lengthMatrix2);
    for(int loop2 = 0; loop2 <lengthMatrix2; loop2++)
    {
        int copyIndex =loop2+beginL;
        secondArr[loop2]=integerArr[copyIndex];
       // printf("   index taken from Array  %d :  %d \n  ", secondArr[loop2],loop2);

    }

   // printf("^^^^^^^^^ 2D ARRAY Matrix 1^^^^^^^^^^\n");
printf("row 2D ->>>>>>>>>%d , %d\n",lengthMatrix,rowOfMatrixOne);
    int  counter = 0;
    for ( row = 0; row < rowOfMatrixOne; row++)
    {
        for ( column  = 0; column <(lengthMatrix-1)/rowOfMatrixOne; column++)
        {

            twoArray[row][column] = firstArr[counter];
             printf("Two D MAT 1 %d %d%d ! \n",twoArray[row][column],row,column);
                                   counter++;
            //printf("Counter%d",counter);


        }



    }

    int counter2 =0;
    for ( row2 = 0; row2 < rowOfMatrixTwo; row2++)
    {
        for ( column2  = 0; column2 <lengthMatrix2/rowOfMatrixTwo; column2++)
        {

            twoArray_2[row2][column2] = secondArr[counter2];
            printf("Two D2 %d %d%d  \n",twoArray_2[row2][column2],row2,column2);
            counter2++;
        }
    }

    resultRow=row;
    resultColumn=column2;
    sizeThreads==resultRow*resultColumn;
   sizeThreadsCell=resultRow*resultColumn;
    pthread_t tid[sizeThreadsCell]; //->12 thread
   // printf("Size %d\n ",sizeThreadsCell);

    	clock_t begin = clock();



    for( int threadID = 0; threadID < sizeThreadsCell; threadID++)
    {int value =threadID ;
    int *p;
    p=&value;

            pthread_create(&tid[threadID],NULL,multiplyCell,p);
            pthread_join(tid[threadID], NULL);
	}
}

void *multiplyCell(void * param)
{
    int threadID = *(int *) param;
int     sumCell=0;
    int i =threadID/resultRow ;
    int j=threadID%resultColumn ;


  for ( int k = 0 ; k <row2; k++ ){
    sumCell = twoArray_2[k][j]*twoArray[i][k] ;
        printf("****RESUL : %d ThreadID : %d****\n",sumCell,threadID);


}


        return NULL;

}
