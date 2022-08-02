class Solution {
    private:
    bool solve(int i,vector<int>&match,vector<int>&ds,int &tot)
    {
        if(i==match.size()){
            if(ds[0]==ds[1] && ds[1]==ds[2] && ds[2]==ds[3])
                return 1;
            return 0;
        }  
        for(int j=0;j<4;++j){ 
            if(ds[j]+match[i]>tot) continue;
            ds[j]+=match[i];
            if(solve(i+1,match,ds,tot))
                return  1;
            ds[j]-=match[i];
        }
        return 0;
    }
public:
    bool makesquare(vector<int>& match) {
        vector<int>ds(4,0); 
        vector<int>dp(match.size(),-1); 
        sort(match.rbegin(),match.rend());
        int tot=0;
        for(auto it: match) tot+=it;
        if(tot%4) return 0; 
        tot/=4;
        return solve(0,match,ds,tot);
    }
};