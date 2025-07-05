// Problem Name    1394. Find Lucky Integer in an Array
// Topic           Array 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        int maximum=-1;
        for(auto it:m)
        {
            if(it.first==it.second)
            {
                maximum=max(maximum,it.first);
            }
        }
        return maximum;
        
    }
};
