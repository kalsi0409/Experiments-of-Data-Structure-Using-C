#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; // Return index
    }
    return -1; // Not found
}

// Binary Search Function (Array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid; // Found
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

int main() {
    int arr[100], n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted for binary search):\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("Choose search method:\n1. Linear Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        result = linearSearch(arr, n, key);
    else if(choice == 2)
        result = binarySearch(arr, n, key);
    else {
        printf("Invalid choice.\n");
        return 0;
    }

    if(result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
