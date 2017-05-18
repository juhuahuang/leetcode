#include "BinartTreeLevelOrderTraversal_102.h"

void BinaryTreeLevelOrderTraversal_102::execute()
{
	this->result = LevelOrder(this->root);
}

BinaryTreeLevelOrderTraversal_102::BinaryTreeLevelOrderTraversal_102(vector<int> num) {
}

vector<vector<int>> BinaryTreeLevelOrderTraversal_102::LevelOrder(TreeNode * root)
{
	vector<vector<int>> result;
	vector<TreeNode*> nextLevel;
	vector<TreeNode*> currentLevel;
	if (root != NULL) {
		nextLevel.push_back(root);
	}
	while (!nextLevel.empty()) {
		vector<int> currentLevelVal;
		currentLevel = nextLevel;
		nextLevel.clear();
		for (TreeNode* n : currentLevel) {
			currentLevelVal.push_back(n->val);
			if (n->left != NULL) {
				nextLevel.push_back(n->left);
			}
			if (n->right != NULL) {
				nextLevel.push_back(n->right);
			}
		}
		result.push_back(currentLevelVal);
	}
	return result;
}
