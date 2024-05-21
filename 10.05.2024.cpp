class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(arr.begin(), arr.end());
        findCombinations(arr, result, combination, k, 0);
        return result;
    }

private:
    void findCombinations(const vector<int>& arr, vector<vector<int>>& result, vector<int>& combination, int target, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < arr.size() && arr[i] <= target; ++i) {
            if (i > start && arr[i] == arr[i - 1])
                continue;
            
            combination.push_back(arr[i]);
            findCombinations(arr, result, combination, target - arr[i], i + 1);
            combination.pop_back();
        }
    }
};