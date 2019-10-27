#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include <time.h>
int row , row2, column, column2;
int twoArray[20][20];
int twoArray_2[20][20];
int resultRow;

int resultColumn;
int resultArr[20][20];
void *multiplyCell(void *data) ;

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
    for(int loop = 0; loop <lengthMatrix-1; loop++)
    {
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
    for(int loop2 = 0; loop2 <lengthMatrix2; loop2++)
    {
        int copyIndex =loop2+beginL;
        secondArr[loop2]=integerArr[copyIndex];
        printf("***********************");
        printf("   index taken from Array  %d :  %d \n  ", secondArr[loop2],loop2);

    }

    printf("^^^^^^^^^ 2D ARRAY Matrix 1^^^^^^^^^^\n");

    int  counter = 0;
    int row,column;
    for ( row = 0; row < rowOfMatrixOne; row++)
    {
        for ( column  = 0; column <lengthMatrix/rowOfMatrixOne; column++)
        {

            twoArray[row][column] = firstArr[counter];
            counter++;
        }
        counter = 0;
        int row2,column2;


    }
    printf("^^^^^^^^^ 2D ARRAY Matrix 2^^^^^^^^^^\n");
    int twoArray_2[rowOfMatrixTwo][rowOfMatrixOne];
    for ( row2 = 0; row2 < rowOfMatrixTwo; row2++)
    {
        for ( column2  = 0; column2 <lengthMatrix2/rowOfMatrixTwo; column2++)
        {

            twoArray_2[row2][column2] = secondArr[counter];
            printf("%d %d%d Two D \n",twoArray_2[row2][column2],row2,column2);
            counter++;
        }
    }

    resultRow=row;
    resultColumn=row2;
    int sizeThreads=resultRow*resultColumn;
    pthread_t tid[sizeThreads]; //->12 thread
    void *status;
    	clock_t begin = clock();

    for(int i = 0; i < sizeThreads; i++)
    {



//
//Thread equivalent of fork()

//int  pthread_create(pthread_t  * thread,  thread_attr_t  *  attr, void * (*start_routine)(void *),
//void * arg
//);
//Returns 0 if OK, and non-zero (> 0) if error.
//Parameters for the routines are passed through void * arg.

        int   rc = pthread_join(thread[t], &status);
        pthread_create(&tid[i],NULL,multiplyCell,void *p);
        pthread_join(tid[i], NULL);

    }

	clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("Time elpased is %f seconds", time_spent);
}




void *multiplyCell(void *p)
{
    int  sum = 0;

    for(int n = 0; n< resultRow; n++)
    {
        for(int r = 0; r< resultColumn; r++)
        {
            sum =sum+ twoArray[n][r]*twoArray_2[n][r];

            resultArr[n][r]=sum;
            printf("%d",sum);
        }
    }
    pthread_exit(0);
}
