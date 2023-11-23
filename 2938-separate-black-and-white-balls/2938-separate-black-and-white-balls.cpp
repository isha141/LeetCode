class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0;
        int last=0;
        for(int i=0;i<n;++i){
            if(s[i]=='0'){
                ans+=(i-last);
                last+=1;
            }
        }
        return ans;
    }
};