class Solution {
public:
    int strStr(string hay, string s) {
        int n=hay.size();
        auto ind=hay.find(s); 
        if(ind!=string::npos){
            return ind;
        }
        return -1;
    }
};