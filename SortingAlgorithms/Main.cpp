#include<bits/stdc++.h>
#include "QuickSort_Time.cpp"

int main()
{

	int n=2300;
    // ifstream in("data_rand.txt");
	// ifstream in("data_asc.txt");
	// ifstream in("data_desc.txt");
    ifstream in("data_pn.txt");

    for(int i=0;i<n;i++){
        in>>arr[i];
        //cout<<a[i]<<endl;
    }
	in.close();//close file
    cout<<"Sorting Algorithm running ..... "<<endl;

    auto start = chrono::steady_clock::now();
    //------Call a sorting algorithm---------
    // quickSort(arr,0,n);
    sort(arr,arr+n);

    //----------execution complete of the sorting algorithm-------
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    // print arrray
    // for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

	long long int t=chrono::duration <double, nano> (diff).count();
    cout<<"When n="<<n<<endl;
    cout<<"Required time:" << t << " nano sec" << endl;
	cout<<"Required time:" << t*1.0/(int)1e3 << " micro sec" << endl;
	cout<<"Required time:" << t*1.0/(int)1e6 << " mili sec" << endl;

	return 0;
}
