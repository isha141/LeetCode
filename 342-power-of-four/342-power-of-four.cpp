class Solution {
public:
    bool isPowerOfFour(int n) {
        return (((long(n) & long(n)-1)==0) && (n-1)%3==0);
    }
};