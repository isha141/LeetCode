class Solution {
    private:
    bool ok(string &ans,string &a,string &b){
        int i=0;
        int n=a.size();
        int m=b.size();
        int t=ans.size();
        while(i<n){
            string temp=a.substr(i,t);
            if(temp!=ans)
                  return 0;
            i+=t;
        }
        if(i>n || i<n) return 0;
        i=0;
        while(i<m){
            string temp=b.substr(i,t);
            if(temp!=ans)
                  return 0;
            i+=t;
        }
        if(i>m || i<m) return 0;
        return 1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string ans="";
        int i=0;
        int j=0;
        string res="";
        while(i<min(n,m)){
            ans+=str1[i];
            if(ok(ans,str1,str2)){
                res=ans;
            }
            i++;
        }
        return res;
    }
};