class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n=s.size();
        map<string,int>mp;
        for(int i=0;i<n;++i){
            if(s[i]=='A'|| s[i]=='C' || s[i]=='G'|| s[i]=='T'){
            string temp=s.substr(i,10); 
                // cout<<temp<<"::"<<i<<endl;
                mp[temp]++;
            }
        } 
        for(auto itr: mp){
            if(itr.second>1)
            ans.push_back(itr.first);
        }
        return ans;
    }
};