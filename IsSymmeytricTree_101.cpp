#include "IsSymmetricTree_101.h"
#include <vector>
void IsSymmetricTree_101::execute()
{
	this->result = this->isSymmetric(this->root);
}

IsSymmetricTree_101::IsSymmetricTree_101(std::vector<int> num)
{
}

bool IsSymmetricTree_101::isSymmetric(TreeNode* node) {
	if (node == NULL) {
		return true;
	}
	return this->isSymmetric(node->left, node->right);
}

bool IsSymmetricTree_101::isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
	if (leftNode == NULL || rightNode == NULL) return leftNode == NULL && rightNode == NULL;
	if (leftNode->val != rightNode->val) return false;
	return this->isSymmetric(leftNode->left, rightNode->right) && this->isSymmetric(leftNode->right, rightNode->left);
}