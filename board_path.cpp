#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;



int boardPath(int s,int e,vi & dp){

   if(s==e) return dp[s]=1;

   if(dp[s]!=0) return dp[s];
   int count=0;
   for(int dice=1;dice<=6 and dice+s<=e; dice++){
       count+=boardPath(s+dice,e,dp);
   }
   return dp[s]=count;
}


int main(){
    vi dp(11,0);
    cout<< boardPath(0,10,dp);

}


