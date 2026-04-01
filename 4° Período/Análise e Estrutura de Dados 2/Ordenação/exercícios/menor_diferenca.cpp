#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    vector<int> v;
    v.reserve(n);
    srand(seed);

    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }

    return v;
}


vector<int> remover_duplicatas(vector<int>& v){
    vector<int> s;

    if (v.size() == 0) return s;

    std::sort(v.begin(), v.end());
    s.push_back(v[0]);

    for (int i = 1; i < v.size(); i++){
        if (v[i] != v[i - 1]){
            s.push_back(v[i]);
        }
    }

    return s;
}


/*
Dado um vetor de inteiros positivos V, retorne um par de inteiros cuja diferença absoluta é a menor possível entre dois elementos do vetor. Considere que os inteiros devem estar em posições diferentes e que não há elementos repetidos.

1) DESORDENADO - COMPARA COM TODOS OS ELEMENTOS
    V = [10, 1, 7, 5, 14]

2) ORDENADO - COMPARA APENAS COM O ELEMENTO DO LADO
    V = [1, 5, 7, 10, 14]
*/


pair<int, int> menor_diferenca(vector<int> &v){
    vector<int> v2(v);
    sort(v2.begin(), v2.end());

    pair<int, int> par = {v2[0], v2[1]};
    int dif = v2[1] - v2[0];

    if (v.size() < 2){
        return {0, 0};

    } else if (v.size() == 2){
        return {v2[0], v2[1]};

    } else {
        for (int i = 1; i < v2.size() - 1; i++){
            int dif_atual = v2[i + 1] - v2[i];

            if (dif_atual < dif){
                dif = dif_atual;
                par = {v2[i], v2[i + 1]};
            }
            
        }
    }
    
    return par;
}


pair<int, int> menor_diferenca2(vector<int> &v){
    pair<int, int> par = {v[0], v[1]};
    int dif = v[1] - v[0];

    if (v.size() < 2){
        return {0, 0};

    } else if (v.size() == 2){
        return {v[0], v[1]};

    } else {
        for (int i = 1; i < v.size() - 1; i++){
            for (int j = i + 1; j < v.size(); j++){
                int dif_atual = abs(v[i] - v[j]);

                if (dif_atual < dif){
                    dif = dif_atual;
                    par = {v[i], v[j]};
                }
            }
        }
    }

    return par;
}


int main(int argc, char** argv){ 
    int n = std::atoi(argv[1]);

    vector<int> vetor = gerar_vetor_aleatorio(n, 5, n*10);
    
    /*
    cout << "\nvetor: [";
    for (int i = 0; i < vetor.size(); i++){
        cout << vetor[i];
        if (i != vetor.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";
    */
    
    vetor = remover_duplicatas(vetor);
    
    /*
    cout << "\nvetor sem duplicatas: [";
    for (int i = 0; i < vetor.size(); i++){
        cout << vetor[i];
        if (i != vetor.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";
    */

    /*
    sort(vetor.begin(), vetor.end());
    cout << "\nvetor ordenado: [";
    for (int i = 0; i < vetor.size(); i++){
        cout << vetor[i];
        if (i != vetor.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";
    */
    
    pair<int,int> res = menor_diferenca2(vetor);
    cout << "\npar de menor diferença: ";
    cout << "(" << res.first << ", " << res.second << ")";

    cout << "\n";
    return 0;
}
