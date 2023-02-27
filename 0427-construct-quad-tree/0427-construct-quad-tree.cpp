/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution { 
    private:
    int n,m; 
    vector<vector<int>>grid; 
    bool issame(int i,int j,int length){
         int val=grid[i][j];
        for(int x=i;x<i+length;x++){
            for(int y=j;y<j+length;y++){
                if(grid[x][y]!=val){
                    return 0;
                }
            }
        }
        return 1;
    }
    Node * solve(int i,int j,int length){
         if(issame(i,j,length)){
             return new Node(grid[i][j],1);
         } 
         Node * root=new Node();
        root->val=grid[i][j];
        root->topLeft=solve(i,j,length/2);
        root->topRight=solve(i,j+length/2,length/2);
        root->bottomLeft=solve(i+length/2,j,length/2);
        root->bottomRight=solve(i+length/2,j+length/2,length/2);
        return root;
        
    }
public:
    Node* construct(vector<vector<int>>& grid) { 
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        return solve(0,0,n);
    }
};