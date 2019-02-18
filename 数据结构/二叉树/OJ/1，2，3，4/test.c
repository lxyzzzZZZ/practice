//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (q == NULL && p == NULL){
		return true;
	}
	if (p != NULL && q != NULL && p->val == q->val){
		return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
	else{
		return false;
	}
}
//给定一个二叉树，返回它的 前序 遍历。
void preorder(struct TreeNode* root, int* returnSize, int* ret){
	if (root != NULL){
		ret[(*returnSize)++] = root->val;
		preorder(root->left, returnSize, ret);
		preorder(root->right, returnSize, ret);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int)* 1000);
	*returnSize = 0;
	preorder(root, returnSize, ret);
	return ret;
}
//给定一个二叉树，返回它的中序 遍历。
void inorder(struct TreeNode* root, int* returnSize, int* ret){
	if (root != NULL){
		inorder(root->left, returnSize, ret);
		ret[(*returnSize)++] = root->val;
		inorder(root->right, returnSize, ret);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int)* 1000);
	*returnSize = 0;
	inorder(root, returnSize, ret);
	return ret;
}
//给定一个二叉树，返回它的 后序 遍历。
void postorder(struct TreeNode* root, int* returnSize, int* ret){
	if (root != NULL){
		postorder(root->left, returnSize, ret);
		postorder(root->right, returnSize, ret);
		ret[(*returnSize)++] = root->val;
	}
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int)* 1000);
	*returnSize = 0;
	postorder(root, returnSize, ret);
	return ret;
}