#include<bits/stdc++.h>
using namespace std;
 
int knapsack_tabu(vector<int>&wt,vector<int>&val,int W,int n){
       
   vector<vector<int>> dp(n+1,vector<int>(W+1));
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){
     
       if(i==0 or j==0) dp[i][j]=0;
       else if(wt[i-1]<=j) dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);

       else dp[i][j] = dp[i-1][j];
    }
  }
   
 return dp[n][W];

}



// int knapsack_memo(int W, vector<int>&wt,vector<int>&val, int n,vector<vector<int>>&dp){
        
         
//        if(n==0 or W==0) return 0;
       
//        else if(dp[n][W]!=-1) return dp[n][W];
       
//        else if(wt[n-1]<=W){
           
//            int consider = val[n-1] + knapsack_memo(W-wt[n-1],wt,val,n-1,dp);
//            int not_consider = knapsack_memo(W,wt,val,n-1,dp);
           
//           return dp[n][W]=max(consider,not_consider);
//        } 
          
//       else if(wt[n-1]>W )
//         return dp[n][W]=knapsack_memo(W,wt,val,n-1,dp);        
        
//     }



int main(){
   int n; cin>>n; 
   vector<int>wt(n),v(n);
   int W; cin>>W;
   
   vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

   for(int i=0;i<n;i++) cin>>v[i]; 
   for(int i=0;i<n;i++) cin>>wt[i];
   
   // cout<<knapsack_memo(W,wt,v,n,dp);

  cout<<knapsack_tabu(wt,v,W,n);



}