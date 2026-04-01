#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

std::vector<int> remover_duplicatas(std::vector<int>& v){
    std::vector<int> s;

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

int main(int argc, char** argv){ 
    int n = std::atoi(argv[1]);

    vector<int> vetor = gerar_vetor_aleatorio(n, 5, 20);
    cout << "\nvetor: [";
    for (int i : vetor){
        cout << i << ", ";
    }
    cout << "]";

    sort(vetor.begin(), vetor.end());
    cout << "\nvetor ordenado: [";
    for (int i : vetor){
        cout << i << ", ";
    }
    cout << "]";

    vector<int> novoSemDuplicatas = remover_duplicatas(vetor);
    cout << "\nnvetor sem duplicatas: [";
    for (int i : novoSemDuplicatas){
        cout << i << ", ";
    }
    cout << "]";

    cout << "\n\n";
    return 0;
}
