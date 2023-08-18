class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        return (n>0 && !(n & n-1));
        // return 0;
    }
};