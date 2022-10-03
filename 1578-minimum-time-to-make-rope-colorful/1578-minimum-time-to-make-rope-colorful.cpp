class Solution {
public:
    int minCost(string colors, vector<int>& t) {
        int n=colors.size();
        int ans=0;
        int i=0;
        int j=0;
        while(i<n){
            if(i+1<n && colors[i]==colors[i+1]){
                int j=i;
                int tt=INT_MAX; 
                vector<int>ds;
                while(j<n && colors[i]==colors[j]){
                  ds.push_back(t[j]);
                    j++;
                }
                i=j;
                sort(ds.begin(),ds.end());
                for(int i=0;i<ds.size()-1;++i){
                    ans+=ds[i];
                }
                continue;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};