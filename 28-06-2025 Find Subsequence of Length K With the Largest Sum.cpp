// Problem Name Find Subsequence of Length K With the Largest Sum
// Topic Name Array + Hasmap 
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>temp(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        int index=nums.size()-k;
        for(int i=index;i<nums.size();i++)
        {
            m[nums[i]]++;

        }
        vector<int>ans;
        for(int i=0;i<temp.size();i++)
        {
            if(m.find(temp[i])!=m.end() && m[temp[i]]>0)
            {
                  ans.push_back(temp[i]);
                  m[temp[i]]--;
            }
        }
        return ans;

        
    }
};
