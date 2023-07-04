class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0; 
        int n=s.size();
        for(int i=0;i<s.size()-1;++i){
            if(s[i]!=s[i+1]){
                ans+=min(i+1,n-i-1);
            }
        }
        return ans;
    }
};