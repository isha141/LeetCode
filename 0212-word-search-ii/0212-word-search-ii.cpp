class trie{
    public:
    bool flag=0; 
    string s="";
    trie *links[26]; 
    public: 
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
   void create(char ch, trie *node){
        links[ch-'a']=node;
    }
    trie * refrenced(char ch){
        return links[ch-'a'];
    }  
    void toset(){
        flag=1;
    }
    bool isset(){
        return flag;
    }
}; 
class Solution { 
    private: 
    set<string>st;
     trie *root;
     int n,m; 
    void insert(string word){
        trie *node=root;
        for(int i=0;i<word.size();++i){
            if(node->containskey(word[i])){
                node=node->refrenced(word[i]);
            } 
            else{
               node->create(word[i],new trie());
                   node=node->refrenced(word[i]);
            }
        }
          node->toset();
          node->s=word;
    }
void dfs(int i,int j,vector<vector<char>>& board,trie *node,vector<string>&ans){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]==')' || !node->links[board[i][j]-'a'])
            return ;
        node=node->refrenced(board[i][j]); 
        char ch=board[i][j];
        board[i][j]=')';  
        if(node->isset()){ 
            if(st.find(node->s)==st.end()){
            ans.push_back(node->s);
                st.insert(node->s);
            }
        // return ;
        }
        dfs(i+1,j,board,node,ans);
        dfs(i-1,j,board,node,ans);
        dfs(i,j+1,board,node,ans);
        dfs(i,j-1,board,node,ans);
        board[i][j]=ch;
        return ;
    }
    
public: 
     Solution(){
        root=new trie();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        n=board.size();
        m=board[0].size();
        vector<string>ans;
        for(auto itr: words)
            insert(itr);
        trie *node=root;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dfs(i,j,board,node,ans);
            }
        }
        return  ans;
    }
};