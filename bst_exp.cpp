#include <iostream>


using namespace std;

/*
	binary search tree;
	how to create this non-linear data structure??
	-- by dynamically created nodes linked to each other using pointers 
		or references just the way we do it for the linked lists.
	we can define the node as an object with 3 fields :
	+ one for to store data,
	+ one for to store address or reference to left child
	+ one for to store adress or reference to right child 
*/
struct Node
{
	int		data;
	Node	*left; // stores the address of the left child
	Node	*right; // stores the address of the right child
};

// create a new node
Node *createNewNode(Node *rootptr, int data)
{
	Node *newNode = new Node();
	newNode->data = rootptr->data;
	newNode->left = rootptr->right = NULL;
	return newNode;
}

// insert a new value
void	_insert(Node *rootPtr, int data)
{
	if (rootPtr == NULL)
	{
		rootPtr = createNewNode(rootPtr, data);
	}
	else if (data <= rootPtr->data)
	{
		rootPtr->left = Insert(root->left, data);
	}
	else
	{
		rootPtr->right = Insert(rootPtr->right, data);
	}
	return rootPtr;
}

bool _search(Node *rootPtr, int data)
{
	if (rootPtr == NULL)
		return false;
	else if (rootPtr->data = data)
		return true;
	else if (data <= rootPtr->data)
		return _search(rootPtr->left, data);
	else
		return _search(rootPtr->right, data);
}

int main()
{

	struct Node	*rootPtr = NULL; // to store the address of root node

	rootPtr = _insert(rootPtr, 15);
	_insert(rootPtr, 20);
	_insert(rootPtr, 10);

}




/* class bst
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
} */