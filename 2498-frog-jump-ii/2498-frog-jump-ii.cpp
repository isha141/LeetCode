class Solution {
public:
    int maxJump(vector<int>& s) {
         int n=s.size();
        int ans1=0;
        int ans2=0; 
        if(n==2){
            return abs(s[0]-s[1]);
        }
        for(int i=0;i<n;i+=2){ 
            if((i-2)>=0)
            ans1=max(ans1,abs(s[i]-s[i-2]));
        }
        for(int i=1;i<n;i+=2){
            if(i+2<n){
                ans2=max(ans2,abs(s[i+2]-s[i]));
            }
        }
        return max(ans1,ans2);
        
    }
};