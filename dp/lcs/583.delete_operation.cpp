// https://leetcode.com/problems/delete-operation-for-two-strings/?


class Solution {
public:
    int minDistance(string text1, string text2) {
        if(text1==text2)return 0 ; 
        int n = text1.size();
        int m = text2.size();
        
              vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return ( n- dp[text1.size()][text2.size()] )+(m-dp[text1.size()][text2.size()]);

    }
};
