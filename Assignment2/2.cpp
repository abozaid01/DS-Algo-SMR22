/*Given a Binary Search Tree and an integer k, we have to determine if there exist two nodes
in the BST with a sum of values equal to the given target. The input is the root of the tree and
the output can be true or false.*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
};

Node *NewNode(int data){

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root, int key){

	if (root == NULL)
		return NewNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

bool findpairUtil(Node* root, int sum,
				unordered_set<int>& set)
{
	if (root == NULL)
		return false;

	if (findpairUtil(root->left, sum, set))
		return true;

	if (set.find(sum - root->data) != set.end()) {
		cout << "Pair is found (" << sum - root->data
			<< ", " << root->data << ")" << endl;
		return true;
	}
	else
		set.insert(root->data);

	return findpairUtil(root->right, sum, set);
}

void findPair(Node* root, int sum)
{
	unordered_set<int> set;
	if (!findpairUtil(root, sum, set))
		cout << "Pairs do not exit" << endl;
}

int main(){
    
	Node* root = NULL;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 6);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 7);

	int sum = 9;
	findPair(root, sum);

	return 0;
}