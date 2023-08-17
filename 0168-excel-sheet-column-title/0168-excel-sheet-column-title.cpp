class Solution {
public:
    string convertToTitle(int num) {
         string ans="";
         while(num){
             int rem=num%26;
             if(rem==0){
                 ans+='Z';
                 num=num/26-1;
             }
             else{
                 ans+=rem-1+'A';
                 num=num/26;
             }
         }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};