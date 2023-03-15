class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        string ans="";
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop(); 
            int val1=itr.first;
            if(ans.size()<=1 || (ans[ans.size()-1]!=itr.second) ||(val1<=1 && ans[ans.size()-2]!=itr.second)){
                int mini=min(2,itr.first);
                for(int i=0;i<mini;++i){
                    ans+=itr.second;
                }
                val1-=mini;
            }
            if(pq.size()==0) break;
            auto itr1=pq.top();
            pq.pop();
            int val2=itr1.first; 
            int mini1=min(1,val2);
            for(int i=0;i<mini1;++i){
                ans+=itr1.second;
            }
            val2-=mini1;
            if(val1!=0){
                pq.push({val1,itr.second});
            }
            if(val2!=0){
                pq.push({val2,itr1.second});
            }
        }
        return ans;
        
    }
};