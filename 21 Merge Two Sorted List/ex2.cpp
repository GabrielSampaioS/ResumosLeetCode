#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //2 Rercurvivo Merge Sort
    //Tempo: O(n+m) Espaço: O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //caso base
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        //Comparar os valores dos nós
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;   
        }
    }

    
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Criando e preenchendo a lista 1       List1 = {1, 2, 4}
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Criando e preenchendo a lista 2       List2 = {1, 3, 4}
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    printList(mergedList);

    // Liberando a memória alocada
    ListNode* current = mergedList;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp; 
    }
    delete list1;
    

    //CMD não fechar
    int x; cin >> x; 
    return 0;

}
