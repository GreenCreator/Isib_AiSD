#include <vector>
#include <iostream>
#include <unordered_map>

//Вход: l1 = [2,4,3], l2 = [5,6,4]
// Выход: [7,0,8]
// Объяснение: 342 + 465 = 807.
//Пример 2:
//
//Вход: l1 = [0], l2 = [0]
// Выход: [0]
//Пример 3:
//
//Вход: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Выход: [8,9,9,9,0,0,0,1]
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* result = new ListNode(0);
    ListNode* curr = result;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return result->next;
}

int main() {
    auto l = new ListNode(1, new ListNode(2, new ListNode(3)));
    auto l2 = new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7))));


    auto sum = addTwoNumbers(l, l2);

    for (auto current = sum; current != nullptr; current = current->next) {
        std::cout << current->val << " ";
    }
}

