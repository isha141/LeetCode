class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi=arr[0];
        queue<int>q;
        int n=arr.size();
        for(int i=1;i<n;++i){
             q.push(arr[i]);
             maxi=max(maxi,arr[i]);
        }
         int curr=arr[0];
         int win=0;
          while(!q.empty()){
              auto itr=q.front();
              q.pop();
              if(curr>itr){
                  win++;
                  q.push(itr);
              }
              else{
                  q.push(curr);
                  curr=itr;
                  win=1;
              }
              if(win==k || (curr==maxi)) 
                  return curr;
          }
        return -1;
    }
};