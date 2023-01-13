class Solution {
public:
    vector<string> invalidTransactions(vector<string>& tran) {
        vector<string>ans;
        int n=tran.size(); 
        sort(tran.begin(),tran.end());
        string name[n];
        string time[n];
        string amount[n];
        string city[n]; 
        vector<bool>vis(n,0);
        for(int i=0;i<n;++i){
             vector<string>ds;
              stringstream ss(tran[i]);
              while (ss.good()) {
               string substr;
                getline(ss, substr, ',');
                  ds.push_back(substr);
           }      
            name[i]=ds[0];
            time[i]=ds[1];
            amount[i]=ds[2];
            city[i]=ds[3];
        }
        for(int i=0;i<n;++i){ 
              int am=stoi(amount[i]);
             if(am>1000){
                // cout<<i<<"...";
                  vis[i]=1; 
            }
            int t1=stoi(time[i]);
            for(int j=i+1;j<n;++j){
                int t2=stoi(time[j]);
              if(name[i]==name[j] && abs(t2-t1)<=60 && city[i]!=city[j]){
                  vis[i]=1;
                  vis[j]=1;
              }  
            }
        }
        for(int i=0;i<n;++i){
            if(vis[i])
                ans.push_back(tran[i]);
        }
        return ans;
    }
    
};