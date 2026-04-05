class LRUCache {
public:
    struct LinkedList {
        LinkedList* prev;
        LinkedList* next;
        int key, value;
    };
    int maxCapacity;
    unordered_map <int, LinkedList*> key_node_cache;
    LinkedList* head, *tail;
    LRUCache(int capacity) {
        head = new LinkedList ();
        tail = new LinkedList ();
        head -> next = tail;
        tail -> next = NULL;
        tail -> prev = head;
        head -> prev = NULL;
        maxCapacity = capacity;
    }

    LinkedList* deleteNode (int key) {
        LinkedList* currentNode = key_node_cache[key];
        currentNode -> prev -> next = currentNode -> next;
        currentNode -> next -> prev = currentNode -> prev ;
        return currentNode;

    }
    void insertAfterHead (LinkedList* node) {
        LinkedList* headNext = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = headNext;
        headNext -> prev = node;

    }
    
    int get(int key) {
        // check map if this key
        // if exists before returning just put that node on the front after head
        // then return the value
        // else return -1
        if (key_node_cache.find(key) == key_node_cache.end()) return -1;
        LinkedList* currentNode = deleteNode (key);
        insertAfterHead (currentNode);

        return currentNode -> value;

    }
    
    void put(int key, int value) {
        // check if value already exisits using map
        // if already there then update it at both map and LL 
        // then put that element next to head
        // else create new node next to the head
        if (key_node_cache.find(key) == key_node_cache.end()) {
            LinkedList* node = new LinkedList ();
            node -> value = value;
            node -> key = key;

            insertAfterHead (node);
            key_node_cache[key] = node;

        } else {
            key_node_cache[key] -> value = value;

        LinkedList* currentNode = deleteNode (key);
        insertAfterHead (currentNode);

        }
        
        if (key_node_cache.size() > maxCapacity) {
            LinkedList* nodeToDelete = deleteNode (tail -> prev -> key);
            key_node_cache.erase(nodeToDelete -> key);
        }
    }
};
// tip: clearly communicate everything like in start when u reiterate the question.
// think before u tell the solution - 1-2 min thinking
//HW. learn how deque works 
// all data structure traversal

//  (5,5) (3,3) (2,2) (1,1)       (4,4)
 // 1. push anywhere
 // 2. pop anywhere
 // 3. maintain sequence 
//  arr  

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */