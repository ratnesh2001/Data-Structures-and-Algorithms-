#include<stdio.h>
#include<stdlib.h>
 
//this is required for bucket
struct bucket 
{
    int count;
    int* value;
};
 
//efination of functions 
int compareIntegers(const void* first, const void* second);
void bucketSort(int array[],int n);

//main
int main()
{
    
    int i,k,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	
	int* arr=(int *)malloc(sizeof(int)*n);
	 
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
 
    bucketSort(arr, n); 
    printf("\nAfter Sorting\n");
    for (k = 0; k<i; k++)
        printf("%d ", arr[k]);   
 
 
    return 0;
}

//comparing integers
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
 
//bucketsort algo
void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}
 







	
