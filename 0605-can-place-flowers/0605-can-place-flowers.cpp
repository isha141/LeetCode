class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int m=f.size(); 
        if(n==0) return 1;
        if(m==1){
            if(f[0]==0 && n==1) return 1; 
            return 0;
        }
        for(int i=0;i<m;++i){  
            if(n==0) return 1;
            if(f[i]==1) continue;
            if(i==0){
                if(f[i]==0 && i+1<m && f[i+1]==0){
                    f[i]=1;
                    n--; 
                } 
                continue;
            }
            else if(i==m-1){
                if(i-1>=0 && f[i-1]==0 && f[i]==0){
                    n--;
                }
                continue;
            } 
            else{
                if(f[i-1]==0 && f[i+1]==0){
                    f[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};