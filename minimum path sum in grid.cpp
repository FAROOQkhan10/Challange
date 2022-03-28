#include<bits/stdc++.h>
using namespace std;

int min_path_tabu(int n,int m, vector<vector<int>>&v){
 vector<vector<int>> dp(n,vector<int>(m));
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          
            if(i==0 and j==0) dp[i][j] = v[i][j];
            
            else{
                int up=v[i][j];
                if(i>0) up += dp[i-1][j];
                else up +=1e9;
                
                int left = v[i][j];
                if(j>0) left += dp[i][j-1];
                else left +=1e9;

                dp[i][j] = min(left,up);
             }
        }
  }
   return dp[n-1][m-1];

}


int min_path_memo(int n,int m, vector<vector<int>>&v,vector<vector<int>>&dp){

    if(n==0 and m==0) return v[n][m];
    
    if(n<0 or m<0) return 1e9;
   
    if(dp[n][m]!=-1) return dp[n][m];
  
    int up = v[n][m] + min_path_memo(n-1,m,v,dp);
    int left = v[n][m] + min_path_memo(n,m-1,v,dp);
    return dp[n][m]=min(up,left);
} 


int main(){
     int n,m;
     cin>>n>>m;
      vector<vector<int>> v(n,vector<int>(m));

    for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++){
           cin>>v[i][j];
       }
    }
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<min_path_memo(n-1,m-1,v,dp);
    

    // Tabulation
    cout<<min_path_tabu(n,m,v);

}