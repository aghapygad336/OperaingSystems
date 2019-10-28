#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include <time.h>
int row ,  column;
void * status;
int integerArr[12],  l,  r, elements;
void *p;
void *mergingMatrix(void *p) ;

void main()
{
    pthread_t *threadPointer;

    FILE* file = fopen ("merge.txt", "r");
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
    int elements =integerArr[0];
    printf("\n -> Number of Elements :%d  \n",elements);

    int sizeThreads=elements;
    pthread_t tid[2]; //10 thread
    printf("\n -> Number of Elements :%d  \n",sizeThreads);

    for(int i = 0; i < 2; i++)
    {
      int rc = pthread_join(tid[i], &status);
        pthread_create(&tid[i],NULL,mergingMatrix,NULL);
        pthread_join(tid[i], NULL);

}





    }


    void merge(int integerArr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = integerArr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = integerArr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            integerArr[k] = left[i];
            i++;
        }
        else
        {
            integerArr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        integerArr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        integerArr[k] = right[j];
        j++;
        k++;
    }
}








void mergeSort(int integerArr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
          mergeSort(integerArr, l, m);
          mergeSort(integerArr, m+1, r);

        merge(integerArr, l, m, r);
    }
}




void *mergingMatrix(void *p){
    mergeSort(integerArr, 0, elements - 1);
}
