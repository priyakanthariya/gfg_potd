class Solution{
public:
     int lcs(string& s, string& r, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == r[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][n];
    }
    
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string r = str;
        reverse(r.begin(), r.end());
        
        int lcsLength = lcs(str, r, n);
        
        int rem = n - lcsLength;
        return rem <= k;
    }
};