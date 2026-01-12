class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left=0,mid=0,right= nums.size()-1,l,r;
        while(left<=right)
        {
            mid= left + (right-left)/2;
            if(nums[mid]==target)
            {
                l=mid;
                r=mid;
                while(l>0 && nums[l-1]==target)
                {
                    l--;
                }
                while(r<right && nums[r+1]==nums[mid])
                {
                    r++;
                }
                return {l,r};
            }
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
        }
        return {-1,-1};
    }
};