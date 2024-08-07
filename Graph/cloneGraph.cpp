/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* &originalNode , unordered_map<Node* , Node*> &ogTOclone){

        Node* clone = new Node(originalNode->val);
        ogTOclone[originalNode] = clone;

        for(auto &nbr : originalNode->neighbors){
            
            // if neighbour nodes are not mapped with their clones
            if(!ogTOclone.count(nbr)){
                dfs(nbr,ogTOclone);   // go first map yourself with ur clone
            }

            // else all its neighbours are mapped

            // pushing clones of nbr into clone's neighbours
            clone->neighbors.push_back(ogTOclone[nbr]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr){return node;}
        unordered_map<Node* , Node*>ogTOclone; // mapping each original node with its clone node
        dfs(node , ogTOclone);
        return ogTOclone[node];
    }
};
