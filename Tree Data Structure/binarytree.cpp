#include <iostream>
#include <queue>

using namespace ::std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPre(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

void printPost(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printKthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

void printAllLevels(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printKthLevel(root, i);
    }
    cout << endl;
}

void bfs(Node *root)
{
    queue<Node *> q;
    //push the root node
    q.push(root);
    //push a NULL
    q.push(NULL);
    //while queue is not empty print the levels
    while (!q.empty())
    {
        //get the front element
        Node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            //print the element
            cout << f->data << ", ";
            //pop the element
            q.pop();

            //check for the left subtree
            if (f->left)
            {
                q.push(f->left);
            }
            //check for the right subtree
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

//function to count the no of nodes in the tree
int count(Node* root){
    if(root == NULL){
        return 0;
    }

    return 1+count(root->left)+count(root->right);
}

//function to return sum of all nodes in the tree
int sumall(Node* root){
    if(root==NULL){
        return 0;
    }

    return root->data+sumall(root->left)+sumall(root->right);
}

//diameter of the tree O(n^2)
int diameter(Node *root){
    if(root==NULL){
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

int main(void)
{
    Node *root = buildTree();
    // cout<<"preorder traversal"<<endl;
    // printPre(root);
    // cout<<endl;
    // cout<<"Inorder traversal "<<endl;
    // printInorder(root);
    // cout<<endl;
    // cout<<"PostOrder traversal"<<endl;
    // printPost(root);

    //Time Complexity == O(n^2)
    // cout<<"Level Order Traversl"<<endl;
    // printAllLevels(root);

    // level order traversal using bfs time complexity == O(n)
    cout << "Bredth First Search\n ";
    bfs(root);
    cout<<endl;

    cout<<"No of nodes in the tree: ";
    cout<<count(root)<<endl;

    cout<<"Sum of all nodes in the tree: ";
    cout<<sumall(root)<<endl;

    cout<<"Diameter of the tree is: ";
    cout<<diameter(root)<<endl;

    cout << endl;
    return 0;
}