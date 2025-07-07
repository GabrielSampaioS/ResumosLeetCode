#include <iostream>
#include <string>
#include <climits> // Para INT_MAX
#include <algorithm> // Para fill
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        const int N = 26; // Alfabeto de 26 letras
        int contador[N] = {0};
        int index[N];
        fill(index, index + N, -1);

        // Contagem de frequência e primeiro índice de cada letra
        for(int i = 0; i < s.length(); i++) {
            int posicao = s[i] - 'a';
            contador[posicao]++;
            if(index[posicao] == -1) {
                index[posicao] = i;
            }
        }

        // Procurar o menor índice com frequência 1
        int retorno = INT_MAX;
        for(int i = 0; i < N; i++) {
            if(contador[i] == 1) {
                retorno = min(retorno, index[i]);
            }
        }

        return retorno == INT_MAX ? -1 : retorno;
    }
};

int main() {
    Solution sol;

    vector<string> testes = {
        "leetcode",        // esperado: 0 (l)
        "loveleetcode",    // esperado: 2 (v)
        "aabb",            // esperado: -1
        "abcdabc",         // esperado: 3 (d)
        "z",               // esperado: 0
        "aaabcccdeeef"     // esperado: 9 (f)
    };

    for (const string& s : testes) {
        cout << "Entrada: \"" << s << "\"\n";
        int resultado = sol.firstUniqChar(s);
        cout << "Saida: " << resultado << "\n\n";
    }

    // Para manter o terminal aberto (opcional no Windows)
    int pause;
    cin >> pause;

    return 0;
}
