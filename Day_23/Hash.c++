class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for(char c:s) 
        {
            freq[c]++;
        }
        vector<pair<int,char>> v;
        for (auto const& [ch, count] : freq) 
        {
            v.push_back({count, ch});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string res="";
        for (auto const& p:v) 
        {
            res.append(p.first, p.second);
        }
        return res;
    }
};