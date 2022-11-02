class Solution { 
    private:
    int solve(string start,string end,map<string,int>&mp){
        queue<string>q;
        q.push(start);
        int c=0;
        set<string>s;
        s.insert(start);
        string st="ACGT";
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto itr=q.front();
                q.pop();
                if(itr==end)
                    return c;
                for(int i=0;i<itr.size();++i){ 
                    // char ch=itr[i];
                   bool flag=0;
                    for(auto it: st){
                        string temp=itr;
                        temp[i]=it;
                        if(mp.find(temp)!=mp.end() && s.find(temp)==s.end()){
                            q.push(temp);
                            s.insert(temp); 
                            // cout<<temp<<" ,"<<c<<endl;
                          flag=1;
                        }
                        // if(flag)
                        //     break;
                        // itr[i]=ch;
                    }
                  // if(flag)
                  //   break;
                }
            }
            c++; 
            
        }
        return -1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int>mp;
        for(auto itr: bank)
            mp[itr]++;
        return solve(start,end,mp);
    }
};