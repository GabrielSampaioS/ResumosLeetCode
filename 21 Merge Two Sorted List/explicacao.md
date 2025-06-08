# Problema #21 – [Merge Two Sorted Lists]

> Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

## 🧠 Descrição

Dado duas listas encadeadas ordenadas, precisamos realizar o merge delas, mantendo a ordem crescente.

---

## 📚 Estratégias Utilizadas

### 1. Abordagem com Array + Sort

- **Descrição**: Inserimos todos os elementos das duas listas em um vetor, ordenamos, e depois criamos uma nova lista encadeada com os elementos ordenados.
- **Complexidade**:
  - Tempo: O((n + m) * log(n + m))
  - Espaço: O(n + m)

### 2. Merge Recursivo

- **Descrição**: Usamos recursão para comparar os nós e ir construindo a nova lista.
- **Complexidade**:
  - Tempo: O(n + m)
  - Espaço: O(n + m) (por causa da pilha de chamadas)

### 3. Merge Iterativo (com nó fictício)

- **Descrição**: Usamos um ponteiro (`tail`) e um nó fictício (`dummy`) para construir a nova lista iterativamente.
- **Complexidade**:
  - Tempo: O(n + m)
  - Espaço: O(1)

---

## 📊 Tabela Comparativa

| Estratégia            | Tempo          | Espaço         | Observações                        |
|-----------------------|----------------|----------------|------------------------------------|
| Array + Sort          | O(n log n)     | O(n)           | Fácil de implementar               |
| Merge Recursivo       | O(n + m)       | O(n + m)       | Usa pilha de recursão              |
| Merge Iterativo       | O(n + m)       | O(1)           | Mais eficiente em espaço (ideal)   |

---
