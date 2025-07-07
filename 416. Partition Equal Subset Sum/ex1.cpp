#include <iostream>
#include <vector>
#include <numeric> // para std::accumulate
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int soma = accumulate(nums.begin(), nums.end(), 0);

        // Se a soma total for ímpar, não é possível dividir em dois subconjuntos iguais
        if (soma % 2 == 1) {
            return false;
        }

        int alvo = soma / 2;
        vector<bool> dp(alvo + 1, false);
        dp[0] = true; // Soma 0 é sempre possível (conjunto vazio)

        for (int num : nums) {
            for (int i = alvo; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }

            // Otimização: parar cedo se já atingimos o alvo
            if (dp[alvo]) {
                break;
            }
        }

        return dp[alvo];
    }
};

int main() {
    Solution sol;

    // Exemplo 1: deve retornar true
    vector<int> exemplo1 = {1, 5, 11, 5};
    bool resultado1 = sol.canPartition(exemplo1);
    cout << "Resultado Exemplo 1: " << (resultado1 ? "true" : "false") << endl;

    // Exemplo 2: deve retornar false
    vector<int> exemplo2 = {1, 2, 3, 5};
    bool resultado2 = sol.canPartition(exemplo2);
    cout << "Resultado Exemplo 2: " << (resultado2 ? "true" : "false") << endl;

    // Exemplo 3: deve retornar false
    vector<int> exemplo3 = {1,2,3,5,7,5,9,1,7,2,9,1};
    bool resultado3 = sol.canPartition(exemplo3);
    cout << "Resultado Exemplo 3: " << (resultado3 ? "true" : "false") << endl;

    // Pausar CMD para visualizar resultado
    int x;
    cin >> x;
    return 0;
}
