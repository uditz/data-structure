/*
unbounded knapsack 
eg ek element array ka kitni bhi baar use ho skata h to get the solution 
used when no limit to get it for element 
 */
class Solution {
public:
    //unbounded knapsack 
    //dp+ memoization 
    /*
    base cases 
     if(target==0)return 0 ; 
     if(i>size || target<0)return maximum
     dp[squares[i]][target]
    */
    int helper(int i , vector<int>squares, vector<vector<int>>&dp,int target){
        if(target==0)return 0 ; 
        if(i>=squares.size() || target<0)return 1e9;
        if(dp[i][target]!=-1)return dp[i][target];
        int take =1+ helper(i,squares,dp , target-squares[i]);
        int leave= helper(i+1, squares,dp,target);
        return dp[i][target]=min(take,leave);
    }

    //bottom up using 2d array 
    int bottom2D(int n ){
          vector<int>squares;
        for(int i=1 ;i*i<= n;i++){
            if((i*i)<=n)squares.push_back(i*i);
        }
    
        vector<vector<int>>dp(squares.size()+1,vector<int>(n+1,0));
        // return helper(0,squares,dp,n);
        /*
        dekh jese upr m base case m likha h if(target =0)return 0 to wahi squares m bhi kia h 
        sari values jidar target 0 h usko 0 kardi 
        wahi kia h squares[i] k sath usko maximum kardi h jidr bhi value squares[i]==0 h 
        becuase it is a base condition 
        */
        for(int i=0 ;i<squares.size();i++){
            dp[i][0]=0;
        }
        for(int i=0 ;i<=n ;i++){
            dp[0][i]=INT_MAX-1000;
        }
        for(int i=1;i<=squares.size();i++){
            for(int j=1;j<=n;j++){
                if(squares[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-squares[i-1]],dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[squares.size()][n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1 , 1e9);
        dp[0]=0; 
        for(int i=1 ;i<dp.size();i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
