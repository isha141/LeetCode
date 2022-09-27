class Solution {
public:
    string pushDominoes(string dom) {
        int m=dom.size();
        queue<int>q;
        for(int i=0;i<m;++i){
            if(dom[i]!='.')
                q.push(i);
        }
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(m,0);
            while(n--){
                int itr=q.front();
                q.pop();
                if(dom[itr]=='L')
                {
                    if(itr-1>=0 && dom[itr-1]=='.'){
                        temp[itr-1]-=1;
                    }
                }
                else {
                    if(itr+1<m && dom[itr+1]=='.'){
                        temp[itr+1]+=1;
                    }
                }
            }
          for(int i=0;i<m;++i){
              if(temp[i]==-1){
                  dom[i]='L';
                  q.push(i);
              }
              else if(temp[i]==1){
                  dom[i]='R';
                  q.push(i);
              }
          }
        }
        return dom;
}
};