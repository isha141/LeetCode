class Solution {
public:
    int minimumMoves(string s) {
        int i=0;
        int n=s.size();
        int count=0;
        while(i<n){
            if(s[i]=='X') count++,i=i+3;
            else
                i++;
        }
        return count;
    }
};