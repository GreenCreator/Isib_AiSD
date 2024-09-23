
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {

}

int main() {
    auto list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    std::cout << isPalindrome(list);
}