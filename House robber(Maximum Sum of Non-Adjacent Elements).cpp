#include<bits/stdc++.h>
using namespace std;

int robber_tabu(vector<int>&v,int n){
  
  vector<int>dp(n,0);

  dp[0] = v[0];

  for(int i=1;i<n;i++){
    
    int rob1 = v[i];
    
    if(i>1)  rob1 = v[i] + dp[i-2];
    int rob2 = dp[i-1];
   
    dp[i] = max(rob1,rob2);       

  }
  return dp[n-1];

}



int robber_memo(vector<int>&v,int n,int dp[]){
    
    if(n==0) return v[n];  

    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    int rob1 = v[n] + robber_memo(v,n-2,dp);
    int rob2 = robber_memo(v,n-1,dp);
    
    return dp[n]=max(rob1,rob2);
}

int main(){

    int n; cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
   
    // int dp[n]; memset(dp,-1,sizeof(dp));

    // cout<<robber_memo(v,n-1,dp);  
   
   cout<<robber_tabu(v,n);

}