// Problem Name Longest Harmonious Subsequence
// Topic    Hashtable+Math+sliding window

// in c++ using Hashtable 
class Solution {
public:
    int findLHS(vector<int>& nums) {
         map<int,int>m;   
    for(int i=0;i<nums.size();i++)
    {
        m[nums[i]]++;
    }
    int previous_first=0;
    int previous_second=0;
    bool flag=true;
    int value=0;
    int maximum=0;
    for(auto it:m)
    {
       if(flag==true)
       {
           previous_first=it.first;
           previous_second=it.second;
           flag=false;
           continue;
       }
      if(flag==false && it.first-previous_first==1)
      {
          value=previous_second+it.second;
          
      }
      maximum=max(maximum,value);
      previous_first=it.first;
      previous_second=it.second;
       
       
    }
    return maximum;
        
    }
};
// _________________________________________________USING SLIDING WINDOW ________________________________________________________- IN C++ _______________________________________________
class Solution {
public:
    int findLHS(vector<int>& nums) {
         sort(nums.begin(),nums.end()); // sort the array because we apply the sliding window 
    int first=0;      // first index point 
    int second=first+1;  // second index point 
    int maximum=0;     // store the longest subsequence 
    while(second<nums.size())
    {
        while(nums[second]-nums[first]>1)//  1,3,2,2,5,2,3,7 dry run on this output 
        {
            first++;
        }
        if(nums[second]-nums[first]==1)// if differnce of two value is one then count 
       {
           maximum=max(maximum,second-first+1);
       }
       second++;    // all time second is increasing 
    }
    return maximum;
        
    }
};
