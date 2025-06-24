
// ____________________________________________ Brute Force in c++ _________________________________________________________________________
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        set<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            {
                for(int j=0;j<n;j++)
                {
                    if(abs(i-j)<=k )
                    {
                       temp.insert(j); 
                    }
                }
            }
        }
       vector<int>ans(temp.begin(),temp.end());
       return ans;

        
    }
};
// // ____________________________________________ Optimal in c++ _________________________________________________________________________
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==key)
            {
                int start=max(0,j-k);   // start 
                int end=min(n-1,k+j);   // end;
                if(ans.size()>0 && ans.back()>=start)  // means agar last ka array ans ka last element start se bada hoga tabhi dry run for nums[2,2,2,2,2,2] ,key =2 , k=2;
                {
                    start=ans.back()+1;
                }
                for(int i=start;i<=end;i++)   // intiliaze i= start;
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
        
    }
};
