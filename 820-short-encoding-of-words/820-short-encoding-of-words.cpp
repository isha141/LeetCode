class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) { 
        int res=0;
        int n=words.size();
        for(int i=0;i<words.size();++i)
            reverse(words[i].begin(),words[i].end());
             sort(words.begin(),words.end());
        for(int i=0;i<n-1;++i){
            int c=words[i]==words[i+1].substr(0,words[i].size())?0: words[i].size()+1; 
            cout<<c<<" ";
            res+=c;
        }
       res+=words[n-1].size()+1;
        return res;
    }
};