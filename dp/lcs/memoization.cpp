#include<bits/stdc++.h>
using namespace std;
int lcs(string str1, string str2, int i , int j,vector<vector<int>>&dp){
if(i>=str1.size()||j>=str2.size())return 0 ; 
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j]){
    return dp[i][j]= 1+ lcs(str1,str2,i+1,j+1,dp);
    }
    return dp[i][j]= max(
    lcs(str1,str2,i+1,j,dp),
    lcs(str1,str2,i,j+1,dp)
    );
}
int main(){
    string str1="udit";
    string str2="u12d12i12t";
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
    cout<<lcs(str1 ,str2,0,0,dp);
    
}
