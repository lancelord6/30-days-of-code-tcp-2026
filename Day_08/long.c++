class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int result = 1;
        int streak = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                streak++;
            } else if (nums[i] != nums[i - 1]) {
                streak = 1;
            }
            if (streak > result) result = streak;
        }

        return result;
    }
};