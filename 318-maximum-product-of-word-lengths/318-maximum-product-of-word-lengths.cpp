class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0; 
        int n=words.size();
        vector<vector<bool>> v(words.size(),vector<bool>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(auto itr: words[i])
                v[i][itr-'a']=1;
        }
        for(int i=0;i<n;i++)
        { 
            for(int j=i+1;j<n;j++)
            { 
                 int ok=1;
                for(int k=0;k<26;k++){
                if(v[i][k] && v[j][k])
                {
                    ok=0;
                    break;
                }
                 }
            if(ok)
                ans=max(ans,(int)(words[i].size()*(int)words[j].size()));
            }
        }
        return ans;
    }
};
