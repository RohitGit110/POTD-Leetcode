// PROBLEM NAME 
// PROBLEM NAME 

class Solution {
public:
    int maxDistance(string s, int k) {
        int result=INT_MIN;
        int N=0;
        int S=0;
        int W=0;
        int E=0;
        int curr=0;
        int count=0;
        int wasted=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='N')
            {
                N++;
            }
            else if(s[i]=='S')
            {
                S++;
            }
            else if(s[i]=='W')
            {
                W++;
            }
            else if(s[i]=='E')
            {
                E++;
            }
             curr=abs(W-E)+ abs(N-S);
             count=i+1;
             wasted=count-curr;
             int extra=0;
             if(wasted!=0)
             {
                extra=min(2*k,wasted);
             }
             int add=extra+curr;
             result=max(result,add);

            

        }
        return result;
    }
};
