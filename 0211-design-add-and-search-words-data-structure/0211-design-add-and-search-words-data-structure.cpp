class trie{
    public:
    trie *links[26];
    bool flag=0;  
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    void create(char ch, trie * root){
         links[ch-'a']=root;
    }
    trie *reference(char ch){
        return links[ch-'a'];
    }
    void setflag(){
        flag=1;
    }  
    bool isflag(){
        return flag;
    }
};
class WordDictionary { 
    trie * root; 
    bool solve(int i,trie * head,string word,int n,bool check=0){
        if(i>=n) {
          check =1;
            return head->isflag();
        }
        if(word[i]!='.'){
            if(head->containskey(word[i])){
                if(solve(i+1,head->reference(word[i]),word,n) )
                    return 1;
            }
            else
            return 0;
        }
        else{
          for(int j=0;j<26;++j){
              if(head->links[j]!=NULL){
                  if(solve(i+1,head->reference(j+'a'),word,n))
                      return 1;
              }
          }
        }
        return 0;
    }
public:
    WordDictionary() {
        root=new trie();
    }
    
    void addWord(string word) {
        trie *head=root;
        for(int i=0;i<word.size();++i){
            if(!head->containskey(word[i])){
                head->create(word[i],new trie());
            }
           head=head->reference(word[i]);
        } 
        head->setflag();
    }
     
    bool search(string word) { 
        trie * head=root;
        for(int i=0;i<word.size();++i){
            if(word[i]!='.'){
                if(head->containskey(word[i])){
                    head=head->reference(word[i]);
                }
                else return 0;
            }
            else{  
                int n=word.size();
                return solve(i,head,word,n);
            }
        }
        return head->isflag();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */