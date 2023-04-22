class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
         vector<int>ans;
         int n=nums.size();  
        int m=nums[0].size();
        for(auto itr: q){
            vector<string>ds=nums;
            for(int i=0;i<n;++i){ 
                 int temp=m-itr[1];
                ds[i]=ds[i].substr(temp);
            }
            vector<pair<string ,int>>a; 
            for(int i=0;i<n;++i){
                a.push_back({ds[i],i});
            }
            sort(a.begin(),a.end(),[&](pair<string , int>&arr,pair<string ,int>&b){
                if(arr.first!=b.first)
                     return arr.first<b.first;
                return arr.second<b.second;
            });
            ans.push_back(a[itr[0]-1].second);
        }
        return ans;
        
    }
};