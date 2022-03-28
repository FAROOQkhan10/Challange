#include<bits/stdc++.h>
using namespace std;
 
int triangle_tabu(int n,vector<vector<int>>&v){

   vector<vector<int>> dp(n,vector<int>(n));


   for(int j=n-1;j>=0;--j) dp[n-1][j] = v[n-1][j];

   for(int i=n-2;i>=0;i--){
       for(int j=i;j>=0;j--){
           int down = v[i][j] + dp[i+1][j];
           int diagonal = v[i][j] + dp[i+1][j+1];
           dp[i][j] = min(down,diagonal);
       }
   }  
   return dp[0][0];
}

int triangle_memo(int i,int j,int n,vector<vector<int>>&v,vector<vector<int>>&dp){
      
    if(i==n-1) return v[n-1][j];
   
    if(dp[i][j]!=-1) return dp[i][j];

    int down = v[i][j] + triangle_memo(i+1,j,n,v,dp);
    int diagonal = v[i][j] + triangle_memo(i+1,j+1,n,v,dp);

    return dp[i][j] = min(down,diagonal);

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>v[i][j];
        }
    }
    // Memoization 

    // vector<vector<int>> dp(n,vector<int>(n,-1));
   
    // cout<<triangle_memo(0,0,n,v,dp);

    // Tabulation

    cout<<triangle_tabu(n,v);


}