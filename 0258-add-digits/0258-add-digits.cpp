class Solution {
public:
    int addDigits(int num) {
         int ans=num;
         while(num>=10){
             int temp=num;
             ans=0;
             while(temp>0){
                 int rem=temp%10;
                 ans+=rem;
                 temp/=10;
             }
             num=ans;
         }
        return ans;
    }
};