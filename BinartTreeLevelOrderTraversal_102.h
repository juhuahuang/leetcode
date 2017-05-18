#pragma once
#include "ILeetCodeSolution.h"
#include <vector>
#include "TreeNode.h"

using namespace std;

class BinaryTreeLevelOrderTraversal_102 : public ILeetCodeSolution {
public:
	void execute() override;
	BinaryTreeLevelOrderTraversal_102(vector<int> num);
	vector<vector<int> > result;
private:
	vector<vector<int> > LevelOrder(TreeNode* root);
	TreeNode* root;
};
