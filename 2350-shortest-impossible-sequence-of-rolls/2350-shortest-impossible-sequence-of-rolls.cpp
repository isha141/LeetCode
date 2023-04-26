class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size();
        set<int>s;
        int count=1;
        for(int i=0;i<n;++i){
            s.insert(rolls[i]);
            if(s.size()>=k){
                s.clear();
                count+=1;
            }
        }
        return count;
    }
};