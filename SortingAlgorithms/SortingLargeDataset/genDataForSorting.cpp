#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
int arr[(int)1e7];

int main()
{
    llu n,val;    
    n=(int) 1e7;
    const int M=(int)1e7;

    // ofstream out("data_random.txt");    
    // ofstream out("data_asc.txt");
    // ofstream out("data_desc.txt");
    ofstream out("data_pn.txt");
    srand(time(0));

    for(int i=1;i<n;i++)
    {
        val=rand();  
        arr[i]=val; //for +ve dataset

        //for -ve dataset
        // if(i%3==0) arr[i]=-val;
        // else arr[i]=val;                     
    }
    // for sorted ascending/descending dataset
    // sort(arr,arr+n,[](int a,int b){ return a<b; });//ascending order a,b.. (a<b)
    // sort(arr,arr+n,[](int a,int b){ return a>b; });//Descending order a,b... (a>b)

    for(int i=0;i<n;i++)
    {
        out<<arr[i]<<" ";        
    }
    out.close();    
    cout<<"Data successfully generated."<<endl;
    
    return 0;
}