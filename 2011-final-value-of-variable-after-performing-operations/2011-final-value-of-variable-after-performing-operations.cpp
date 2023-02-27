class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans=0;
        for(auto itr: op){
            if(itr[0]=='+' || itr[itr.size()-1]=='+'){
                ans+=1;
            }
            else{
                ans-=1;
            }
        }
        return ans;
    }
};