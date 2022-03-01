#include <time.h>

typedef struct Node
{
	int key;

	struct Node* left;

	struct Node* right;

} BinTreeIntNode;

BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data)
{
	BinTreeIntNode* newNode;

	newNode = (BinTreeIntNode*)malloc(sizeof(BinTreeIntNode));

	newNode->key = data;

	newNode->left = NULL;

	newNode->right = NULL;

	BinTreeIntNode* current = t;

	BinTreeIntNode* parent = t;

	if (t == NULL)
	{
		t = newNode;
	}
	else 
	{
		while (current->key != data)
		{
			parent = current;

			if (current->key > data) {

				current = current->left;

				if (current == NULL) {
					parent->left = newNode;
					return t;
				}

			}
			else {
				current = current->right;

				if (current == NULL)
				{
					parent->right = newNode;

					return t;
				}
			}
		}
	}
	return t;
}


