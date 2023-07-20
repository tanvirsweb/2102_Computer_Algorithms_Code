#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
int main()
{
    llu n,val;
    cout<<"Data successfully generated."<<endl;
    n=10000;
    const int M=(int)500;

    //ofstream out("data.txt");
    //ofstream out("sortedData.txt");
    ofstream out("Lab3_task4/convexHullPoints.txt");
    srand(time(0));

    for(int i=1;i<=n;i++)
    {
        val=rand()%M;
        //val=i*10-5;
        out<<val<<" ";

        val=rand()%M;
        out<<val<<"\n";
    }
        

    return 0;
}