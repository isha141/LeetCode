class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
         vector<int>ans(n+2,0);
        for(int i=0;i<ranges.size();++i){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            ans[left]=max(ans[left],right);
        }
        // for(auto itr: ans)
              // cout<<itr<<"-->";
        // cout<<endl;
        int c=0;
        int currind=0;
        int maxind=0;
        for(int i=0;i<=n;++i){
            if(i>maxind)
                  return -1;
            if(i>currind){
                currind=maxind;
                c+=1;
            }
            maxind=max(maxind,ans[i]);
        }
        return c;
    }
};