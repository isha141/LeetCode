class Solution { 
    private:
    int solve(string &start,string &end,vector<string>&bank){
        queue<string>q; 
        unordered_set<string>s;
        for(auto itr: bank)
            s.insert(itr);
        q.push(start);
        string temp="ACGT";
        map<string,int>mp;
        int c=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
            auto itr=q.front();
            q.pop();
            if(itr==end)
                return c;
            for(int i=0;i<itr.size();++i){
                for(int j=0;j<temp.size();++j){
                    char ch=itr[i];
                    itr[i]=temp[j];
                    if(s.find(itr)!=s.end() && mp.find(itr)==mp.end()){
                        q.push(itr);
                        mp[itr]++;
                    }  
                    itr[i]=ch;
                }
            }
            }
            c++;
        }
        return -1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        return solve(start,end,bank);
    }
};