#include<bits/stdc++.h>

using namespace std;

int dp[501][501];

int lcs(vector<int>&v1,vector<int>&v2,int n,int m){

   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           if(i==0 or j==0) dp[i][j]=0;

           else if(v1[i-1]==v2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
           else dp[i][j]  = max(dp[i-1][j],dp[i][j-1]);

       }
   }
   return dp[n][m];

}


int main(){

   vector<int>v1={1,3,7,1,7,5};
   vector<int>v2={1,9,2,5,1};

   cout<<lcs(v1,v2,v1.size(),v2.size());
   cout<<endl;

}