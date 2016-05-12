/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> ss;
        TreeNode* node = root;
        while( node || !ss.empty() ){
            if(node){
                result.push_back(node->val);
                ss.push(node);
                node = node->left;
            }
            else{
                
                node = ss.top()->right;
                ss.pop();
            }
        }
        return result;
    }
};