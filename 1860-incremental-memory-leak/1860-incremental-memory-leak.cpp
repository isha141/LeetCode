class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
         vector<int>ans;
          bool flag=0;
        int i=1;
        while(m1>=i || m2>=i){
            if(m1>=m2){
                m1-=i;
            }
            else{
                m2-=i;
            }
            i++;
        }
        ans.push_back(i);
        ans.push_back(m1);
        ans.push_back(m2);
        return ans;
    }
};