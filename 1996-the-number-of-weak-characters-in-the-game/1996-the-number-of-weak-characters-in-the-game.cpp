class Solution { 
     static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])
            return a[0]<b[0];
         return a[1]>b[1];
     }
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        int n=pro.size();
        sort(pro.begin(),pro.end(),cmp);
        int c=0; 
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: pro){
          while(!pq.empty() && pq.top()<it[1]){
                c++;
                pq.pop();
            }
            pq.push(it[1]);
        }
        return c;
    }
};