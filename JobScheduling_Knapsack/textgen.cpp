#include<bits/stdc++.h>
using namespace std;


int main(){
    ofstream out("knapsackN.txt");
    //ofstream out("jobN.txt");
    srand(time(0));
    //q 
    //n p[n] d[n]

    /*int q=rand()%30+10;
    out<<q<<endl;
    for(int i=0;i<q;i++){
        int n=rand()%20+10;
        out<<n<<endl;
        for(int j=0;j<n;j++) out<<( rand()%30+5 )<<" ";
        out<<endl;
        for(int j=0;j<n;j++) out<<( rand()%10+1 )<<" ";
        out<<endl;
    }*/
    /*
    q
    n
    w
    p[n]
    w[n]
   */ 
   int q=20;
   out<<q<<endl;
    for(int i=0;i<q;i++){
        int n,w;
        n=rand()%30+10;
        w=rand()%50+1;
        out<<n<<endl;
        out<<w<<endl;
        for(int j=0;j<n;j++) out<< (rand()%(w-10)+1)<<" ";
        out<<endl;
        for(int j=0;j<n;j++) out<< (rand()%200+1)<<" ";
        out<<endl;
        
        
    }

    cout<<"******************complete***************"<<endl;
}