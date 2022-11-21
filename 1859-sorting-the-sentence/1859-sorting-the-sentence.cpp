class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mp;
        string temp="";
        for(auto itr: s){
            if(itr==' '){
                char ch=temp[temp.size()-1];
                temp.pop_back();
                mp[ch-'0']=temp;
                temp="";
            }
            else
                temp+=itr;
        } 
        if(temp.size()){
          char ch=temp[temp.size()-1];
                temp.pop_back();
                mp[ch-'0']=temp;  
        }
        string ans="";
        for(auto itr: mp){
            ans+=itr.second;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};