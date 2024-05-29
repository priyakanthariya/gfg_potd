class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
        // code here
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            if (i - 1 >= 0 && dp[i - 1] == 0)
            {
                dp[i] = 1;
            }

            else if (i - x >= 0 && dp[i - x] == 0)
            {
                dp[i] = 1;
            }

            else if (i - y >= 0 && dp[i - y] == 0)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = 0;
            }
        }

        return dp[n];
    }
};