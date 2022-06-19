class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pr, string sea) {
       vector<vector<string>>ans;
        sort(pr.begin(),pr.end());
        string s=""; 
        int n=pr.size();
        for(auto itr: sea){
            s+=itr;  
            vector<string>ds;
            int itt=lower_bound(pr.begin(),pr.end(),s)-pr.begin();
            for(int i=itt;i<min(3+itt,n);i++){  
                if(pr[i].find(s)) break;
               ds.push_back(pr[i]); 
            }
            ans.push_back(ds);
        }
        return ans;
    }
};