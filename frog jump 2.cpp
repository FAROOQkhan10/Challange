#include<bits/stdc++.h>
using namespace std;


int jump_tabu(vector<int>&v,int n,int k){
 
    if(n==0) return 0;  

   vector<int> dp(n,0);
   dp[0] = 0;

   for(int i=1;i<n;i++){     
       int mini = INT_MAX;
      for(int j=1;j<=k;j++){ 
        if(i-j>=0){ 
         int jump_k = dp[i-j] + abs(v[i]-v[i-j]);  
          mini = min(mini,jump_k); 
      }
    }
    dp[i]=mini; 
  }
   return dp[n-1];
}



int jump_memo(vector<int>&v,int n,int k,int dp[]){
 
    if(n==0) return 0;
    int mini = INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=k;i++){
 
      if(n-i>=0){
 
        int jump_k = jump_memo(v,n-i,k,dp) + abs(v[n]-v[n-i]);  
        mini = min(mini,jump_k); 
      }
    }
  return dp[n]=mini;  
}


int main(){

    int n,k; cin>>n>>k;

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
   
    //Memoization

    // int dp[n];
    // memset(dp,-1,sizeof(dp));
    // cout<<jump_memo(v,n-1,k,dp);

    // Tabulation

    cout<<jump_tabu(v,n,k);
   


}