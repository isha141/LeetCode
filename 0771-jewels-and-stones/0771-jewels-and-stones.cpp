class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int n=j.size();
        int m=s.size(); 
        int c=0;
        for(int i=0;i<n;++i){
            c+=count(s.begin(),s.end(),j[i]);
        }
        return c;
    }
};