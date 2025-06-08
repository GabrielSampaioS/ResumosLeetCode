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
    //3 Iterativo Merge Sort
    //Tempo: O(n+m) Espaço: O(1)
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){

    ListNode* dummy = new ListNode(-1); // Nó fictício para facilitar a manipulação
    ListNode* tail = dummy; // Ponteiro para o final da lista mesclada

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;    
        }

        tail = tail->next; // Avança o ponteiro do final da lista mesclada

        
    }
    if (list1 != nullptr) {
            tail->next = list1; // Se list1 acabou, conecta o restante de list2
    } else if (list2 == nullptr) {
            tail->next = list1; // Se list2 acabou, conecta o restante de list1
    }
            return dummy->next; // Retorna a lista mesclada, ignorando o nó fictício


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
    ListNode* mergedList = solution.mergeTwoList(list1, list2);

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