class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // int c=0; 
        if(n==0)
            return 1;
        int total=10;
        int start=9;
        int cur=9;
        while(--n>0){
            cur=cur*start--;
            total+=cur;
        }
        return total;
        
    }
};