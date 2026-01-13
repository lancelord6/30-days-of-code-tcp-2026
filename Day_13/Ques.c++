class Solution {
public:
   int hours(vector<int>& piles, int s)
    {
        int h=0;
        for(int i=0;i<piles.size();i++)
        {
            h += (1LL * piles[i] + s - 1) / s;
        }
        return h;
    }
  
    

    int minEatingSpeed(vector<int>& piles, int h) 
    {   
        long long right=*std::max_element(piles.begin(), piles.end());   
        long long mid=0,left=1;
        while(left!=right)
        {
            mid=left+(right-left)/2;
            if(hours(piles,mid)<=h)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return (int)left;
    }

    
    
};