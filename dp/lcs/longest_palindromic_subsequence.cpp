// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/1946231721/
class Solution {
public:
    int minInsertions(string s) {
        string text1=s ; 
       reverse(s.begin(),s.end());
        string text2= s;
         vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return text1.size()-dp[text1.size()][text1.size()];
    }
};
