class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=(n+m-2);
        long long res=1;
        int r=m-1;
        for(int i=1;i<m;++i){
            res=res*(N-r+i)/i;
        }
         return res;
    }
};