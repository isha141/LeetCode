class Solution { 
    private:
    bool ok(vector<int>&ds){
          sort(ds.begin(),ds.end());
          int diff=ds[1]-ds[0];
          for(int i=1;i<ds.size();++i){
              if((ds[i]-ds[i-1])!=diff)
                    return 0;
          }
         return 1;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
          int n=nums.size();
          int m=l.size();
          vector<bool>ans;
          for(int i=0;i<m;++i){
              int start=l[i];
              int end=r[i];
              vector<int>ds;
              for(int i=start;i<=end;++i){
                  ds.push_back(nums[i]);
              }
              if(ok(ds)){
                  ans.push_back(1);
              }
              else
                  ans.push_back(0);
          }
         return ans;
    }
};