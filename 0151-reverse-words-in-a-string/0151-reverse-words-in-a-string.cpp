class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        string temp="";
        int n=s.size();
        while(i<n){
            while(i<n && s[i]==' ' && temp.size()==0)
                i++;
            if(s[i]==' ' && temp.size()){
                string a=ans;
                temp+=' ';
                temp+=a;
                ans=temp;
                temp="";
                // cout<<i<<","<<ans<<" "<;
            }
            else if(i<n && s[i]!=' ')
                temp+=s[i];
            i++; 
        }
        // cout<<temp<<endl;
        if(temp.size()>0){
            temp+=' '; 
            cout<<"hy";
            string a=ans;
            temp+=a;
            ans=temp;
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};