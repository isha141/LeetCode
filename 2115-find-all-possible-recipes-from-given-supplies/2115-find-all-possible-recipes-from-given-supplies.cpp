class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& sup) {
        int n=r.size();
        unordered_set<string>ans;
        unordered_set<string>s;
        for(auto itr: sup)  s.insert(itr); 
        while(1){
            int c=s.size();
             for(int i=0;i<n;++i){
                 if(ans.find(r[i])==ans.end()){
                     vector<string>ds=ing[i];
                     bool flag=0;
                     int c=0;
                     for(auto it: ds){
                         if(s.find(it)==s.end()){
                             flag=1;
                             c++;
                             break;
                         }
                     }
                     if(flag==0){
                        ans.insert(r[i]);
                         s.insert(r[i]);
                     }
                 }
             }
            if(s.size()==c)
                break;
        }
        vector<string>temp;
        for(auto itr=ans.begin();itr!=ans.end();++itr){
            temp.push_back(*itr);
        } 
        // sort(temp.begin(),temp.end());
        // sort(ds.begin(),ds.end()); 
        return temp;
    }
};