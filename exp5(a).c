#include <stdio.h>
void main()
{   
    int a[6],temp,i,j;
    int size=6;
    printf("input the elements:");
    for(i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("after sorting:");
    for(i=0;i<6;i++)
    {
        printf("%d\n",a[i]);
        
    }
}











//INSERTION SORT
#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];        // The element to be inserted
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, n);

    printArray(arr, n);

    return 0;
}
