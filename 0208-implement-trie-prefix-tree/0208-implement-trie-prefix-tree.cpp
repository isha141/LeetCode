class trie{
    public:
    trie *links[26];
    bool flag=0; 
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    } 
    trie* refrenced(char ch){
        return links[ch-'a'];
    } 
    void create(char ch,trie *node){
        links[ch-'a']=node;
    } 
    void setend(){
        flag=1;
    } 
    bool isset(){
        return flag==1;
    } 
    
};
class Trie { 
    private :
    trie *root;
public:
    Trie() {
        root=new trie();
    }
    
    void insert(string word) {
        trie *node=root;
        // t.c--> length of the word;
        for(int i=0;i<word.size();++i){
            if(node->containskey(word[i])){
                node=node->refrenced(word[i]);
            }
            else{
                node->create(word[i],new trie());
                 node=node->refrenced(word[i]);
            }
        } 
        node->setend();
    }
    
    bool search(string word) { 
        trie *node=root;
        for(int i=0;i<word.size();++i){
            if(node->containskey(word[i]))
                node=node->refrenced(word[i]);
            else
                return 0;
        }
        return node->isset();
    }
    
    bool startsWith(string prefix) { 
        trie *node=root;
        for(int i=0;i<prefix.size();++i){
            if(node->containskey(prefix[i])){
                node=node->refrenced(prefix[i]);
            }
            else
                return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */