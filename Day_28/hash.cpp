class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        unordered_map<int, int> count;
        count[0] = 1; 
        int currentOddCount = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] % 2 != 0) 
            {
                currentOddCount++;
            }
            if (count.find(currentOddCount - k) != count.end()) 
            {
                ans += count[currentOddCount - k];
            }
            count[currentOddCount]++;
        }
        return ans;
    }
};