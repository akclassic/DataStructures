#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int key){
    Node* node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node; 
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int getBalance(Node* root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node *rightRotate(Node *root){
    //create nodes
    Node *x = root->left;
    Node *y = x->right;

    //do rotation
    x->right = root;
    root->left = y;

    //update heights
    root->height = max(height(root->left),height(root->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    //return new root
    return x;
}

Node *leftRotate(Node *root){
    //create nodes
    Node *x = root->right;
    Node *y = x->left;

    //do rotation
    x->left = root;
    root->right = y;

    //update the heights
    root->height = max(height(root->left),height(root->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    //return new root
    return x;
}

Node* insert(Node *root, int key){
    if(root==NULL){
        return newNode(key);
    }
    
    if(root->data > key){
        root->left = insert(root->left,key);
    }else if(root->data < key){
        root->right = insert(root->right,key);
    }

    //update the height 
    root->height = 1 + max(height(root->left),height(root->right));

    //calculate the balance factor for the node
    int balance = getBalance(root);
 
    //1.left left case
    if(balance>1 && key < root->left->data){
        return rightRotate(root);
    }
    // Right Right Case 
	if (balance < -1 && key > root->right->data){
    	return leftRotate(root); 
    }	

	// Left Right Case 
	if (balance > 1 && key > root->left->data){ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Left Case 
	if (balance < -1 && key < root->right->data){ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

    //return the root
    return root;
}

Node* minValueNode(Node *root){
    Node *temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return root;
    }
    //key is in left subtree
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }else if(key>root->data){ //key is in the right subtree
        root->right = deleteNode(root->right,key);
    }else{
        //node with only one child or no child
        if(root->left == NULL || root->right == NULL){
            //get the left child if it exits or the right child
            Node *temp = root->left ? root->left: root->right;

            //case : no child exists
            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
                //case : one child
                //copy th contents of the non-empty child to the ancestor
                *root = *temp;
            }
            free(temp);
        }else{
            //node with two children
            //get inorder successor i.e the smallest element in the right subtree
            Node *temp = minValueNode(root->right);

            //copy the successor data to current node
            root->data = temp->data;

            //delet the successor
            root->right = deleteNode(root->right,temp->data);
        }
    }

     // If the tree had only one node then return 
    if (root == NULL){
        return root; 
    } 
      

    //update the heights
    root->height = 1+max(height(root->left),height(root->right));

    //get the balance factor
    int balance = getBalance(root);

    //check if the tree is unbalanced 
    	// Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0){
            return rightRotate(root);
        }
        

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0){ 
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0){
            return leftRotate(root);
        } 
        if (balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

  return root;
}

void preOrder(Node* root){
    if(root!=NULL){
        cout<<"Data: "<<root->data<<" height: "<<root->height<<" Balance factor: "<<getBalance(root)<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}



int main(void){
    Node *root = NULL;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,20);
    root = insert(root,2);
    //a situation for right rotation
    root = insert(root,1);
    root = insert(root,30);
    //situation for left rotation
    root = insert(root,40);
    //delete node 20
    root = deleteNode(root,40);
    //delete node 10(root element)
    root = deleteNode(root,10);
    preOrder(root);
    cout<<endl;
    return 0;
}