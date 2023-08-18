class Solution {
public:
    string convertToTitle(int col) {
          string ans="";
         while(col){
             int rem=col%26;
              if(rem==0){
                  ans+='Z';
                  col=col/26-1;
              }
             else{
                 ans+=rem-1+'A';
                 col=col/26;
             }
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};