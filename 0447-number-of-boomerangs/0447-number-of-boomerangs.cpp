class Solution { 
    private:
    int getdis(vector<int>&a,vector<int>&b){
        int x=a[0]-b[0];
        int y=a[1]-b[1];
        return x*x+y*y;
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue; 
                int a=getdis(p[i],p[j]);
                mp[a]++;
            }
            for(auto itr: mp)
                ans+=(itr.second)*(itr.second-1);
        mp.clear();
        }
       return ans;
    }
};