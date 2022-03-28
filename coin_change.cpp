#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int coin_change(vi & cost,int k){
    if(k==0) return 1;
    if(k<0) return 0;
    int count=0;
    for(int i=0;i<cost.size();i++){
          count+=coin_change(cost,k-cost[i]);
        }  
    return count;
}

// int coin_change(vi & cost,int k,vi & dp){
//     if(k==0) return 1;
//     if(k<0) return 0;
//     int count=0;

//     // if()

//     for(int i=0;i<cost.size();i++){
//           dp[i]+=coin_change(cost,k-cost[i]);
//         }
//     return count;
// }

int main(){
    
    vi cost={1,2,3};
    // vi dp(cost.size()+1,0);
    cout<<coin_change(cost,4);
    

}


