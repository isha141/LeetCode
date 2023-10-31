class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        int n=pre.size();
        vector<int>ans;
        ans.push_back(pre[0]);
        for(int i=1;i<n;++i){
            ans.push_back(pre[i]^pre[i-1]);
        }
        return ans;
    }
};