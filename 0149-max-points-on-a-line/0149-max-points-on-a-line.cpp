class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0; 
        // sort(p.begin(),p.end());
        for(int i=0;i<n;++i){
            map<double,int>mp;
            for(int j=i+1;j<n;++j){
                 int y=(p[j][0]-p[i][0]);  
                if(y==0)
                { mp[INT_MAX]++; ans=max(ans,mp[INT_MAX]);
                 continue;
                }
                 double slope=(double)((p[j][1]-p[i][1]))/(y);
                 mp[slope]++;
                 ans=max(ans,mp[slope]);
            }
        }
        return ans+1;
    }
};