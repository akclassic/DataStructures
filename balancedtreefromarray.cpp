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

Node* buildTreeFromArr(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
     int mid = (s+e)/2;
    Node* root = new Node(a[mid]);
    root->left = buildTreeFromArr(a,s,mid-1);
    root->right = buildTreeFromArr(a,mid+1,e);
    return root;
}


int main(){
    // Node *root = buildTree();
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildTreeFromArr(arr,0,size-1);
    bfs(root);
    
    cout<<endl;
    return 0;
}