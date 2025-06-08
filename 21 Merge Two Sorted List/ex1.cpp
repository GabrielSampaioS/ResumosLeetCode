#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
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
    //1 array simple
    //Tempo: O((n+m)*log(n+m)) Espaço: O(n+m)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> intermediario;
        while (list1 != nullptr) {
            intermediario.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            intermediario.push_back(list2->val);
            list2 = list2->next;
        }

        sort(intermediario.begin(), intermediario.end());

        // criar array e insert cada elemento
        ListNode* Retorno = new ListNode();
        ListNode* curr = Retorno;
        for (int i = 0; i < intermediario.size(); i++) {
            curr->next = new ListNode(intermediario[i]);
            curr = curr->next;
        }

        return Retorno->next; // Retorna o próximo para ignorar o nó inicial vazio
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

    //Criando e preenchendo a lista 1       List1 = {1, 2, 4}
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    //Criando e preenchendo a lista 2       List2 = {1, 3, 4}
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    //Criando a solução
    Solution solution;
    //Chamando o método para mesclar as listas
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    //Imprimindo a lista mesclada
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