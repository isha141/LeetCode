class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
         vector<pair<int,int>>ds;
         for(int i=0;i<s.size();i++){
             ds.push_back({s[i],i});
         }
        int c=1;  
        int n=s.size();
        vector<string>ans(n,",");
        sort(ds.rbegin(),ds.rend());
        for(auto itr: ds){
            auto it=itr;
            int ind=it.second;
            if(c==1){
                ans[ind]="Gold Medal";
            }
            else if(c==2){
                ans[ind]="Silver Medal";
            }
            else if(c==3){
                ans[ind]="Bronze Medal";
            }
            else{
                ans[ind]=to_string(c);
            }
            c++;
        }
        return ans;
    }
};