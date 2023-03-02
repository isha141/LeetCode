class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0; 
        int prev=0;
        for(auto itr: bank){ 
            int c=0;
            for(auto itt: itr){
                if(itt=='1') 
                    c++;
            } 
            // ans+=(c*2); 
            if(c){
            ans+=(prev*c);
            prev=c;
            }
        }
        return ans;
    }
};