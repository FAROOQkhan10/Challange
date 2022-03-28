#include<bits/stdc++.h>
using namespace std;

int find_path_tabu(int m,int n){
      
   int dp[m][n];

   for(int i=0;i<m;i++){
       for(int j=0;j<m;j++){
 
         if(i==0 and j==0) dp[i][j]=1;
         else{
             int left=0,up=0;
            
             if(i>0) up=dp[i-1][j];
             if(j>0) left=dp[i][j-1]; 
             dp[i][j] = up+left;
         }
       }
   }
   
   return dp[m-1][n-1];


}



int find_path_memo(int m,int n,int dp[100][100]){

   if(m==0 and n==0) return 1;

   if(m<0 or n<0) return 0;

   if(dp[m][n]!=-1) return dp[m][n];

   int up = find_path_memo(m-1,n,dp);
   int left = find_path_memo(m,n-1,dp);

   return dp[m][n] = up + left;
}

int main(){

    int n,m;
    cin>>m>>n;
    // memoization
    // int dp[100][100]; memset(dp,-1,sizeof(dp));
    // cout<<find_path_memo(m-1,n-1,dp);
    
    // Tabulation
    cout<<find_path_tabu(m,n);    
  

}