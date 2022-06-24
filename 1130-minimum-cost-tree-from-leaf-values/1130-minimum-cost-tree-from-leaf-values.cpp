class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res=0; 
        int n=arr.size();
        vector<int>ans;
        ans.push_back(INT_MAX);
        for(int i=0;i<n;++i){
            while(ans.back()<=arr[i]){
                int temp=ans.back();
                ans.pop_back();
                res+=temp*min(arr[i],ans.back());
            }
            ans.push_back(arr[i]);
        }
        for(int i=2;i<ans.size();++i){
            res+=ans[i-1]*ans[i];
        }
        return res;
    }
};