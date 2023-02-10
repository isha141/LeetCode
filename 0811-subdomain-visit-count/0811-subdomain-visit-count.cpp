class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
       vector<string>ans;
       // int n=cp.size();
       map<string,int>mp;
       for(auto itr: cp){
           string s=itr;
           int i=0; 
           int m=s.size();
           // string ans="";
           int ans=0;
           while(i<s.size() && s[i]!=' '){
               ans=ans*10+s[i]-'0';
               i++;
           }
          mp[s.substr(i+1)]+=ans;
           while(i<m && s[i]!='.') i++; 
           int j=i+1;
           i++;
           while(i<m){
               if(s[i]=='.'){ 
                   // cout<<j<<" "<<i<<endl;
                   mp[s.substr(j)]+=ans;
                   j=i+1;
               }
               i++;
           }
           // cout<<j<<" "<<i<<endl;
           mp[s.substr(j)]+=ans;
       }
        for(auto itr: mp){
            // for(auto itt: itr.second){
                ans.push_back(to_string(itr.second)+" "+itr.first);
            // }
        }
        return ans;
    }
};