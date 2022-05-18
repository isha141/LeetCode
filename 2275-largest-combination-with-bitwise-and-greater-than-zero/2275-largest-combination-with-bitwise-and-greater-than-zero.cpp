class Solution {
public:
    int largestCombination(vector<int>& can) {
        int count=0;
        for(int i=0;i<32;i++)
        {
          int temp=0;
            for(auto itr: can)
            {
                if(itr & (1<<i))
                    temp++;
            }
            count=max(count,temp);
        }
        return count;
    }
};