#include <iostream>
using namespace std;
//Trees notions

/*root, parent, sibling, leaf
Depth of x = no of edges in path from root to x
Height of x = no of edges in longest path from x to a leaf
Height of tree = height of root

Applications: 
1) Storing naturally hierarchical data - fily system
2) Organize data for quick search, insertion, deletion - Binary search trees
3)Trie - dictionary
4)Network Routing Algorithm


Categories:
1. Binary Tree = a tree in which each node can have at most 2 children
	Implementation using lists: a node has a field for data, and two for the addresses of the two children
 
	Complete Binary Tree = all levels except possibly the last are completely filled and all nodes are as 
left as possible

 Max no of nodes at level i = 2^i
 Max no of nodes in a binary tree with height h = 2^(h+1) - 1 
 Min height in a binary tree is floor(log2n)
 Balanced binary tree = diff between height of left and right subtree for every node is not more than K (mostly 1)

*/

//Binary Tree-implementation
//1. dynamically created nodes
class Node {
	int data;
	Node* left;
	Node* right;
};


/*2.arrays - number each node from left to right on every level(complete binary tree)
-> for node at index i:
	left-child-index = 2i + 1;
	right-child-index = 2i + 2;
*/

//Binary Search Tree 
/*
	We can perfom binary search in a sorted array with O(log n)
	With BST cost of Search, Insert, Remove of X will be O(log n)

	BST = a bin tree which for each node, value of all the nodes  in left
subtree is lesser or equal and value of all nodes in the right subtree is 
greater
Ex:
		 15
	10        20
  8    12   17   25

*/

class BstNode {
public:
	int data ;
	BstNode* left;
	BstNode* right;
	BstNode(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
BstNode* getNewNode(int data) {
	BstNode* newNode = new BstNode(data);
	return newNode;
}
BstNode* Insert(BstNode* root, int data) {
	if (root == nullptr) {
		root = getNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}
bool Search(BstNode* root, int data) {
	if (root == nullptr) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}
int main() {
	BstNode* rootPtr;
	rootPtr = nullptr;
	rootPtr = Insert(rootPtr, 15);
	rootPtr = Insert(rootPtr, 10);
	rootPtr = Insert(rootPtr, 20);
	rootPtr = Insert(rootPtr, 25);
	rootPtr = Insert(rootPtr, 8);
	rootPtr = Insert(rootPtr, 12);
	int number;
	cout << "Enter number be seached\n";
	cin >> number;
	if (Search(rootPtr, number) == true) cout << "Found" << endl;
	else cout << "Not Found" << endl;
}
