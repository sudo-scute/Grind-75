// Encodes a tree to a single string.

// converting tree to string
string serialize(TreeNode* root) {

        if (root == nullptr) {
            return "NULL,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

// Decodes your encoded data to tree.

// making tree from preorder traversal
TreeNode* makeTree(queue<string> &q){

        // each time front element of q is popped to make its tree
        string val = q.front();
        q.pop();

        if(val == "NULL"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = makeTree(q);
        root->right = makeTree(q);

        return root;
        }

// parsing our tree string into actual tree
TreeNode* deserialize(string data) { 
        
        // just filling out queue with only elements
        queue<string> q;
        string ele = "";

        for(char i : data){

            if(i == ','){
                q.push(ele);
                ele = "";
                continue;
            }
            else{
                ele += i;  // for numbers like 124
            }
        }

        if(ele.size() != 0){ // if any number is remaining 
            q.push(ele);
        }

        return makeTree(q); // finally making tree using this preorder queue
}
