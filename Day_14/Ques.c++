class Solution 
{
  public:
    int power(int n) {
        if (n <= 0) return 0;
        int left = 0, right = 30;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)pow(2, mid) <= (long long)n) {
                ans = mid;
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    int setBits(int n) {
        int c = 0;
        long long tempN = n; 
        
        while (tempN > 0) {
            int a = power(tempN);
            c++;
            tempN -= (long long)pow(2, a);
        }
        return c;
    }
};