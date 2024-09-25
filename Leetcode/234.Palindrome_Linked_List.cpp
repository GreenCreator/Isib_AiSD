
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

ListNode *reverse(ListNode *head, ListNode *prev = nullptr) {
    if (!head) {
        return prev;
    }
    auto next = head->next;
    head->next = prev;
    return reverse(next, head);
}

bool isPalindrome(ListNode *head) {

    auto middle = middleNode(head);
    auto reverseMiddle = reverse(middle);
    while (reverseMiddle != nullptr) {
        if (reverseMiddle->val != head->val) {
            return false;
        }
        reverseMiddle = reverseMiddle->next;
        head = head->next;
    }
    return true;
}

int main() {
    auto list = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    std::cout << isPalindrome(list);
}