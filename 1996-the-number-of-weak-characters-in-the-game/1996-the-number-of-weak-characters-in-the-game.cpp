class Solution { 
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        else 
            return a[1]>b[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro){
        int n=pro.size();
        sort(pro.begin(),pro.end(),cmp);
        int c=0; 
        priority_queue<int,vector<int>,greater<int>>pq;
        int mini=INT_MIN;
        for(auto itr: pro){
           while(!pq.empty() && pq.top()<itr[1]){
               pq.pop(); 
               c++;
           }
            pq.push(itr[1]);
        }
        return c;
    }
};