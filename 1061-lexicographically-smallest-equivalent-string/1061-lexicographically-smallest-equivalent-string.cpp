class Solution { 
    private: 
    vector<int>ds;
    char find(int a){
        if(ds[a]==-1)
            return a; 
      return  ds[a]=find(ds[a]);
    }
    void union1(int x,int y){
         x=find(x);
          y=find(y); 
        // cout<<x+'a'<<" "<<y+'a'<<endl;
        if(x!=y){
            ds[max(x,y)]=min(x,y);
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string base) {
        int n=s1.size(); 
        ds.resize(27,-1);
        for(int i=0;i<n;++i){ 
             // cout<<i<<" ";
            union1(s1[i]-'a',s2[i]-'a');
        }   
        string ans="";
        for(int i=0;i<base.size();++i){
            ans+=find(base[i]-'a')+'a';
        }
        return ans;
    }
};