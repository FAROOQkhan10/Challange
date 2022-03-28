#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    getline(cin,s);

    int l=0,r=s.size()-1;
    while(l<=r){
        swap(s[l],s[r]);
        l+=1;
        r-=1;
        if(s[l]=='@' or s[l]=='#' or s[l]=='$'){
            l+=1;
        }
        if(s[r]=='@' or s[r]=='#' or s[r]=='$'){
            r-=1;
        }
    }

    cout<<s<<"\n";

}


