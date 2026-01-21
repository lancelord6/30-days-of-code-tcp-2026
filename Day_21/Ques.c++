class Solution 
{
public:
    int find(vector<int>& arr, int n)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==n)
            {
                return i;
            }
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        for (int i=0;i<nums1.size();i++)
        {
            int startIdx=find(nums2, nums1[i]);
            int found=-1;
            for (int j=startIdx+1;j<nums2.size();j++)
            {
                if(nums2[j]>nums1[i])
                {
                    found=nums2[j];
                    break;
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};