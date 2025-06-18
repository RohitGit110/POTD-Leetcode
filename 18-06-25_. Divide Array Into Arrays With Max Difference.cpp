// 🔗 Problem: 2966. Divide Array Into Arrays With Max Difference
// 📝 Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
// ✅ Status: Solved ✅
// 💡 Approach:  Array +sorting 




class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());// sorting first because of without sorting not possible to solve this 
        vector<vector<int>>temp;  // in question said that return in 2D Matrix
        for(int i=0;i<nums.size();i+=3)
        {
            if(i+2<nums.size() &&  (abs(nums[i]-nums[i+1])<=k && abs(nums[i]-nums[i+2])<=k && abs(nums[i+1]-nums[i+2])<=k))// this part is main logic why 
            {
                temp.push_back({nums[i],nums[i+1],nums[i+2]});
                
            }
            else
            {
                return {};
            }
        }
        return temp;
        
    }
};
