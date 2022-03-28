#include<bits/stdc++.h>
using namespace std;

// tabulation

int jump(int n,vector<int>&v,int dp[]){

   int jump2 = INT_MAX; 
   
   for(int i=1;i<n;i++){
  
   int jump1 = dp[i-1] + abs(v[i]-v[i-1]);
   if(i>1)
       jump2 = dp[i-2] + abs(v[i]-v[i-2]);
   
    dp[i] = min(jump1,jump2);    


   }
 return dp[n-1];
   
}



// memoization 
// int jump(int n,vector<int>&v,int dp[]){
   
//    if(n==0) return 0;

//    int jump2 = INT_MAX; 
   
//    if(dp[n]!=-1) return dp[n];

//    int jump1 = jump(n-1,v,dp) + abs(v[n]-v[n-1]);
//    if(n>1)
//      jump2 = jump(n-2,v,dp) + abs(v[n]-v[n-2]);
   
//    return dp[n] = min(jump1,jump2);

  
// }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
   int n; cin>>n;

   vector<int>v(n);
   for(int i=0;i<n;i++) cin>>v[i];

// memoization
//   int dp[n+1]; memset(dp,-1,sizeof(dp));
//   cout<<jump(n-1,v,dp);

//  Tabulation
   int dp[n]; memset(dp,0,sizeof(dp));
   cout<<jump(n,v,dp);


}