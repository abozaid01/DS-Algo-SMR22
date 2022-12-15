#include <iostream>
using namespace std;

const int k = 2;

class Node
{
public:
	int point[k]; // To store k dimensional point
	Node *left, *right;
};




//-------------------------------------------------- new node -------------------------------------------------------------------------------
Node* newNode(int arr[])
{
	Node* temp = new Node;

	for (int i=0; i<k; i++)
	temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	return temp;
}
//===========================================================================================================================================



//---------------------------------------------------- insert ---------------------------------------------------------------------------------
Node *insertRec(Node *root, int point[], unsigned depth)
{
	if (root == NULL)
	return newNode(point);

	unsigned cd = depth % k;

	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth + 1);
	else
		root->right = insertRec(root->right, point, depth + 1);

	return root;
}

Node* insert(Node *root, int point[])
{
	return insertRec(root, point, 0);
}
//===============================================================================================================================================






// -------------------------------------------------------------- compareing points -----------------------------------------------------------
bool arePointsSame(int point1[], int point2[])
{
	for (int i = 0; i < k; ++i)
		if (point1[i] != point2[i])
			return false;

	return true;
}
//=============================================================================================================================================





//----------------------------------------------------------- search ----------------------------------------------------------------------
bool searchRec(Node* root, int point[], unsigned depth)
{
	if (root == NULL)
		return false;
	if (arePointsSame(root->point, point))
		return true;

	unsigned cd = depth % k;

	if (point[cd] < root->point[cd])
		return searchRec(root->left, point, depth + 1);

	return searchRec(root->right, point, depth + 1);
}

bool search(Node* root, int point[])
{
	return searchRec(root, point, 0);
}
//=============================================================================================================================================






// -------------------------------------------------------------- find min -----------------------------------------------------------
int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int findMinRec(Node* root, int d, unsigned depth)
{
    if (root == NULL)
        return INT_MAX;
  
    unsigned cd = depth % k;
  
    if (cd == d) {
        if (root->left == NULL)
            return root->point[d];
        return findMinRec(root->left, d, depth + 1);
    }

    return min(root->point[d], findMinRec(root->left, d, depth + 1),  findMinRec(root->right, d, depth + 1));
}
 
int findMin(Node* root, int d)
{
    return findMinRec(root, d, 0);
}
//=============================================================================================================================================





// -------------------------------------------------------------- delete -----------------------------------------------------------
Node *minNode(Node *x, Node *y, Node *z, int d)
{
    Node *res = x;
    if (y != NULL && y->point[d] < res->point[d])
       res = y;
    if (z != NULL && z->point[d] < res->point[d])
       res = z;
    return res;
}

Node *findMinRec_del(Node* root, int d, unsigned depth)
{
    if (root == NULL)
        return NULL;
  
    unsigned cd = depth % k;
  
    if (cd == d)
    {
        if (root->left == NULL)
            return root;
        return findMinRec_del(root->left, d, depth+1);
    }
  
    return minNode(root, findMinRec_del(root->left, d, depth+1), findMinRec_del(root->right, d, depth+1), d);
}
  
Node *findMin_del(Node* root, int d)
{
    return findMinRec_del(root, d, 0);
}
  
// bool arePointsSame(int point1[], int point2[])
// {
//     for (int i = 0; i < k; ++i)
//         if (point1[i] != point2[i])
//             return false;
//
//    return true;
// }
  
void copyPoint(int p1[], int p2[])
{
   for (int i=0; i<k; i++)
       p1[i] = p2[i];
}
  
Node *deleteNodeRec(Node *root, int point[], int depth)
{
    if (root == NULL)
        return NULL;
  
    int cd = depth % k;
  
    //1) If the point to be deleted is present at root
    if (arePointsSame(root->point, point))
    {
        // If right child is not NULL
        if (root->right != NULL)
        {
            Node *min = findMin_del(root->right, cd);
  
            copyPoint(root->point, min->point);
  
            root->right = deleteNodeRec(root->right, min->point, depth+1);
        }
        // Find minimum of root's dimension in right subtree
        else if (root->left != NULL) 
        {
            Node *min = findMin_del(root->left, cd);
            copyPoint(root->point, min->point);
            root->right = deleteNodeRec(root->left, min->point, depth+1);
        }
        // If node to be deleted is leaf node
        else 
        {
            delete root;
            return NULL;
        }
        return root;
    }
  
    // 2) If current node doesn't contain point, search downward
    if (point[cd] < root->point[cd])
        root->left = deleteNodeRec(root->left, point, depth+1);
    else
        root->right = deleteNodeRec(root->right, point, depth+1);
    return root;
}
  
Node* deleteNode(Node *root, int point[])
{
   return deleteNodeRec(root, point, 0);
}
//=============================================================================================================================================



int main()
{
//------------------------------------------------------------------------- insert and search test -----------------------------------------------

	Node *root1 = NULL;
	int points1[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};

	int n1 = sizeof(points1)/sizeof(points1[0]);

	for (int i=0; i<n1; i++)
	root1 = insert(root1, points1[i]);

	int point1[] = {10, 19};
	(search(root1, point1))? cout << "Found\n": cout << "Not Found\n";

	int point2[] = {12, 19};
	(search(root1, point2))? cout << "Found\n": cout << "Not Found\n";
//------------------------------------------------------------------------- find min test -----------------------------------------------

    Node* root2 = NULL;
    int points2[][k] = { { 30, 40 }, { 5, 25 }, { 70, 70 }, { 10, 12 }, { 50, 30 }, { 35, 45 } };
  
    int n2 = sizeof(points2) / sizeof(points2[0]);
  
    for (int i = 0; i < n2; i++)
        root2 = insert(root2, points2[i]);
  
    cout << "Minimum of 0'th dimension is " << findMin(root2, 0) << endl;
    cout << "Minimum of 1'th dimension is " << findMin(root2, 1) << endl;
  
    
//------------------------------------------------------------------------- delete test -----------------------------------------------

    Node *root3 = NULL;
    int points[][k] = {{30, 40}, {5, 25}, {70, 70}, {10, 12}, {50, 30}, {35, 45}};
  
    int n3 = sizeof(points)/sizeof(points[0]);
  
    for (int i=0; i<n3; i++)
        root3 = insert(root3, points[i]);
  
    // Delete (30, 40);
    root3 = deleteNode(root3, points[0]);
  
    cout << "Root3 after deletion of (30, 40)\n";
    cout << root3->point[0] << ", " << root3->point[1] << endl;


    

	return 0;
}
