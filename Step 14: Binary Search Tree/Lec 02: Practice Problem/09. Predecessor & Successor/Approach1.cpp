pair<int, int> predecessorSuccessor(TreeNode *root, int key)

{

    // Write your code here.

    if(root == NULL){

        pair<int , int> p = make_pair(NULL , NULL);

        return p;

    }

 

    int pred =-1;

    int succ = -1;

 

    TreeNode* temp = root;

    while(temp!=NULL){

    if(key>temp->data ){

        pred = temp->data;

        temp = temp->right;

    }

    else if(key<temp->data){

        succ =temp->data;

        temp = temp->left;

    }

    else if(key==temp->data){

        break;

    }

    }

 

    if(temp==NULL){

        return make_pair(pred,succ);

    }

    

    TreeNode* leftTree = temp->left;

    TreeNode* rightTree = temp->right;

 

    while(leftTree!=NULL){

        pred = leftTree->data;

        leftTree = leftTree->right;

    }

 

    while(rightTree!=NULL){

        succ = rightTree->data;

        rightTree = rightTree->left;

    }

 

    return make_pair(pred,succ);

 

}
