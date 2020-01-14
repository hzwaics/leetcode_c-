#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
#include <unistd.h> 

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
    // 默认各初试化头尾node节点
    DoubleLinkedList() {
        pHead = new Node(0,0);
        pTail = new Node(0,1);
        pHead->next = pTail;
        pHead->prev = NULL;
        pTail->next = NULL; 
        pTail->prev = pHead;
        size = 0;  
    }

    // 删除所有的node节点
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

        n->next = pHead->next;
        n->prev = pHead;
        pHead->next->prev = n;
        pHead->next = n;

        return;

        // return n;//返回头部节点指针
    }

    // 独立一个node节点出来
    void unlinkNode(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;

        n->prev = NULL;
        n->next = NULL;
    }

    void moveToHead(Node *n) {
        if (n == pHead->next)
            return;
        else {
            // 先独立出来这个node节点
            unlinkNode(n);
            // 再移动到表头
            addNodeHead(n);

        }

        return;
        // return n;
    }

    // 支持删除data节点
    void deleteNode(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;

        size--;

        delete n;
    }

    void popTailNode() {
        Node* tmp = pTail->prev;
        tmp->prev->next = pTail;
        pTail->prev = tmp->prev;

        delete tmp;
        
    }

    Node* getTailNode() {
        return pTail->prev;
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
        this->count = 0;
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        // Node* n = cache.get(key);
        if (cache.find(key) == cache.end()) {
            // cout << "error: -1" << endl;
            return -1;      // cache里面没有
        }
        Node* n = cache[key];
        

        //cache 命中，移动到队列头部
        L.moveToHead(n);

        // cout << "get: " << n->value << endl;

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

            if (count > this->capacity) {
                // 删除tail节点的缓存
                int tmp = L.getTailNode()->key;
                cache.erase(tmp);
                // 最后一个节点弹出
                L.popTailNode();

                count--;
            }
        } else {
            // delete node节点 & map缓存
            L.deleteNode(cache[key]);
            cache.erase(key);

            // 重新新建node，写入map缓存并插入队列头部
            Node* n = new Node(key, value);
            cache[key] = n;
            L.addNodeHead(n);
        }
        
    }

};



int main(int argc, char** argv) {
    int capacity = 2;

    LRUCache cache(capacity);

    for (int i=0; i<10000; i++) {
        cache.put(2,1);
        cache.put(2,2);
        cache.get(2);
        cache.put(1,1);
        cache.put(4,1);
        cache.get(2);

        sleep(3);

    }


    return 0;
}