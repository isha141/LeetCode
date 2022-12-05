class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        vector<int>ds;
        sort(s.begin(),s.end());
        int i=0;
        int n=s.size();
        int j=n-1;
        long long ans=0;
        while(i<=j){
            ds.push_back(s[i]+s[j]);
            ans+=(s[i]*s[j]);
            i++;
            j--;
        }
        for(int i=1;i<ds.size();++i){
            if(ds[i]!=ds[i-1])
                return -1;
        }
        // cout<<"hy";
        if(ds.size()==n/2)
            return ans;
        return -1;
    }
};