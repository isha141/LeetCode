bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]) 
        return a[0]<b[0];
      return a[1]<b[1];
        
}
class Solution { 
    private:
    int solve(vector<int>&it1,vector<int>&it2,vector<int>&it3)
    {       int x1=it1[0];
            int y1=it1[1];
            int x2=it2[0];
            int y2=it2[1];
            int x3=it3[0];
            int y3=it3[1]; 
         return ((y3-y2)*(x2-x1)-((y2-y1)*(x3-x2)));
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>ans;
        sort(begin(trees),end(trees),cmp);
        deque<vector<int>>lower;
        deque<vector<int>>upper;
        for(int i=0;i<trees.size();++i){
            auto it1=trees[i];
            while(lower.size()>=2   && solve(lower[lower.size()-1],lower[lower.size()-2],it1)<0){
                  lower.pop_back();
            }
             while(upper.size()>=2 && (solve(upper[upper.size()-1],upper[upper.size()-2],it1)>0))
                upper.pop_back();
        lower.push_back(it1);
        upper.push_back(it1);
        } 
        set<vector<int>>s;
        while(lower.size()>0){
            s.insert(lower.front());
            lower.pop_front();
        }
        while(upper.size()>0){
            s.insert(upper.front());
            upper.pop_front();
        } 
        for(auto itr: s)
            ans.push_back(itr);
        
        return ans; 
    }
};