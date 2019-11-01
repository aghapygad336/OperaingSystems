#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include <time.h>
int row ,  column;
void * status;
int integerArr[12],elements;
void *p;
int elementCell = 0;
void* mergeSortVector(void* arg);
void merge_sort(int low, int high, int arr[]);
void merge(int integerArr[], int l, int m, int r);
void main()

{
    pthread_t *threadPointer;
    clock_t t_Start, t_End;

    FILE* file = fopen ("merge.txt", "r");
    int i = 0;
    int integerArr[50];
    int copyArr[50];
    int count =0;
    fscanf (file, "%d", &i);
    while (!feof (file))

    {
        copyArr[count]=i;
        printf ("%d\t",  copyArr[count]);
        fscanf (file, "%d", &i);

        count ++;
    }
    fclose (file);
    int elements =copyArr[0];
    printf("\n -> Number of Elements :%d  \n",elements);
    for(int loop = 0; loop <elements; loop++)
    {
        integerArr[loop] = copyArr[loop+1];
        printf("MAtrix %d\n",integerArr[loop]);
    }

    int sizeThreads=2;
    pthread_t tid[sizeThreads]; //10 thread
    printf("-> Number of Threads :%d  \n",sizeThreads);

    t_Start = clock();

    for(int i = 0; i < sizeThreads; i++)
    {
        pthread_create(&tid[i],NULL,mergeSortVector,NULL);
    }



    for(int i = 0; i < sizeThreads; i++)
    {
        pthread_join(tid[i], NULL);

    }


    t_End = clock();
    float total_t;
    total_t = (float)(t_End-t_Start) / CLOCKS_PER_SEC;

    printf("Starting of the program, start_t = %ld\n", t_Start);

    printf("End of the big loop, end_t = %ld\n", t_End);
    printf("Total time taken by CPU For Merge Sort : %f\n",total_t);




}









void* mergeSortVector(void* arg)
{
    int ele = elementCell;     // element out of 2 thread
    int low = ele*(elements / 2);
    int high = (ele +1) * (elements / 2) - 1;

    int mid = low + (high - low) / 2;
    if (high>low)
    {
        merge_sort(low, mid,integerArr);
        merge_sort(mid + 1, high,integerArr);
        merge(integerArr,low, mid, high);
    }
    elementCell++;
}

void merge_sort(int low, int high, int arr[])
{
    int mid = low + (high - low) / 2;
    if (low < high)
    {

        merge_sort(low, mid,arr);
        merge_sort(mid + 1, high,arr);
        merge(arr,low, mid, high);
    }
}
void merge(int integerArr[], int l, int m, int r)
{
    int sub_one, sub_two, merged;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    int temp=0;
    while(temp!=n1)
    {
        L[temp] = integerArr[l + temp];
        temp++;
    }
    int temp_2=0;

    while(temp_2!=n2)
    {
        R[temp_2] = integerArr[m + 1+ temp_2];
        temp_2++;
    }

    sub_one = 0;
    sub_two = 0;
    merged = l;
    while (sub_one < n1 && sub_two < n2)
    {
        if (L[sub_one] <= R[sub_two])
        {
            integerArr[merged] = L[sub_one];
            sub_one++;
        }
        else
        {
            integerArr[merged] = R[sub_two];
            sub_two++;
        }
        merged++;
    }

    while (sub_one < n1)
    {
        integerArr[merged] = L[sub_one];
        sub_one++;
        merged++;
    }
    while (sub_two < n2)
    {
        integerArr[merged] = R[sub_two];
        sub_two++;
        merged++;
    }
}
