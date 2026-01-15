class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) 
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    ll lcm(ll a, ll b)
    {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) 
    {
        ll la = a, lb = b, lc = c;
        ll lab = lcm(la, lb);
        ll lbc = lcm(lb, lc);
        ll lac = lcm(la, lc);
        ll labc = lcm(lab, lc);

        ll left = 1, right = 2e9;
        ll ans = right;

        while (left <= right) 
        {
            ll mid = left + (right - left) / 2;
            ll count = mid/la + mid/lb + mid/lc - lab - lbc - lac + labc; 
            ll actualCount = mid/la + mid/lb + mid/lc - mid/lab - mid/lbc - mid/lac + mid/labc;
            if (actualCount >= n)
            {
                ans = mid;
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return (int)ans;
    }
};