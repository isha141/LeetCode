class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev,ans;
        int n=arr.size();
        for(int i=0;i<n;++i){
          unordered_set<int>curr; 
            curr.insert(arr[i]);
            for(auto itr: prev){
                curr.insert(arr[i]|itr);
            }
            prev=curr;
            for(auto itr: prev){
                ans.insert(itr);
            }
        }
        return ans.size();
    }
};