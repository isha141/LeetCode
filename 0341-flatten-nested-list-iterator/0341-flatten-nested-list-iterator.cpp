/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator { 
    vector<int>ans;
    int i=0;
    void helper(vector<NestedInteger>&ds){
        for(auto itr: ds){
            if(itr.isInteger())
                ans.push_back(itr.getInteger());
            else{
              helper(itr.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nes) {
        helper(nes);
    }
    
    int next() {
        if(i<ans.size()){
            return ans[i++];
        }
        return -1;
    }
    
    bool hasNext() {
        return i<ans.size()?1:0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */