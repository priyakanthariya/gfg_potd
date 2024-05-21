class Solution {
private:
    unordered_map<string, string> parent;
    
    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(string x, string y) {
        parent[find(x)] = find(y);
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> owner;
        unordered_map<string, vector<string>> mergedAccounts;
        
        // Initialize parent pointers
        for (auto& acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                parent[acc[i]] = acc[i];
                owner[acc[i]] = acc[0];
            }
        }
        
        // Merge accounts
        for (auto& acc : accounts) {
            string p = find(acc[1]);
            for (int i = 2; i < acc.size(); ++i) {
                Union(acc[i], p);
            }
        }
        
        // Group emails by their representative
        for (auto it = parent.begin(); it != parent.end(); ++it) {
            string rep = find(it->first);
            mergedAccounts[rep].push_back(it->first);
        }
        
        // Construct the result
        vector<vector<string>> result;
        for (auto it = mergedAccounts.begin(); it != mergedAccounts.end(); ++it) {
            vector<string>& emails = it->second;
            sort(emails.begin(), emails.end());
            vector<string> account = { owner[emails[0]] };
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        
        return result;
    }
};