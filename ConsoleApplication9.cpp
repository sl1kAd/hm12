#include <iostream>
#include "Header.h"
#include <random>



using namespace std;


int countDepth(BinTreeIntNode *node)
{
	if (node == NULL)
	{
		return 0;
	}

	int left = 0;

	int right = 0;

	if (node->left != NULL)
	{
		left = countDepth(node->left);
	}
	if (node->right != NULL)
	{
		right = countDepth(node->right);
	}
	return 1 + ((left > right) ? left : right);
}

bool isBalancedRool(BinTreeIntNode* root)
{
	return abs(countDepth(root->left) - countDepth(root->right)) <= 1;
}

void fillTree(int size, BinTreeIntNode* root)
{
	for (int i = 0; i < size; ++i)
	{
		treeInsert(root, data:rand() % 1000);
	}
}

BinTreeIntNode* searchNode(BinTreeIntNode *root, int data)
{
	if (root == NULL || root->key == data)
		return root;

	if (data < root->key)
		return searchNode(root->left, data);
	else
		return searchNode(root->right, data);
}

int isBalanced(BinTreeIntNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int leftSize = isBalanced(node->left);

	int rightSize = isBalanced(node->right);
	
	if (leftSize == -1 || rightSize == -1 || abs(leftSize - rightSize > 1))
		return -1;
	return ((leftSize > rightSize) ? leftSize : rightSize) + 1;
}

int main()
{
	const int TREES = 50;

	const int size = 10000;

	int balanced = 0;

	for (int i = 0; i < TREES; ++i)
	{
		BinTreeIntNode *node = NULL;

		BinTreeIntNode *root = treeInsert(node, data:rand() % 1000);

		fillTree(size, root);

		balanced += isBalancedRoot(root) ? 1 : 0;
	}

	printf("%d%% \n", balanced * 100 / TREES);

	balanced = 0;

	for (int i = 0; i < TREES; ++i)
	{
		BinTreeIntNode *node = NULL;

		BinTreeIntNode *root = treeInsert(node, data:rand() % 1000);

		fillTree(size, root);

		balanced += (isBalanced(root) != -1) ? 1 : 0;
	}
	printf("%d%% \n", balanced * 100 / TREES);

	return 0;
}

