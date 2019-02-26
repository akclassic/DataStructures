#include<iostream>
#include<queue>

using namespace::std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

Node* buildTree(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPre(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);

}

void printPost(Node* root){
    if(root == NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

void printKthLevel(Node *root, int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}

void printAllLevels(Node* root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
    }
    cout<<endl;
}

void bfs(Node *root){
    queue<Node*> q;
    //push the root node
    q.push(root);
    //while queue is not empty print the levels
    while(!q.empty()){
        //get the front element
        Node* f = q.front();
        //print the element
        cout<<f->data<<", ";
        //pop the element
        q.pop();
        //check for the left subtree
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

int main(void){
    Node* root = buildTree();
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
    cout<<"Bredth First Search ";
    bfs(root);

    cout<<endl;
    return 0;
}