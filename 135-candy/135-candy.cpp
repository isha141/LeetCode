#define mod 100000007+9
class Solution {
public:
    int candy(vector<int>& rat) { 
        int n=rat.size();
        vector<int>l(n,1);
        vector<int>r(n,1);
        for(int i=1;i<n;++i){
            if(rat[i]>rat[i-1]){
                l[i]=l[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;--i){
            if(rat[i]>rat[i+1]){
                r[i]=r[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=max(r[i],l[i]);
        }
        return sum;
    }
};