// 单向链表的反转
// 比如有一个链表是这样的，1->2->3->4->5，反转后成为 5->4->3->2->1。

// 分析
// 实现链表反转，我们需要从第二个节点开始遍历，将当前节点的 next 指向前一个节点。这里需要注意的是，该变当前节点的 next 时，需要提前保存 next，不然遍历就会中断。

// 时间复杂度 O(n)；
// 空间复杂度 O(1)。

struct LinkNode {
    int value;
    LinkNode* next;
};

LinkNode* Reverse(LinkNode *header);

LinkNode* Reverse(LinkNode* header) {
    if (header==NULL || header->next==NULL) {
        return header;
    }

    LinkNode* pre = header, *cur = header->next;
    while (cur != NULL) {
        auto next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre
}