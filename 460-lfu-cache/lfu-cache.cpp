class Node {
public:
    int val;
    int key;
    int cnt;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        cnt = 1;
        prev = next = nullptr;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, pair<Node*, Node*>> freqToNode;
    int minFreq;
    int capacity;
    int size;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->size = 0;
    }

    void createFreqList(int freq) {
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        freqToNode[freq] = {head, tail};
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToFront(int freq, Node* node) {
        if (freqToNode.find(freq) == freqToNode.end()) {
            createFreqList(freq);
        }
        Node* head = freqToNode[freq].first;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void removeLFUNode() {
        auto list = freqToNode[minFreq];
        Node* tail = list.second;
        Node* nodeToRemove = tail->prev;

        removeNode(nodeToRemove);
        keyToNode.erase(nodeToRemove->key);
        size--;

        if (freqToNode[minFreq].first->next == freqToNode[minFreq].second) {
            freqToNode.erase(minFreq);
        }

        delete nodeToRemove;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end())
            return -1;

        Node* node = keyToNode[key];
        int currFreq = node->cnt;

        removeNode(node);
        if (freqToNode[currFreq].first->next == freqToNode[currFreq].second) {
            freqToNode.erase(currFreq);
            if (minFreq == currFreq)
                minFreq++;
        }

        node->cnt++;
        addNodeToFront(node->cnt, node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->val = value;
            get(key);
            return;
        }

        if (size == capacity) {
            removeLFUNode();
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;
        addNodeToFront(1, newNode);
        keyToNode[key] = newNode;
        size++;
    }
};
