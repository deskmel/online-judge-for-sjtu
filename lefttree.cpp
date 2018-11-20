#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	int npl;
};
//左偏树的合并操作 递归合并，俩个树，若head节点的值h1<h2则将h1的右节子树和H2合并
TreeNode* Merge(TreeNode* H1,TreeNode *H2)
{
	if (H1==NULL)
		return H2;
	if (H2==NULL)
		return H1;
	if (H1->val<H2->val)
		return Merge1(H1,H2);
	else return Merge1(H2,H1);
}
static TreeNode * Merge1(TreeNode *H1,TreeNode *H2)
{
	if (H1->left==NULL)
		H1->left = H2;
	else 
	{
		H1->right = Merge(H1->right,H2)
		if (H1->left->npl<H1->right->npl)
		{
			TreeNode *tmp = H1->left;
			H1->left=H2->left;
			H2->left=tmp;
			H1->npl=H1->right->npl+1;
		}
	}
	return H1; 
}
TreeNode* Insert(int x,TreeNode * H)
{
	TreeNode * SingleNode;
	SingleNode=new node 
}


int main(int argc, char const *argv[])
{
	
	return 0;
}