#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    double current_sum = 0;
    for (int i = 0; i < k; i++) 
    {
        current_sum += a[i];
    }
    double total_sum = current_sum;
    for (int i = k; i < n; i++) 
    {
        current_sum += a[i] - a[i - k];
        total_sum += current_sum;
    }
    double result = total_sum / (n - k + 1);
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}