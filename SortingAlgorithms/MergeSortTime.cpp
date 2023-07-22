#include<bits/stdc++.h>
using namespace std;

typedef long long int llu;
int a[1000],cntM,cntQ;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l,
		int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back
	// into arr[l..r]
	// Initial index of first subarray
	i = 0;
	// Initial index of second subarray
	j = 0;

	// Initial index of merged subarray
	k = l;
	while (i < n1 && j < n2)
	{
        cntM++;
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1) {
        cntM++;
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2)
	{
        cntM++;
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int arr[],
			int l, int r)
{
    cntM++;
	if (l < r)
	{
		// Same as (l+r)/2, but avoids
		// overflow for large l and h
        cntM++;
		int m = l + (r - l) / 2;

		// Sort first and second halves
        cntM++;
		mergeSort(arr, l, m);
        cntM++;
		mergeSort(arr, m + 1, r);
        cntM++;
		merge(arr, l, m, r);
	}
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
        cout<<a[i]<<" ";
	cout<<endl;
}

// Driver code
int main()
{
	int n=300;
    ifstream in("data.txt");
    for(int i=0;i<n;i++){
        in>>a[i];
        //cout<<a[i]<<endl;
    }

    auto start = chrono::steady_clock::now();
    mergeSort(a,0,n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    printArray(a,n);
    cout<<"When n="<<n<<" then step count no for MergeSort is:"<<cntM<<endl;
    cout<<"Required time:" << chrono::duration <double, nano> (diff).count() << " ns" << endl;

	return 0;
}
