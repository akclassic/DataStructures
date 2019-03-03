#include<iostream>
#include<queue>
#include<climits>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root){
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{

            cout<<f->data<<", ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

Node* insertNode(Node* root,int data){
    //base case
    if(root==NULL){
        return new Node(data);
    }
    //recusive case
    if(data <= root->data){
        root->left = insertNode(root->left, data);
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* build(){
    int d;
    cin>>d;

    Node* root = NULL;

    while(d != -1){
        root = insertNode(root,d);
        cin>>d;
    }
    return root;
}

bool bins(Node *root, int target){
    if(root == NULL){
        return false;
    }else if(root->data == target){
        return true;
    }

    if(target < root->data){
        return bins(root->left, target);
    }else if(target > root->data){
        return bins(root->right, target);
    }
}

Node* deletion(Node* root, int target){
    if(root == NULL){
        return NULL;
    }else if(target< root->data){
        root->left = deletion(root->left,target);
        return root;
    }else if(target > root->data){
        root->right = deletion(root->right,target);
        return root;
    }else if(root->data == target){
        //1. 0 children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2. 1 child
        if(root->left!=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(root->left==NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //3. left and right child exists
        if(root->left!= NULL && root->right!=NULL){
            Node* replace = root->right;
            //return the inorder successor
            while(replace->left!=NULL){
                replace = replace->left;
            }

            root->data = replace->data;
            root->right = deletion(root->right,target);
            return root;
            
        }
    }
}

bool checkBST(Node *root, int min = INT_MIN , int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data<=max && checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max)){
        return true;
    }else{
        return false;
    }
    
}


int main(){
    Node* root = build();
    // bfs(root);
    // cout<<endl;
    // int s;
    // cin>>s;
    // root = deletion(root,s);
    // if(checkBST(root)) cout<<"Yes\n";
    // else{
    //     cout<<"No";
    // }
    if( bins(root,363)){
        cout<<"found";
    }else
    {
        cout<<"not found";
    }
    
    cout<<endl;
    bfs(root);
    cout<<endl;
}

