//������������������дһ�����������������Ƿ���ͬ��
//
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
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
//����һ������������������ ǰ�� ������
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
//����һ���������������������� ������
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
//����һ������������������ ���� ������
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