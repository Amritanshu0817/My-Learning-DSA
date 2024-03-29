// TREE IS A NON-LINEAR DATA STRUCTURE IN WHICH A SINGLE NODE CAN BE CONNECTED TO VARIOUS NODES
// A TREE IN WHICH ITS NODE MAY HAVE <=2 CHILD IS CALLED BINARY TREE
// THE ANCESTOR OF A NODE IN A BINARY TREE IS A NODE THAT IS AT THE UPPER LEVEL OF THE GIVEN NODE
// VICE-A-VERSA OF ANCESTOR NODE IS DESCENDENT NODE

#include<iostream>
#include<queue>
using namespace std;

class tree{

    public:
    int data;
    tree* left;
    tree* right;

    tree(int v){
        this->data = v;
        this->left = NULL;
        this->right = NULL;
    }

};

tree* build(tree* rootNode){
    cout<<"Enter the data for node ";
    int data;
    cin>>data;
    rootNode = new tree(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data in left side of the node "<<data<<endl<<"Enter -1 for no input"<<endl;
    rootNode->left = build(rootNode->left);
    cout<<"Enter the data in right side of node "<<data<<endl<<"Enter -1 for no input"<<endl;
    rootNode->right = build(rootNode->right);

    return rootNode;
    
}

void levelOrdertraversal(tree* rootNode){
// Level Order Traversal technique is defined as a method to traverse a Tree
//  such that all nodes present in the same level are traversed completely 
// before traversing the next level.

    cout<<"Printing the level order traversal"<<endl;
    // FOR PRINTING THE LEVEL ORDER TRAVERSAL OR Breadth First Search(BFS) WE HAVE TO ADD THE SEPARATOR AFTER EACH NODE LEVEL
    // FOR ADDING THE SEPARATOR WE MAKE A CONDITION LIKE IF THERE IS ANY NULL IN QUEUE THEN THERE IS A LEVEL CHANGE

    queue<tree*> q;
    q.push(rootNode);             // PUSHING THE ROOT NODE IN THE QUEUE
    q.push(NULL);                // THERE MUST BE ONLY ONE NODE AT ROOT AND WE HAVE TO ADD SEPARATOR FOR OTHER LEVEL

    while (!q.empty())
    {
        tree* temp = q.front();       // ASSINGING THE FRONT ELEMENT TO THE TEMP FOR PRINTING
        q.pop();  // POPING THE FRONT AND MOVING IT TO NEXT ELEMENT AS IN THE NEXT ITERATION TEMP WILL BE ASSIGN TO NEXT PUSHED ELEMENT

    // HERE WE ARE PUSHING NULL AFTER EVERY LEVEL CHANGE    
        if(temp == NULL){         // IF THERE IS ANY NULL PRESENT IN THE QUEUE THEN WE HAVE TO ADD SEPARATOR
            cout<<endl;          // endl AT THIS PLACE WORKING AS SEPARATOR FOR THE LEVEL OF QUEUE
            
            if(!q.empty()){      // IF QUEUE IS NOT EMPTY THEN THERE THERE MUST BE ADDED ELEMENTS FROM THE PREVIOUS TEMP
                q.push(NULL);   // NULL IS PUSHED BECAUSE THE LAST TEMP HAS ADDED ITS LEFT AND RIGHT NODES AND WE NEED SEPARATOR AFTER IT
            }
        }

    // PUSHING THE LEFT AND RIGHT NODES OF THE NODE TAKEN IN TEMP    
        else{
            cout<<temp->data<<" ";   // IF TEMP IS NOT NULL THEN IT MUST CONTAIN SOME DATA 
            if(temp ->left){          
                q.push(temp->left);   // HERE THE LEFT ELEMENT OF THE NOT-NULL TEMP IS PUSHED IN THE STACK
            }
            if(temp -> right){
                q.push(temp->right);    // HERE THE LEFT ELEMENT OF THE NOT-NULL TEMP IS PUSHED IN THE STACK
            }
        }
    }
    
}

void inorder(tree* &node){
    
    //base case:
    if(node == NULL)
    return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);

}

void preorder(tree* &node){

    //base case
    if(node == NULL)
    return;

    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(tree* &node){

    // base case 
    if(node == NULL)
    return;

    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

void buildLevelOrder(tree* &rootNode){

    queue<tree*> q;
    int data;
    cout<<"Enter the data ";
    cin>>data;
    rootNode = new tree(data);
    q.push(rootNode);

    while (!q.empty())
    {
        tree* temp = q.front();
        q.pop();

        cout<<"Enter the data for Left side of "<<temp->data<<" ";
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new tree(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data for Right side of "<<temp->data<<" ";
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new tree(rightdata);
            q.push(temp->right);
        }
    }
}


int main(){

    // 1 3 5 -1 -1 7 -1 -1 9 11 -1 -1 13 -1 -1

    tree* rootNode = NULL;

    // rootNode = build(rootNode);
    // levelOrdertraversal(rootNode);
    // cout<<"InOrder Traversal = ";
    // inorder(rootNode);
    // cout<<endl;
    // cout<<"PreOrder Traversal = ";
    // preorder(rootNode);
    // cout<<endl;
    // cout<<"PostOrder Traversal = ";
    // postorder(rootNode);
    // cout<<endl;

    buildLevelOrder(rootNode);
    levelOrdertraversal(rootNode);

    return 0;
}