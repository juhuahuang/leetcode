/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
       stack<TreeNode*> ss;
       vector<int> result;
       TreeNode* node = root;
       TreeNode* last_visit;
       TreeNode* peek;
       while( node || !ss.empty()){
           if( node){
               ss.push(node);
               node = node->left;
           }
           else{
               peek = ss.top();
               if( peek->right == NULL || peek->right == last_visit ){
                   result.push_back(peek->val);
                   ss.pop();
                   lastvisit = peek;
               }
               else{
                   node = peek->right;
               }
           }
       }
       return result;
    }
};