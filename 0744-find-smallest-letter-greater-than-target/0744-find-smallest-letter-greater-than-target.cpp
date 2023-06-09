class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
         for(auto itr : l){
             if(itr>t)
                  return itr;
         }
        return l[0];
    }
};