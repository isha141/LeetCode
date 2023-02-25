class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0;
        // sort(p.begin(),p.end());
        for(int i=0;i<n;++i){
              map<double,int>mp; 
            for(int j=i+1;j<n;++j){
                // if(i!=j){
                    int x1=p[i][0];
                    int y1=p[i][1];
                    int x2=p[j][0];
                    int y2=p[j][1]; 
                    if((x2-x1)==0) {
                        mp[INT_MAX]++;
                         ans=max(ans,mp[INT_MAX]); 
                        continue;
                    }
                    double slope=(double)(y2-y1)/(x2-x1);
                    mp[slope]++;
                     ans=max(ans,mp[slope]); 
                } 
            // cout<<i<<"************"<<endl;
              // for(auto itr: mp)
                  // cout<<itr.first<<" "<<itr.second<<endl;
        }
        return ans+1;
    }
};