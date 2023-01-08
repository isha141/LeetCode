class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
        sort(in.begin(),in.end());
        int first=in[0][0];
        int second=in[0][1]; 
        int n=in.size();
        for(int i=1;i<n;++i){
            if(in[i][0]<=second){
                second=max(second,in[i][1]);
                first=min(first,in[i][0]);
            }
            else{
                ans.push_back({first,second});
                first=in[i][0];
                second=in[i][1];
            }
        } 
        ans.push_back({first,second});
        return ans;
        
    }
};