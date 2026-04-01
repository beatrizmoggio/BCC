#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int maior_pos(const vector<int>& v, int inicio, int fim){
    int maior = inicio;

    for (int i = inicio + 1; i <= fim; i++){
        if (v[i] > v[maior]){
            maior = i;
        }
        
    }

    return maior;
}


void selectionSort(vector<int>& v){
    for (int i = v.size() - 1; i > 0; i--){
        int pmaior = maior_pos(v, 0, i);
        
        int aux = v[i];
        v[i] = v[pmaior];
        v[pmaior] = aux;
    }
}


int main(){
    vector<int> v = {3, 0, 2, 6, 5};
    cout << "\nvetor v: ";

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i != v.size() - 1){
            cout << ", ";
        }
    }

    cout << "\n";

    selectionSort(v);
    cout << "vetor selection sort: ";

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i != v.size() - 1){
            cout << ", ";
        }
    }

    cout << "\n\n";

    return 0;
}