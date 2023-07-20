#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;

llu cntItr,cntR,cntL;
int a[10000];

int linearSearch(int a[],int n,int x){
    for(int i=0;i<n;i++)
    {
        cntL++;
        if(a[i]==x){
            return i;
        }
    }
    cntL++;
    return -1;
}

int binSearchItr(int a[],int n,int x)
{
    llu low=0,high=n,mid;
    while(low<=high)
    {
        cntItr++;
        mid=(low+high)/2;

        cntItr++;
        if(x<a[mid]){
            high=mid-1;
        }
        else if(x>a[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

//--------------------------------

int BinSrch(int a[],int i,int l,int x){
    cntR++;
    if(i==l){
        if(x==a[i]){
            return i;
        }
        else{
            return -1;
        }
    }
    else{
        cntR++;
        llu mid=(i+l)/2;

        cntR++;
        if(x==a[mid]){
            return mid;
        }
        else if(x<a[mid]){
            return BinSrch(a,i,mid-1,x);
        }
        else{
            return BinSrch(a,mid+1,l,x);
        }
    }
}
//---------------------------------

int main()
{
    int n=10000;
    ifstream in("sortedData.txt");
    for(int i=0;i<n;i++){
        in>>a[i];
    }
    //---------------------
    auto start = chrono::steady_clock::now();
    //  Insert the code that will be timed
    
    binSearchItr(a,n,1004);
    auto end = chrono::steady_clock::now();
    // Store the time difference between start and end
    auto diff = end - start;
    cout<<"when n="<<n<<" Then count no for Iteration metod:"<<cntItr<<endl;
    cout<<"Required time:" << chrono::duration <double, nano> (diff).count() << " ns" << endl;


    start = chrono::steady_clock::now();
    BinSrch(a,0,n,1004);
    end = chrono::steady_clock::now();
    // Store the time difference between start and end
    diff = end - start;
    cout<<"when n="<<n<<" Then count no for Recursive metod:"<<cntR<<endl;
    cout<<"Required time:" << chrono::duration <double, nano> (diff).count() << " ns" << endl;
    
    start = chrono::steady_clock::now();
    linearSearch(a,n,1004);
    end = chrono::steady_clock::now();
    // Store the time difference between start and end
    diff = end - start;
    cout<<"when n="<<n<<" Then count no for LinearSearch metod:"<<cntL<<endl;
    cout<<"Required time:" << chrono::duration <double, nano> (diff).count() << " ns" << endl;

    return 0;
}