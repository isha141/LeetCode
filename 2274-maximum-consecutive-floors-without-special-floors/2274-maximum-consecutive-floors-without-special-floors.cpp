class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) {
        sort(sp.begin(),sp.end());
        int ans=sp[0]-bottom; 
        int prev=sp[0];
        for(auto itr: sp)
        {
            ans=max(ans,itr-prev-1);
            prev=itr;
        }
        return max(ans,top-prev);
    }
};