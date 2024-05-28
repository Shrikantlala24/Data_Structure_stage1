// Binary Search

#include <math.h>
#include <stdio.h>

int main()
{
    int arr[50],n,x,result;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("\n Enter elements of array:");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Given array is:");
    displayArray(arr, n);
    printf("\n\nEnter the number to be searched:");
    scanf("%d",&x);
    result = binarySearch(arr, x, 0, n - 1);
    if (result == -1)
    printf("\nElement is not present in the array");
    else
    printf("\nElement is present at index %d",result);
    return 0;
}

void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int binarySearch(int arr[], int x, int l, int r)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    // if we reach here, then element was not present
    return -1;
}
