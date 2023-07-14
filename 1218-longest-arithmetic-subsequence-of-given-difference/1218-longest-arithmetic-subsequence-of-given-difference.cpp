class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
            int n=arr.size();
             int ans=1;
          map<int,int>mp;
        for(int i=0;i<n;++i){
            int temp=arr[i]-diff;
            if(mp.find(temp)!=mp.end()){
                mp[arr[i]]=mp[temp]+1;
            }
            else{
                mp[arr[i]]=1;
            }
        }
         for(auto itr: mp){
             ans=max(ans,itr.second);
         }
        return ans;
    }
};