class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mps,mpt;
        for(int i=0;i<m;++i)
            mpt[t[i]]++; 
        if(n<m) return "";
        int j=0; 
        int i=0;
        int left=-1;
        int right=-1;
        string ans="";
        int count=0;
        while(j<n){ 
            mps[s[j]]++;
            if(mpt.find(s[j])!=mpt.end()){
                if(mps[s[j]]<=mpt[s[j]])
                    count++; 
            }
            if(count==m){
                while(i<=j && count==m){ 
                    // cout<<s.substr(i,j-i+1)<<"(())";
                    if((left==-1 && right==-1 ) || (right-left+1)>(j-i+1)){
                        left=i;
                        right=j;
                    }
                    mps[s[i]]--;
                    if(mpt.find(s[i])!=mpt.end()){
                        if(mps[s[i]]<mpt[s[i]])
                            count--;
                    }
                    if(mps[s[i]]<=0)
                        mps.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        if(left==-1 || right==-1) return "";
        return s.substr(left,right-left+1);
    }
};