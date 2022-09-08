class Solution {
public:
    int monotoneIncreasingDigits(int n) { 
        string ans=to_string(n); 
        int index=ans.size();
        for(int i=ans.size()-1;i>0;--i){
            if(ans[i-1]>ans[i]){
                ans[i-1]--; 
                index=i;
            }
        }
        for(int i=index;i<ans.size();++i){
            ans[i]='9';
        
        }
    return stoi(ans);
    }
};