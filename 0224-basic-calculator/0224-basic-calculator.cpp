class Solution {
    private:
public:
    int calculate(string s) {
        int n=s.size();
        long long ans=0; 
        stack<int>st;
        int sign=1; 
        long long curr=0;
        for(auto itr: s){
            if(isdigit(itr))
                curr=curr*10+(itr-'0');
            else if(itr=='+'){
                ans+=curr*sign;
                curr=0;
                sign=1;
            }
            else if(itr=='-'){ 
                ans+=curr*sign;
                sign=-1;
                curr=0;
            }
            else if(itr=='('){
                ans+=curr*sign;
                st.push(ans);
                st.push(sign);
                sign=1;
                curr=0;
                ans=0;
            }
            else if(itr==')'){
                ans+=curr*sign;
                curr=0;
                int temp=st.top();
                ans*=temp;
                st.pop();
                ans+=st.top();
                st.pop();
            }
            // cout<<curr<<endl;
        }
         ans+=curr*sign;
        return ans;
    }
};