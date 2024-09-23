#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    auto list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    auto mid = middleNode(list);

    while (mid != nullptr) {
        std::cout << mid->val << " ";
        mid = mid->next;
    }
}