#include<bits/stdc++.h>
using namespace std;

int arr[1000],cntQ;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
        // cntQ++;
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	// cntQ++;
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
        // cntQ++;

		while (arr[i] <= pivot) {
			i++;
			// cntQ++;
		}

		while (arr[j] > pivot) {
			j--;
			// cntQ++;
		}
        // cntQ++;
		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	// cntQ++;
	if (start >= end)
		return;

	// partitioning the array
	// cntQ++;
	int p = partition(arr, start, end);

	// Sorting the left part
	// cntQ++;
	quickSort(arr, start, p - 1);

	// Sorting the right part
	// cntQ++;
	quickSort(arr, p + 1, end);
}

int main()
{

	int n=300;
    ifstream in("data.txt");
    for(int i=0;i<n;i++){
        in>>arr[i];
        //cout<<a[i]<<endl;
    }
    auto start = chrono::steady_clock::now();
    quickSort(arr,0,n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"When n="<<n<<" then count no for Quick Sort is:"<<cntQ<<endl;
    cout<<"Required time:" << chrono::duration <double, nano> (diff).count() << " ns" << endl;


	return 0;
}
