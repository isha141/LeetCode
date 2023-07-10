class Solution {
public:
    string simplifyPath(string path) {
         int n=path.size();
         string ans="";
         int i=0;
         while(i<n){
             if(path[i]=='/'){
                 if(i+1<n && (ans.size()==0 || ans.back()!='/')) {
                     ans+='/';
                 }
                 string temp="";
                 int count=0;
                 i++;
                 while(i<n && path[i]=='/') i++;
                 while(i<n && path[i]!='/'){
                         temp+=path[i];
                     i++; 
                 } 
                 // cout<<i<<";;"<<temp<<endl; 
                 if(temp==".") continue;
                 if(temp==".."){ 
                     if(ans.size()) ans.pop_back();
                     while(ans.size() && ans.back()!='/') ans.pop_back();
                     if(ans.size()==0)
                     ans="/"; 
                     // i++;
                     temp="";
                 }
                 ans+=temp;
             }
         } 
        // cout<<ans<<";;"<<endl;
        if(ans.size()==0) return"/";
        if(ans.size()==1) return ans;
        if(ans.size() && ans.back()=='/') ans.pop_back();
        return ans;
    }
};