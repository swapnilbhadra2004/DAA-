#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int sum(int *arr,int x,int y)
{
    int sum = 0 ; 
    for(int i = x ; i <= y ; i++)
    {
        sum += arr[i] ;
    }
    return sum ;
}

int MaxSubarraySum(int *arr,int start,int end)
{
    int maxSum = INT_MIN ;
    int x = 0, y = 0;
    for(int i = start ; i< end ; i++)
    {
        for(int j = start ; j < end  ; j++)
        {
            if(sum(arr,i,j) > maxSum)
            {
                maxSum = sum(arr,i,j) ; 
                x = i ;
                y = j ;
            }
        }
    }
    return maxSum ;
}

void main()
{
    int *arr = (int*)malloc(10*sizeof(int));
    for(int i = 0 ; i < 10 ; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d is the maximum suubarray sum",MaxSubarraySum(arr,0,9));
}