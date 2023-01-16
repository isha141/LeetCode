class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newi) {
        vector<vector<int>>ans;
        sort(newi.begin(),newi.end());
        int j=0;
        int first=newi[0];
        int second=newi[1];
         in.push_back({first,second});
         sort(in.begin(),in.end()); 
        first=in[0][0];
        second=in[0][1];
        for(int i=0;i<in.size();++i){ 
            if(in[i][0]<=second){
                first=min(first,in[i][0]);
                second=max(second,in[i][1]);
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