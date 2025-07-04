// Problem Name  Find the K-th Character in String Game II
  // copy ans paste 
class Solution {
public:
    
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> powof2(51,1);
        for (int i = 1; i< 51 ;i++){
            powof2[i]=powof2[i-1]*2;
        }
        long long num = k-1;
        int ans  = 0;
        while (num>0){
            int i = 0 ;
            while(powof2[i+1]<=num) i++;
            if(operations[i]==1) {
                ans = (ans+1)%26;
            }
            num = (num%powof2[i]);
        }
        return ans+'a';
    }
};
