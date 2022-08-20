class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {  
        string res=s;  
        int n=s.size();
        vector<int>ds(n+1,0);
        for(auto itr: shifts){
            vector<int>it=itr;
            int i=it[0];
            int j=it[1];
            int k=it[2];
            if(k){
                ds[i]+=1;
                ds[j+1]-=1;
                
            }
            else{
                ds[i]-=1;
                ds[j+1]+=1;
            }
        }
        for(int i=1;i<=n;++i){ 
             ds[i]+=ds[i-1];
        }
        string ans="";
        for(int i=0;i<n;++i){
            int d=s[i]-'a';
            d+=ds[i];
            while(d<0)
                d+=26;
            d%=26;
            ans+=d+'a';
        }
        return ans;
    }
};