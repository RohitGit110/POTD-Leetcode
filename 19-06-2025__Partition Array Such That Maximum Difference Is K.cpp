// Problem Name - Partition Array Such That Maximum Difference Is K;
// Problem Link -https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19
// Topic - Sorting ,Greedy

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // sort the array 
        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int required = nums[i] + k;  // maximum value 

            int j = i + 1;
            while (j < nums.size() && nums[j] <= required) {
                j++;
            }

            i = j - 1; // jump to the last element of this group
            count++;
        }

        return count;
    }
};

