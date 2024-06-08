class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        int low = 0, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr1[mid] == arr2[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};