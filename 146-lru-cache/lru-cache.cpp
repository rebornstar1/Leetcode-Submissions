class LRUCache {
public:
    class node {
        public : 
        int key, val;
        node* prev;
        node* next;

        // constructor
        node(int _key,int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int,node*>mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNewNode(node* newNode)
    {
        node* temp = head->next;
        head->next = newNode;
        temp->prev = newNode;
        newNode->next = temp;
        newNode->prev = head;
    }

    void deleteNode(node* newNode)
    {
        node* newprev = newNode->prev;
        node* newnext = newNode->next;
        newprev->next = newnext;
        newnext->prev = newprev;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        node* resnode = mp[key];
        int res = resnode->val;
        mp.erase(key);
        deleteNode(resnode);
        addNewNode(resnode);
        mp[key] = head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mp.size() == cap)
        {
           // If the number of elements present are equal to the capacity
           if(mp.find(key) != mp.end())
           {
               auto it = mp.find(key);
               deleteNode(it->second);
              // mp[key] = value;
               node* temp = new node(key,value);
               mp[key] = temp;
               addNewNode(temp);
           }
           else
           {
              node* temp = tail->prev;
              mp.erase(temp->key);
              deleteNode(temp);
              node* newOne = new node(key,value);
              mp[key] = newOne;
              addNewNode(newOne); 
           }
        }
        else
        {
           if(mp.find(key) != mp.end())
           {
               auto it = mp.find(key);
               deleteNode(it->second);
               node* temp = new node(key,value);
               mp[key] = temp;
               addNewNode(temp);
           }
           else
           {
              node* newOne = new node(key,value);
              mp[key] = newOne;
              addNewNode(newOne); 
           }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */