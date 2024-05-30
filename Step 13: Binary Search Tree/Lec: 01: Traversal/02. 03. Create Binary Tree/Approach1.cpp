void create_tree(node* root, vector<int> &vec){
        //Your code goes here
        queue<node*> qe;
        if(root!=NULL)  qe.push(root);
        
        for(int i=1;i<vec.size();i+=2)
        {
            auto it = qe.front();
            qe.pop();
            
            it->left = newNode(vec[i]);
            qe.push(it->left);
            it->right = newNode(vec[i+1]);
            qe.push(it->right);
        }
    }
