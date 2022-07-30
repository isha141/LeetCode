class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
       vector<string>  ans;
        for(auto itr: words){
            if(itr.size()==pat.size()){
               int i=0;
                map<char,char>mp1,mp2;
                while(i<pat.size()){
                    if(mp1.find(pat[i])==mp1.end() && mp2.find(itr[i])==mp2.end())
                    {
                        mp1[pat[i]]=itr[i];
                        mp2[itr[i]]=pat[i]; 
                    } 
                    else if((mp1.find(pat[i])!=mp1.end() &&  mp1[pat[i]]!=itr[i]) || (mp2.find(itr[i])!=mp2.end() &&  mp2[itr[i]]!=pat[i])) break;                   
                  i++;
                }
                if(i==pat.size())
                    ans.push_back(itr);
            }
        }
        return ans;
    }
};