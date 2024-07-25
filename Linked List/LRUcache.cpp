class LRUCache {
public:

    // doubly linked list with key and value properties
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap; // size of lru cache
    unordered_map<int, Node*> m; 
    // map to store a key with its node to check if node exists or not

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    // all new upcoming nodes are inserted just after the head node
    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        // joining the prevv and nextt of that node with each other
        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {

        // to check if node exists or not using map
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);  // adding the node to front of dll bcz it is latestly accessed

            m[key] = head -> next; // updating the node for that key
            return ans;
        }
        return -1;  // key doesnt exists
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        // deleting the node just before the tail (least recently used)
        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        
        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};
