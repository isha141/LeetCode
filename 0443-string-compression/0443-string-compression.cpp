class Solution {
public:
    int compress(vector<char>& chars) {
        string t="";
        for(auto itr: chars)
            t+=itr;
        int c=1; 
        char prev=t[0];
        string ans="";
        // ans+=t[0];
        for(int i=1;i<t.size();++i){
            if(prev==t[i])
                c++;
            else{
                ans+=prev;
                if(c!=1)
                ans+=to_string(c);
                prev=t[i];
                c=1; 
            }
        } 
        ans+=prev;
        if(c!=1)
            ans+=to_string(c); 
        // cout<<ans<<endl;
        for(int i=0;i<ans.size();++i){
            chars[i]=ans[i];
        }
        return ans.length();
    }
};