class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        // code here
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); 
        int left = pos - 1;
        int right = pos;

        if (right < n && arr[right] == x)
        {
            right++;
        }

        vector<int> result;

        while (k > 0)
        {
            if (left >= 0 && right < n)
            {
                if (abs(arr[left] - x) <= abs(arr[right] - x))
                {
                    if (abs(arr[left] - x) == abs(arr[right] - x))
                    {
                        result.push_back(arr[right]);
                        right++;
                    }
                    else
                    {
                        result.push_back(arr[left]);
                        left--;
                    }
                }
                else
                {
                    result.push_back(arr[right]);
                    right++;
                }
            }
            else if (left >= 0)
            {
                result.push_back(arr[left]);
                left--;
            }
            else if (right < n)
            {
                result.push_back(arr[right]);
                right++;
            }
            k--;
        }

        return result;
    }
};