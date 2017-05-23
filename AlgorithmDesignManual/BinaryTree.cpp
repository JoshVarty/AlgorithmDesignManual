//A little binary tree for a little repo

class BinaryTree {
public:
	int item;
	BinaryTree *parent;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree * SearchTree(BinaryTree * tree, int searchValue);
	BinaryTree * FindMinimum(BinaryTree * tree);
	void PrintInOrder(BinaryTree * tree);
	void Insert(BinaryTree ** tree, int value, BinaryTree *parent);
	//Not sure about this one
	void Delete(BinaryTree ** tree, int value, BinaryTree *parent);
};

