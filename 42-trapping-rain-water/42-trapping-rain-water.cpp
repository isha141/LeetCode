class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int i=0;
        int j=n-1; 
        int left=0;
        int right=0;
        int ans=0;
        while(i<=j){
            if(h[i]<=h[j]){
                if(left<=h[i])
                    left=h[i]; 
                else 
                 ans+=left-h[i];
                i++;
            } 
            else {
                if(right<=h[j])
                    right=h[j];
                else
                    ans+=right-h[j];
                j--;
            }
        }
        return ans;
    }
};