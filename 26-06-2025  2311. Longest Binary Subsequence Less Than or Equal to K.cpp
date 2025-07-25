// Problem Name 2311. Longest Binary Subsequence Less Than or Equal to K
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        
        return length;
    }
};
