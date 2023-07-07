class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
           int i=0;
           int j=0;
           while(i<m && j<n){
               if(n1[i]<n2[j]){
                   i++;
               }
               else{
                   swap(n1[i],n2[j]);
                   sort(n2.begin(),n2.end());
                   i++;
               }
           }
        while(j<n){
            n1[i++]=n2[j++];
        }
        return ;
    }
};