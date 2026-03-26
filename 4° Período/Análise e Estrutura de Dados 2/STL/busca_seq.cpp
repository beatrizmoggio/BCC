#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cachorro{
public:
    Cachorro(string n, int i){
        nome = n;
        idade = i;
    }

    bool operator==(const Cachorro& lado_direito) const {
        return (this->nome == lado_direito.nome);
    }

    bool operator<(const Cachorro& lado_direito){
        return (this->idade < lado_direito.idade);
    }

    string nome;
    int idade;
};

template <typename T>
int buscar(const vector<T>& v, T x){
    for(int i = 0; i < v.size(); i++){
        if (v[i] == x){
            return i;
        }
    }

    return -1;
}

int main(){
    cout << "\n==================== TESTE COM INT ====================\n\n";

    vector<int> v = {3, 1, 6, 2, 4, 0};

    cout << "Vetor: [ ";
    for (int x : v){
        cout << x << " ";
    }
    cout << "]\n";

    int x = 9;
    int pos_int = buscar(v, x);

    if (pos_int != -1){
        cout << ">> Elemento " << x << " encontrado na posição " << pos_int << "\n";
    } else {
        cout << ">> Elemento " << x << " NÃO encontrado (retorno = " << pos_int << ")\n";
    }

    cout << "\n==================== TESTE COM CACHORRO ====================\n\n";

    vector<Cachorro> c;
    c.push_back(Cachorro("Meg", 6));
    c.push_back(Cachorro("Meninona", 5));
    c.push_back(Cachorro("Braguinha", 4));

    cout << "Lista de cachorros:\n";
    for (const Cachorro& x : c){
        cout << " - Nome: " << x.nome << " | Idade: " << x.idade << "\n";
    }

    Cachorro catioro("Meg", 11);
    int pos_c = buscar(c, catioro);

    cout << "\nBuscando (buscar): " << catioro.nome << ", " << catioro.idade << "\n";

    if (pos_c != -1){
        cout << ">> Encontrado na posição " << pos_c << "\n";
    } else {
        cout << ">> NÃO encontrado (retorno = " << pos_c << ")\n";
    }

    cout << "\n-------------------- Usando std::find --------------------\n\n";
    
    Cachorro catioro2("Meninona", 11);
    cout << "Buscando (std::find): " << catioro2.nome << ", " << catioro2.idade << "\n";
    
    auto it = find(c.begin(), c.end(), catioro2);
    
    if (it == c.end()){
        cout << ">> NÃO encontrado!\n";
    } else {
        cout << ">> Encontrado na posição " << (it - c.begin()) << "\n";
    }

    cout << "\n-------------------- Usando std::sort --------------------\n\n";

    sort(c.begin(), c.end());
    for(Cachorro& x : c){
        cout << x.nome << " | " << x.idade << "\n";
    }

    cout << "\n===========================================================\n\n";

    return 0;
}