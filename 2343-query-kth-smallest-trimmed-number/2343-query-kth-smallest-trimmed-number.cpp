class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
          int n=nums.size();
          vector<int>ans;
          int m=q.size();
           int a=nums[0].size();
          for(int i=0;i<m;++i){ 
              vector<pair<string,long>>ds; 
              int size=q[i][1];
              int ind=q[i][0];
               for(int j=0;j<n;++j){
                     if(a==size){
                         ds.push_back({(nums[j]),j});
                         continue;
                     }
                     else{
                         int ind=a-size; 
                         string temp=nums[j].substr(ind,a);
                         // cout<<temp<<";;"<<j<<endl;
                         ds.push_back({(temp),j});
                     }
               }
                sort(ds.begin(),ds.end());
              ans.push_back(ds[ind-1].second);
          }
            return ans;
       }
};