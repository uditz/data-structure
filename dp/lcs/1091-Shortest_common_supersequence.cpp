// https://leetcode.com/problems/shortest-common-supersequence/
/*
bhai thoda tricky question h pehele toh lcs toh find karna hi h fir jo lcs dp ka table h usse hame backtrack krna h 
like table for the st1= "abac" and str2="cab" in lcs dp ka jo table ho ga wo aisa hoga
0  0  0  0  
0  0  1  1  
0  0  1  2  
0  0  1  2  
0  1  1  2 
ab dp[n][m] se start karenge thik h 
hame piche jana h 3 condition dekhte hue 
//backtracking the answer 
1. str1[i-1]==str2[j-1] toh sida str1[i-1] ki value push kardo answer string m 
2. dp[i-1]<=dp[j-1] str2[j-1] ko push karenge
3. else wahi str1[i-1] ko 
ab jo bache hue i or j honge unko push karlenege while(i>0) se 
reverse kardegene string as we are backtracking ofc 
that's ans
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1==str2)return str1;
      if(str1==str2)return str1;
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i = n ; 
        int j = m ; 
        string s;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{ 
                if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(str2[j-1]);
                j--;
            }
            else {
                s.push_back(str1[i-1]);
                i--;
            }
            }
        } 
     while(i>0){
         s.push_back(str1[i-1]);
         i--;
     }
     while(j>0){
         s.push_back(str2[j-1]);
         j--;
}
     reverse(s.begin(),s.end());
     
     
     return s; 
    }
};
