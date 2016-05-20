class Solution {
public:
    bool isValidSerialization(string preorder) {
        if( preorder.empty()  ) return false;
        int nodeCount = 1;
        preorder +=',';
        for( int i =0;i<preorder.size();i++){
            if( preorder[i] !=',') continue;
            nodeCount--;
            if(nodeCount<0) return false;
            if( preorder[i-1] !='#') nodeCount += 2;
        }
        return nodeCount == 0;
    }
};