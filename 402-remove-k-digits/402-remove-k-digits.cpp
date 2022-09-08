class Solution {
public:
    string removeKdigits(string num, int k) {
    int n=num.size();
        int i=0; 
        stack<int>s;
        while(i<n  && k>0){
            while(s.size()>0 && s.top()>(num[i]-'0') && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]-'0');
            i++;
        }  
        while(i<n){ 
            if(k>0 && s.top()>=(num[i]-'0')){
                s.pop();
                k--;
            }
            s.push(num[i]-'0');
            i++; 
        } 
        while(k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        } 
        while(ans.size() && ans[ans.size()-1]=='0')
            ans.pop_back();
        reverse(ans.begin(),ans.end()); 
        
        return ans.size()>0 ? ans:"0";
    }
};