class Solution {
public:
    long long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long ans=0;
        long long a;
        long long b;
        if(ax1>=0 && ax2>=0 || (ax1<0  && ax2<0))
            a=abs(ax1-ax2);
        else
             a=abs(ax1)+abs(ax2);
        if((ay1>=0 && ay2>=0) || (ay1<0 && ay2<0))
            b=abs(ay1-ay2);
        else{
            b=abs(ay1)+abs(ay2);
          }
        ans+=a*b;
        long long x;
        long long y;
        if((bx1>=0 && bx2>=0) || (bx1<0 && bx2<0))
            x=abs(bx1-bx2);
        else
          x=abs(bx1)+abs(bx2); 
        if((by1>=0 && by2>=0) || (by1<0 && by2<0))
            y=abs(by1-by2);
        else
            y=abs(by1)+abs(by2);  
        ans+=(x*y); 
        if(ax1==bx1 && ax2==bx2 && ay1==by1 && ay2==by2)
            return ans/2;
        cout<<ans<<endl;
        if(ax2<=bx1 || ax1>=bx2 || ay2<=by1 || ay1>=by2){ 
            return ans;
        }
        int x1=0;
        int y1=0;
        x1=max(ax1,bx1);
        y1=max(by1,ay1);
        int y11=min(by2,ay2);
        int x11=min(ax2,bx2);
        int l=0;
        int m=0;
        if((x1<0 && x11<0 ) || (x1>=0 && x11>=0)) 
           l=abs(x1-x11);
           else
           l=abs(x1)+abs(x11);
          if((y1>=0 &&  y11>=0 ) || (y1<0 && y11<0))
           m=abs(y1-y11);
           else
           m=abs(y1)+abs(y11);
        cout<<l<<" "<<m<<endl;
           long long temp=m*l;
        ans-=temp;
        return ans;
    }
};