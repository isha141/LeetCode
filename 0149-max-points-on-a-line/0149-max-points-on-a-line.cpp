class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0; 
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){ 
             map<double,int>mp;
            for(int j=i+1;j<n;j++){
                int x=p[j][0]-p[i][0];
                int y=p[j][1]-p[i][1]; 
                if(x==0){
                    mp[1e9]++;
                    ans=max(ans,mp[1e9]);
                    continue;
                }
                double temp=(double)(y)/x;
                mp[temp]++;
                ans=max(ans,mp[temp]);
            }
        }
        return ans+1;
    }
};