#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head, ListNode *prev = nullptr) {
    if (!head) {
        return prev;
    }
    auto next = head->next;
    head->next = prev;
    return reverse(next, head);
}

ListNode *reverseList(ListNode *head) {
    return reverse(head);
}

int main() {
    auto list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    auto mid = reverseList(list);

    while (mid != nullptr) {
        std::cout << mid->val << " ";
        mid = mid->next;
    }
}