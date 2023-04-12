class Solution {
public:
    string simplifyPath(string path) {
         int n=path.size();
         string ans="";
         stack<string>st;
         int i=0;
         while(i<n){
             if(path[i]=='/'){
                 i++;
                 continue;
             } 
             else{
                 string temp=""; 
                 while(i<n && path[i]!='/'){
                     temp+=path[i];
                     i++;
                 }
                 if(temp=="."){
                     continue;
                 }
                 else if(temp==".."){
                     if(st.size()){
                         st.pop();
                     }
                 }
                 else{
                     st.push(temp);
                 }
             }
         }
        while(!st.empty()){
            auto itr=st.top();
            // ans+='/';
            ans="/"+itr+ans;
            // ans+='/';
            st.pop();
        } 
        cout<<ans<<" ";
        if(ans.size()==0)
            return "/";
         return ans;
    }
};