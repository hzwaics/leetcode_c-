#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node *next, *prev;

    Node(int k, int v) {
        key = k;
        value = v;
        next = prev = NULL;
    }
};

class DoubleLinkedList {
private:
    Node *pHead, *pTail;
    int size;

public:
    DoubleLinkedList() {
        pHead = pTail = NULL;
        size = 0;
    }

    ~DoubleLinkedList() {
        while(pHead != NULL) {
            Node *p = pHead;
            pHead = pHead->next;

            delete p;
        }
    }

    int Size() {
        return size;
    }


    // 总是在表头插入节点数据
    void addNodeHead(Node *n) {
        size++;
        if (pHead == NULL) {
            pHead = pTail = n;
            // return n;
        }
        n->next = pHead;
        n->prev = NULL;
        pHead->prev = n;
        pTail = pHead;//更新头尾节点为n
        pHead = n;

        // return n;//返回头部节点指针
    }

    void moveToHead(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;

        n->next = pHead;
        n->prev = NULL;
        pHead = n;

        // return n;
    }

    void deleteNode(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;

        size--;

        delete n;
    }

    void popTailNode() {
        pTail->prev->next = NULL;
        Node* tmp = pTail;
        pTail = pTail->prev;

        size--;

        delete tmp;
    }

    Node* getTailNode() {
        return pTail;
    }

};


class LRUCache {
private:
    int capacity, count;

    // 定义和初始化map和双向链表结构
    // Node* head, tail;
    // unordered_map<int, Node*> cache;
    map<int, Node*> cache;

    DoubleLinkedList L;

public:
    LRUCache(int capacity) {
        count = 0;
        capacity = capacity;
        
    }
    
    int get(int key) {
        // Node* n = cache.get(key);
        if (cache.find(key) == cache.end()) {
            return -1;      // cache里面没有
        }
        Node* n = cache[key];
        

        //cache 命中，移动到队列头部
        L.moveToHead(n);

        cout << "get" << n->value << endl;

        return n->value;
    }
    
    void put(int key, int value) {
        // Node *n = cache.get(key);

        if (cache.find(key) == cache.end())  {
            Node* n = new Node(key, value);

            // 写入hashmap缓存
            cache[key] = n;

            // 插入队列头部
            L.addNodeHead(n);

            ++count;

            if (count > capacity) {
                // 最后一个节点弹出
                L.popTailNode();
                // 删除tail节点的缓存
                int tmp = L.getTailNode()->key;
                cache.erase(tmp);


                count--;
            }
        } else {
            Node* n = cache[key];
            L.moveToHead(n);
        }
        
    }

};



int main(int argc, char** argv) {
    int capacity = 2;

    LRUCache cache(capacity);

    cache.put(1,1);
    cache.put(2,2);
    cache.get(1);

    return 0;
}