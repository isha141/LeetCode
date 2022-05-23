class Solution {
public:
    int titleToNumber(string col) {
        int num=0;
        for(auto itr: col)
        {
            num=num*26+(itr-'A'+1);
        }
        return num;
    }
};