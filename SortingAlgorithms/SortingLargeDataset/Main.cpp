#include<bits/stdc++.h>
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#include "CountingSort.cpp"
#include "RadixSort.cpp"
#include "QuickSort.cpp"
#include "MergeSort.cpp"

using namespace std;

void testFunction(string str,vector<int> arr, void (*func)(vector<int>&)){

    auto start = chrono::steady_clock::now();
    func(arr);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;    
    long long int t=chrono::duration <double, nano> (diff).count();
    cout<<"\nWhen n="<<arr.size()<<endl;
    cout<<"Required time for "+str+"\n" << t << " nano sec\n" << t*1.0/(int)1e3 << " micro sec\n" << t*1.0/(int)1e6 << " ms" << endl;
}

void testFunction(string str,vector<int> arr , int n , void (*func)(vector<int>& , int)){

    auto start = chrono::steady_clock::now();
    func(arr,n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;    
    long long int t=chrono::duration <double, nano> (diff).count();
    cout<<"\nWhen n="<<arr.size()<<endl;
    cout<<"Required time for "+str+"\n" << t << " nano sec\n" << t*1.0/(int)1e3 << " micro sec\n" << t*1.0/(int)1e6 << " ms" << endl;
}
void testFunction(string str,vector<int> arr ,int l, int n , void (*func)(vector<int>& , int, int)){

    auto start = chrono::steady_clock::now();
    func(arr,l,n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;    
    long long int t=chrono::duration <double, nano> (diff).count();
    cout<<"\nWhen n="<<arr.size()<<endl;
    cout<<"Required time for "+str+"\n" << t << " nano sec\n" << t*1.0/(int)1e3 << " micro sec\n" << t*1.0/(int)1e6 << " ms" << endl;
}


int main()
{

	const int n=5e4;
    vector<int> arr(n);
    // ifstream in("data_rand.txt");
	// ifstream in("data_asc.txt");
	// ifstream in("data_desc.txt");
    ifstream in("data_rand.txt");

    for(int i=0;i<n;i++){
        in>>arr[i];
        //cout<<a[i]<<endl;
    }
	in.close();//close file    

    // bubbleSort(arr,n);
    testFunction("Bubble Sort: ", arr , n, &bubbleSort);
    // selectionSort(arr,n);
    testFunction("Selection Sort: ", arr, n, &selectionSort);
    // insertionSort(arr,n);
    testFunction("Insertion Sort: ", arr, n, &insertionSort);
    // countingSort(arr);
    testFunction("Counting Sort: ", arr, &countingSort);
    // radixSort(arr);
    testFunction("Radix Sort: ", arr, &radixSort);
    // quickSort(arr,0,n);
    testFunction("Quick Sort: ", arr, 0, n, &quickSort);
    // mergeSort(arr, 0, n - 1);
    testFunction("Merge Sort: ", arr, 0, n-1, &mergeSort);

	return 0;
}
