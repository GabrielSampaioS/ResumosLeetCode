#include <iostream>
#include <vector>
#include <algorithm> // for std::transform
#include <map>
using namespace std;


class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        map<char, int> letraLinha;
        string linha1 = "qwertyuiop";
        string linha2 = "asdfghjkl";
        string linha3 = "zxcvbnm";

        for(char c : linha1){ letraLinha[c] = 1;}
        for(char c : linha2){ letraLinha[c] = 2;}
        for(char c : linha3){ letraLinha[c] = 3;}

        vector<int> lista(words.size()); //arazenar o id  do conjunto
        vector<string> retorno;

        int idx = 0;
        for(string palavra : words){
            string temp = palavra;
            transform(temp.begin(), temp.end(), temp.begin(), :: tolower); // nãp é atribuito pq é um iterador 

            lista[idx] = letraLinha[temp[0]];
            for(char c : temp){
                if(lista[idx] != letraLinha[c]){
                    lista[idx] = -1;
                    break;
                }
            }
            idx++;
        } 

        int idx2 = 0;
        for(int valor : lista){
            if(valor != -1){
                retorno.push_back(words[idx2]);
            }
            idx2++;
        }      

    return retorno;
        
    }
};

int main() {

    Solution sol;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> resultado = sol.findWords(words);
    for(const string& palavra : resultado) {
        cout << palavra << endl;
    }
    
    //CMD não fechar
    int x; cin >> x; 
    return 0;
}