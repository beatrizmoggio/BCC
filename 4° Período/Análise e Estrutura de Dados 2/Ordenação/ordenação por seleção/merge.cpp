
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void merge(vector<int>& v, int p, int q, int r){
    // p = inicio
    // q = corte
    // r = fim

    // alocar E com  n1 elementos (p ... q)
    int n1 = q - p + 1;
    vector<int> E;
    E.reserve(n1);

    // alocar E com  n1 elementos (q + 1 ... r)
    int n2 = r - q;
    vector<int> D;
    D.reserve(n2);

    // preencher E com V[p ... q]
    for (int i = p; i <= q; i++){
        E.push_back(v[i]);
    }

    cout << "\nvetor E: ";

    for (int i = 0; i < E.size(); i++){
        cout << E[i];
        if (i != E.size() - 1){
            cout << ", ";
        }
    }

    // preencher D com V[q + 1 ... r]
    for (int j = q + 1; j <= r; j++){
        D.push_back(v[j]);
    }

    cout << "\nvetor D: ";

    for (int i = 0; i < D.size(); i++){
        cout << D[i];
        if (i != D.size() - 1){
            cout << ", ";
        }
    }

    int k = p, i = 0, j = 0;

    while ((i < n1) && (j < n2)){
        if (E[i] < E[j]){
            v[k] = E[i];
            i++;
        
        } else {
            v[k] = D[j];
            j++;
        }

        k++;
    }
    
    while (i < n1){
        v[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        v[k] = D[j];
        j++;
        k++;
    }
}


int main(){
    vector<int> v = {3, 5, 6, 0, 4, 7};
    cout << "\nvetor v: ";

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i != v.size() - 1){
            cout << ", ";
        }
    }

    cout << "\n";

    merge(v, 0, 2, 5);
    cout << "\n\nvetor selection sort: ";

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i != v.size() - 1){
            cout << ", ";
        }
    }

    cout << "\n\n";

    return 0;
}