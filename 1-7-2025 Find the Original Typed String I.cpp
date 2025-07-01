// Problem Name Find the Original Typed String I
class Solution {
public:
    int possibleStringCount(string word) {
        int count=1;    
        for(int i=1;i<word.size();i++)   // if element is same then count ++ otherwise not 
        {
           if(word[i]==word[i-1])    
           {
            count++;
           }
        }
        return count;

        
    }
};
