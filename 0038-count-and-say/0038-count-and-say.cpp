class Solution {
    private: 
    int n;
    string t="";
    void solve(int i,string &temp){
        if(i>=n){
            t=temp;
            return ;
        }
        int k=0;
         string ans="";
        while(k<temp.size()){
            int c=1; 
            bool flag=0;
            while(k<temp.size()-1 && temp[k]==temp[k+1]){
                c++;
            flag=1;
                k++;
            } 
            // cout<<c<<" ";
            ans+=to_string(c);
            ans+=temp[k];
            k++;
            // cout<<ans<<endl;
        }
        solve(i+1,ans);
        return ;
    }
public:
    string countAndSay(int n) {
        string temp="11";
        this->n=n;
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        solve(2,temp);  
        return t;
    }
};