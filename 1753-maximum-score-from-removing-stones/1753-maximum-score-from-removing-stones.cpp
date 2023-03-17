class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // return 0; 
        int ans=0;  
        // if(a==b && b==c) return a;
        while(a>0 && b>0 && c>0){ 
             int mini=a;
            int maxi=a; 
            int c1=1;
            int c2=1;
            if(mini>b){
                mini=b; 
                c1=2;
            }
            if(mini>c){
                mini=c;
                c1=3;
            }  
            if(maxi<b){
                maxi=b; 
                c2=2;
            }
            if(maxi<c){
                maxi=c;
                c2=3;
            } 
            ans++;
            if(c1==1) a--;
            if(c1==2) b--;
            if(c1==3) c--;
            if(c2==1) a--;
            if(c2==2) b--;
            if(c2==3) c--;
        } 
        if(a==0) ans+=min(b,c);
        else if(b==0) ans+=min(a,c);
        else if(c==0) ans+=min(a,b);
        return ans;
    }
};