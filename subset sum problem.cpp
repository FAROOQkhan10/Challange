#include<bits/stdc++.h>
using namespace std;
 
int target_tabu(vector<int>&v,int n,int sum){

    vector<vector<int>> dp(n,vector<int>(sum+1));
    
    for(int i=0;i<n;i++) dp[i][0] = 1;

    if(v[0]<=sum)
      dp[0][v[0]]=1;


    for(int i=1;i<n;i++){
       for(int j=1;j<=sum;j++){

         int picked=0;
         if(v[i]<=j)
            picked = dp[i-1][j-v[i]];

          int unpicked = dp[i-1][j];

        dp[i][j] = picked || unpicked;

       }
    }
  return dp[n-1][sum];

}

int target_memo(vector<int>&v,int n,int sum,vector<vector<int>> &dp){

   if(sum==0) return 1;
   if(n==0) return v[n] == sum;

   if(dp[n][sum]!=-1) return dp[n][sum];

   int unpicked = target_memo(v,n-1,sum,dp);

   int picked=0;
   if(v[n]<=sum)
      picked = target_memo(v,n-1,sum-v[n],dp);
   
  return dp[n][sum]=picked || unpicked;
 
}


int main(){
   int n,sum; cin>>n>>sum;
   vector<int>v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   
   // vector<vector<int>> dp(n,vector<int>(sum+1,-1));

   // cout<<target_memo(v,n-1,sum,dp);

  cout<<target_tabu(v,n,sum);

}