//replace the parent node by the sum of its child nodes
#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        left = NULL;
        right = NULL;
        data = d;
    }
};

Node* buildTree(){
    int d;
    cin>>d;

    if(d== -1){
        return NULL;
    }

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
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

int replaceSum(Node *root){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int leftsum = replaceSum(root->left);
    int rightsum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftsum+rightsum;
    return temp+root->data;

}

int main(){
    Node *root = buildTree();
    bfs(root);
    replaceSum(root);
    bfs(root);
    cout<<endl;
    return 0;
}