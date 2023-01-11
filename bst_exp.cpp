#include <iostream>


using namespace std;

class bst
{

	private:

		int	key;
		bst	*left;
		bst	*right;


	public:

	bst(): key(0), left(NULL), right(NULL) {};
	bst(int value) : key(value), left(NULL), right(NULL) {};

	bst *insert(bst *root, int value)
	{
		if (!root)
			return new bst(value);
		if ( value > root->key)
			root->right = insert(root->right, value);
		else
			root->left = insert(root->left, value);
		return (root);
	};

	void traverse(bst *root)
	{
		if(!root)
			return ;
		traverse(root->left);
			cout << root->key << endl;
		traverse(root->right);
	};

	bst *search(bst *root, int value)
	{
		if (root == NULL || root->key == key)
			return (root);
		if (root->key < key)
			return search(root->right, key);
		else
			return search(root->left, key);
		return (root);
	}
};


int main()
{
	bst node;
	bst *root = NULL;

	root = node.insert(root, 0);
	node.insert(root, 20);
	node.insert(root, 10);
	node.insert(root, 3);
	node.insert(root, 5);
	node.insert(root, 8);
	node.traverse(root);
	return 0;
}