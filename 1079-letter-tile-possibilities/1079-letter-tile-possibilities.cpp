class Solution { 
    private: 
    set<string>st;
    int solve(int i,string &t,int n,string &temp,unordered_map<int,int>&mp)
    {  
        if(temp.size()>n)
            return 0; 
        st.insert(temp);
         // if(i>=n)
         //    return 0;
        for(int j=0;j<n;++j){
            if(mp.find(j)==mp.end()){
                mp[j]=j;
                temp+=t[j];
            solve(j+1,t,n,temp,mp);
            temp.pop_back(); 
                mp.erase(j);
            }
        } 
        return 0;
    }
public:
    int numTilePossibilities(string t) {
        int n=t.size(); 
        string temp="";
        unordered_map<int,int>mp;
         solve(0,t,n,temp,mp); 
         // for(auto it: st)
             // cout<<it<<" "; 
        
        return st.size()-1;
    }
};