class Solution {
public:
    bool isPalindrome(int x) {
        long num=0; 
        int temp=x; 
        if(x<0) return 0;
         while(x){
             int rem=x%10;
             num=num*10+rem;
             x/=10;
         }
         if(temp==num) return 1;
        return 0;
    }
};