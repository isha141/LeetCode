class Solution {
public:
    int strStr(string hay, string needle) {
       auto itr=hay.find(needle);
        if(itr!=string::npos)
             return itr;
        return -1;
    }
};