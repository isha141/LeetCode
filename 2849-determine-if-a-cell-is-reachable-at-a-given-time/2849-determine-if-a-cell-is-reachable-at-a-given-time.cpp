class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return 0;
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        int maxi=max(x,y);
        if(maxi>t) return 0;
        if(maxi==0 && (t>0 && t<2))return 0;
        return 1;
    }
};