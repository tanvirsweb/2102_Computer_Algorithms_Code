#include<bits/stdc++.h>
using namespace std;
//problem 1
int cnt,cnt2,cnt3;
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

struct Item{
    double value,weight;
    // double vpw;//value per weight
};
void fractionKnapsack(int n,int w,struct Item arr[]){//total weight that can be taken
    cnt+=2;
    sort(arr,arr+n,[](struct Item o1,struct Item o2){ return (o1.value/o1.weight)>(o2.value/o2.weight); });
    double finalValue=0.0;

    for(int i=0;i<n;i++){
        cnt++;
        if(arr[i].weight <= w){

            cout<<"X:"<<1<<" \tweight:"<<arr[i].weight<<" \tvalue:"<<arr[i].value<<endl;

            cnt+=2;
            w-=arr[i].weight;
            finalValue +=arr[i].value;
            //if remaining weight capacity > weight of this item ---> take whole item
            //else take fraction of that item as much as possible.

            
        }
        else{

            cout<<"X:"<<w<<"/"<<arr[i].weight<<" \tweight:"<<w<<" out of:"<<arr[i].weight<<" \tvalue:"<<(arr[i].value/arr[i].weight)*w<<endl;
            cnt+=2;
            finalValue += (arr[i].value/arr[i].weight)*w;//left remaining_weight_capacity*profit_valuePerWeight of that product
            
            break;
        }
    }
    cnt+=2;
    cout<<"Total profit(taking maximum p/w):"<<finalValue<<endl;
    cout<<"n="<<n<<" statement count: "<<cnt<<"\n\n";
    // Time Complexity: O(N * log N)
    // Auxiliary Space: O(N)
    
}

int main(){    
    ifstream in("knapsackN.txt");
    while(!in.eof()){// !in.eof() works better instead of q
        {//begining of new scope
        int n,w;
        in>>n>>w;
        //cout<<"n="<<n<<" w="<<w<<endl;
        //struct Item *arr=new struct Item[n];
        struct Item arr[n];
        for(int i=0;i<n;i++) in>>arr[i].weight;
        for(int i=0;i<n;i++) in>>arr[i].value;
        
                //cout<<arr[i].value<<" "<<arr[i].weight<<endl;
                // arr[i].vpw =1.0*arr[i].value/arr[i].weight;
        
        fractionKnapsack(n,w,arr);
        kanpsack_feasible1(n,w,arr);
        kanpsack_feasible2(n,w,arr);
        //delete[] arr;
        }//end scope -->after this arr[] will be destroyed.in next iteration new arr[n] will be created
        
    }
    
    in.close();
    return 0;
}