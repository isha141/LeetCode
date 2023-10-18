class Solution {
    private:
    int solve(int root,vector<int>&left,vector<int>&right){
        if(root==-1)
             return 0;
        return 1+solve(left[root],left,right)+solve(right[root],left,right);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<int>indeg(n,0);
        for(int i=0;i<n;++i){
            if(left[i]!=-1){
                indeg[left[i]]++;
                if(indeg[left[i]]>1) 
                    return 0;
            }
            if(right[i]!=-1){
                indeg[right[i]]++;
                if(indeg[right[i]]>1) 
                    return 0;
            }
        } 
        int root=-1;
        for(int i=0;i<n;++i){
            if(indeg[i]==0){
                root=i;
            }
        }
        if(root==-1) return 0;
        return solve(root,left,right)==n;
    }
};