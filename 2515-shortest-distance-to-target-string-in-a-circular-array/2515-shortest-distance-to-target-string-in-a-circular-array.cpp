class Solution {
public:
    int closetTarget(vector<string>& w, string tar, int start) {
          int n=w.size();
           int ans=INT_MAX;
        for(int i=0;i<n;++i){
            if(w[i]==tar){
                ans=min(ans,abs(i-start));
                ans=min(ans,abs(start+(n-i)));
                ans=min(ans,abs(n-start+(i)));
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};