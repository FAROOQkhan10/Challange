#include<bits/stdc++.h>
using namespace std;


void display(vector<int>&dp){
     for(auto t:dp) cout<<t<<" ";
     cout<<endl;
}

int climb(int n){
    int a=1,b=1;
    for(int i=1;i<=n;i++){
        int c = a+b;
        a=b;
        b=c;
    }
   return a;

}


int fib(int n,vector<int>&dp){
    if(n==0) return 0;
    if(n==1) return 1;
    
    if(dp[n]!=-1) return dp[n];
 

   int ans = fib(n-1,dp) +  fib(n-2,dp);
   return dp[n] = ans; 
}

int min_stairs(int n,vector<int>&dp,vector<int>&cost){
        
        
        if(n<=1) return dp[n]=cost[n];
        
        if(dp[n]!=0) return dp[n];
        
        return  dp[n]=min(min_stairs(n-1,dp,cost),min_stairs(n-2,dp,cost)) + cost[n];
        
    }

  int min_stairs_tabu(int n,vector<int>&dp,vector<int>&cost){
        
        for(int i=0;i<=n;i++){

         
        if(n<=1) {dp[i]=cost[i];continue;}
        
         dp[i]=min(dp[i-1],dp[i-2]) + cost[i];
        }
        return dp[n];
    }  
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        cost.push_back(0);
        vector<int>dp(n+1,0);
        int ans = min_stairs_tabu(n,dp,cost);
        display(dp);
        return ans;
        
    }

int main(){
//   int n; cin>>n;
//   vector<int>dp(n+1,-1);
//   cout<<fib(n,dp)<<endl;
   
//    cout<<climb(n);

vector<int> cost = {10,15,20};
cout<<minCostClimbingStairs(cost)<<endl;


}