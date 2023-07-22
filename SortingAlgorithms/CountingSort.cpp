// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

void countSort(int arr[],int n)
{
    int output[n];
    // Create a count array to store count
    // of individual characters and
    // initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for (i = 0;i<n;i++)
        count[arr[i]]++;

    // Change count[i] so that count[i]
    // now contains actual position of this int in output array
    for (i = 1; i <= RANGE;i++)
        count[i] += count[i - 1];

    // Build the output integer array
    for (i = n-1;i>=0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr,
    // so that arr now contains
    // sorted characters
    for (i = 0; arr[i];i++)
        arr[i] = output[i];
}

// Driver code
int main()
{
    int arr[] ={2,4,1,9,4,5,6,2,3,8};

    // Function call
    countSort(arr,10);

    cout << "Sorted array is : ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}
