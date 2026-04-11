# Coin Change (Minimum Coins)

```cpp

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        
        // dp matrix
        vector<vector<int>> dp(n+1, vector<int> (sum+1));
        
        // initialization 
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                
                    if(i == 0 && j == 0)
                        dp[i][j] = INT_MAX - 1;
                        
                    else if(i == 0)
                        dp[i][j] = INT_MAX - 1;
                    
                    else if(j == 0)
                        dp[i][j] = 0;
                
            }
        }
        
        // initialize the 2nd row
        for(int j=1;j<=sum;j++) {
            
            if(j % coins[0] == 0)
                dp[1][j] = j/coins[0];
                
            else 
                dp[1][j] = INT_MAX - 1;
            
        }
        
        // main condition
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                
                if(coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        return dp[n][sum] == INT_MAX-1 ? -1 : dp[n][sum];
        
    }
};

```