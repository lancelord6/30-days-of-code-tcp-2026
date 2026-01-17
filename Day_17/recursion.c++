class Solution 
{
public:
    long long MOD = 1e9 + 7;

    long long solve(long long base, long long exp) 
    {
        if (exp == 0) 
        {
            return 1;
        }
        
        long long res = solve(base, exp / 2);
        res = (res * res) % MOD;
        
        if (exp % 2 != 0) 
        {
            res = (res * base) % MOD;
        }
        
        return res;
    }

    int countGoodNumbers(long long n) 
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        
        long long first = solve(5, even);
        long long second = solve(4, odd);
        
        return (int)((first * second) % MOD);
    }
};