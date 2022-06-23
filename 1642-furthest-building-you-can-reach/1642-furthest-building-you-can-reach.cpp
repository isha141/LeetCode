class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<height.size()-1;++i){
            int d=height[i+1]-height[i];
            if(d>0){
                pq.push(d);
            }
              if(pq.size()>ladders){
                  int temp=pq.top();
                  pq.pop();
                  bricks-=temp;
            }
            if(bricks<0) return i;
        }
        return height.size()-1;
    }
};