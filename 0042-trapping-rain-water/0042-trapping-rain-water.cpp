class Solution {
public:
    int trap(vector<int>& he) {
        int n=he.size();
        int left=0;
        int right=0;
        int l=0;
        int h=n-1;
        int ans=0;
        while(l<=h){
            if(he[l]<=he[h]){
                if(he[l]>=left)
                    left=he[l];
                else
                    ans+=left-he[l];
                l++;
            }
            else {
                if(right<=he[h]){
                    right=he[h];
                }
                else
                    ans+=right-he[h];
                h--;
            }
        }
        return ans;
    }
};