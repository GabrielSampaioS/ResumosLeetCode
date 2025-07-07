# 387. First Unique Character in a String

> 🔗 [Link para o problema no LeetCode](https://leetcode.com/problems/first-unique-character-in-a-string/)

---

## 💡 Intuition

Queremos encontrar o **primeiro caractere não repetido** de uma string.  
A abordagem mais eficiente é percorrer a string **uma única vez** para contar a frequência de cada caractere, e depois determinar o primeiro que ocorre exatamente uma vez.

---

### 📌 Etapas:

1. Criamos dois arrays de tamanho fixo 26:
   - `contador[i]`: armazena quantas vezes o caractere `'a' + i` aparece.
   - `index[i]`: armazena o índice da **primeira ocorrência** de cada caractere, inicializado com `-1`.

2. Fazemos uma primeira passagem na string:
   - Contamos a frequência de cada caractere.
   - Armazenamos a primeira posição em que ele aparece.

3. Em seguida, iteramos pelos 26 caracteres possíveis para encontrar aquele com frequência 1 e o menor índice.

4. Se nenhum for encontrado, retornamos `-1`.

---

## 🧮 Exemplo

**Entrada:** `"leetcode"`  
**Saída:** `0`  
**Explicação:** O caractere `'l'` é o primeiro que aparece apenas uma vez.

**Entrada:** `"loveleetcode"`  
**Saída:** `2`  
**Explicação:** O primeiro caractere único é `'v'`.

---

## ⏱️ Complexity

- **Tempo:** $$O(n)$$ — uma passagem sobre a string e outra fixa sobre o alfabeto.
- **Espaço:** $$O(1)$$ — utilizamos espaço constante, já que o alfabeto é fixo em 26 letras.

---

## ✅ Código

```cpp
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
```
