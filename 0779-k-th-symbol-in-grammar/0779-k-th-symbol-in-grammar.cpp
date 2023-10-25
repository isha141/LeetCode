class Solution {
    private:
    int solve(int n,int k){
        if(n==1)
             return 0;
        int len=pow(2,n-1);
        int mid=(len)/2;
        if(k<=mid){
            return solve(n-1,k);
        }
        else{
            return 1-solve(n-1,k-mid);
        }
    }
public:
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};