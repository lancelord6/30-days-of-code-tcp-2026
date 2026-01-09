class Solution {
public:
    string largestOddNumber(string num)
    {
        int a=num.size()-1,n=1;
        while(n!=0)
            {
                if(num.empty())
                    return "";
                
                else if((num[a]-0)%2==0)
                {
                   num.pop_back();
                    a--;
                }
                
                
                else
                    return num;
            }
        return "";
    }
};