//check if tree is balanced or not
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

class HBpair{
    public:
        int height;
        bool balanced;
};

HBpair checkHeightBalanced(Node *root){
    HBpair p;

    if(root == NULL){
        p.height = 0;
        p.balanced = true;
        return p;
    }
    //recursive case
    HBpair left = checkHeightBalanced(root->left);
    HBpair right = checkHeightBalanced(root->right);

    p.height = max(left.height,right.height) +1;

    if(abs(left.height - right.height)<=1 && left.balanced && right.balanced){
        p.balanced = true;
    }else{
        p.balanced = false;
    }
    return p;
}

int main(){
    Node *root = buildTree();
    bfs(root);
    if(checkHeightBalanced(root).balanced){
        cout<<"Binary tree is height balanced";
    }else{
        cout<<"Tree is not height balanced";
    }
    cout<<endl;
    return 0;
}