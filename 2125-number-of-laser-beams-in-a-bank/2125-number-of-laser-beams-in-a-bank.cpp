class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0; 
        int prev=0;
        for(auto itr: bank){ 
            int c=0;
            c=count(itr.begin(),itr.end(),'1');
            if(c){
            ans+=(prev*c);
            prev=c;
            }
        }
        return ans;
    }
};