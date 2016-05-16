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
        private:
    stack<NestedInteger> ss;
    int curInteger;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for( int i = nestedList.size() -1 ; i>=0;i--){
            ss.push(nestedList[i]);
        }
    }

    int next() {
        return curInteger;
    }

    bool hasNext() {
        while( !ss.empty()){
            NestedInteger curNested = ss.top();ss.pop();
            if( curNested.isInteger()) {
                curInteger = curNested.getInteger();
                return true;
            }
            vector<NestedInteger> nextList = curNested.getList();
            if( nextList.empty()) continue;
            for( int i = nextList.size() -1 ;i >=0;i--){
                ss.push(nextList[i]);
            }
                
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */