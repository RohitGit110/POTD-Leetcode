// Problem Name  2138. Divide a String Into Groups of Size k
// TOPIC         MATH+ARRAY



class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
       int value=s.size()%k;
       int first=s.size()-value;

        for(int i=0;i<first;i+=k)
        {
            string temp=s.substr(i,k);
            ans.push_back(temp);
           
        }
        if(s.size()%k==0)
        {
            return ans;
        }
        else
        {
            int rem=s.size()%k;
            int index=s.size()-rem;
            string temp;
            for(int i=index;i<s.size();i++)
            {
                temp.push_back(s[i]);

            }
            int time=k-rem;
            for(int i=0;i<time;i++)
            {
                temp.push_back(fill);

            }
            ans.push_back(temp);

            
        }
        return ans;
        
    }
};
