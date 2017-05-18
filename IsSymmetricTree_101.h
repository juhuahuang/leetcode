#pragma once
#include "TreeNode.h"
#include "ILeetCodeSolution.h"
#include <vector>
class IsSymmetricTree_101 : public ILeetCodeSolution {
public:
	void execute() override;
	IsSymmetricTree_101(std::vector<int> num);
	bool result;
	TreeNode* root;
private:
	bool isSymmetric(TreeNode*);
	bool isSymmetric(TreeNode*, TreeNode*);

};