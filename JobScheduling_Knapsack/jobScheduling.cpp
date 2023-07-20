#include<bits/stdc++.h>
using namespace std;
ifstream in("jobN.txt");
int cnt;
//global variable

/*
Analysis of greedy Knapsack problem and Job scheduling.

Knapsack.txt:
4
20
20 25 10 12
30 25 20 10
5
25
20 15 20
(n,m,w,p)
1. 2 Feasible solution
2. 1 optimal solution
Calculated profit earned

job Scheduling:
n=num jobs
pi=profit
di=deadline
Let every job can be done in 1 clock pulse.

1st job choose depending on profit
then serial them acording to deadline.

4 
100 10 15 27
1 2 1 2
3
100 30 20
1 2 1
*/

void printArr(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
struct data{
    int p;//profit
    int d;//dead line
    int j;//job no
};

void JobScheduling(int n,struct data dat[]){   
    cnt= 2+n;
    int mD=0,p_total=0;
    for(int i=0;i<n;i++){
        if(mD<dat[i].d) mD=dat[i].d;
        //cout<<dat[i].j<<" p: "<<dat[i].p<<" d: "<<dat[i].d<<endl;
    }
    cnt+= mD+2;
    int picked[mD];
    for(int i=0;i<mD;i++) picked[i]=-1;

//sort acording to highest profit
    cnt++;
    sort( dat,dat+n,[](struct data o1,struct data o2){ return o1.p>o2.p; } );
            
    for(int i=0;i<n;i++){
        cnt++;
        //cout<<dat[i].j<<" "<<dat[i].p<<" "<<dat[i].d<<endl;
        if(picked[dat[i].d-1] == -1){
            picked[dat[i].d-1] = i;
            cnt++;
            //printArr(picked,mD);
        }
        else{
            for(int j=dat[i].d-2 ; j>=0 ; j--){
                cnt++;
                if(picked[j] == -1){
                    cnt+=2;
                    picked[j] = i;
                    //printArr(picked,mD);
                    break;
                }
            }
        }
        
    }
    cnt+= 2*mD+1;
    for(int i=0;i<mD;i++){
        //print taken data and total profit
        cout<<"job no:"<<dat[picked[i]].j<<" profit:"<<dat[picked[i]].p<<" deadline:"<<dat[picked[i]].d<<endl;
        p_total+=dat[picked[i]].p;
    }
    cout<<"Total profit:"<<p_total<<endl; 
    cout<<"for n="<<n<<" statement count="<<cnt<<endl<<endl;   
}


int main(){
    cout<<"\nLab 4:(task 5-> job scheduling): \n"<<endl;
    int q;
    in>>q;
    while(q--){// !in.eof()
        {
            int n;
            in>>n;
            struct data dat[n];
            for(int i=0;i<n;i++) in>>dat[i].p;
            for(int i=0;i<n;i++) {in>>dat[i].d; dat[i].j=i+1;}
            JobScheduling(n,dat);
        }
        
    }
    
    in.close();
    return 0;
}