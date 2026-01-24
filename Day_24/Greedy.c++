#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    long long d;
    if (!(cin >> n >> d)) return 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<int>());
    int wins = 0;
    int remaining_players = n;
    for (int i = 0; i < n; i++) 
    {
        long long needed = (d / p[i]) + 1;
        if (remaining_players >= needed) 
        {
            wins++;
            remaining_players -= needed;
        }
        else 
        {
            break;
        }
    }
    cout << wins << endl;
    return 0;
}