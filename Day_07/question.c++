class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums)
    {
        int i,s=0;
        for(i=0;i<nums.size();i++)
        {
            s=s+encrypt(nums[i]);
        }
        return s;
    }
    int encrypt(int n)
    {
        int a=0,b=0,c;
        while (n>0)
        {
            if(a<(n%10))
            a=n%10;
            n=n/10;
            b++;
        }
        c=0;
        while(b>0)
        {
            c=c*10 +a;
            b--;
        }
        return c;
    }

};