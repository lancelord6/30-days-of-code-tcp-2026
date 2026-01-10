class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
         int max=(*std::max_element(arr.begin(),arr.end()));
    vector<int> hash(max + 1,0);
    int k=0;
    for(int i=0;i<arr.size();i++)
    {
        hash[arr[i]]=hash[arr[i]] +1;  
    }
    for(int i=0;i<=max;i++)
    {
        for(int j=0;j<hash[i];j++)
        {
            arr[k]=i;
            k++;
        }
    }
    }
};