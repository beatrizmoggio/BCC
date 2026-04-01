#include <iostream>
#include <vector>

using namespace std;

vector<int> coletar_pares(const vector<int>& v) {
    vector<int> S;

    for(int x : v){
        if(x % 2 == 0){
            S.push_back(x);
        }
    }

    return S;
}

int main(){
    vector<int> v = {2, 3, 9, 3, 2};
    cout << "vetor v: ";
    for (int x : v){
        cout << x << ", ";
    }
    
    cout << "\n";

    vector<int> z = coletar_pares(v);
    cout << "vetor z: ";
    for (int x : z){
        cout << x << ", ";
    }

    cout << "\n";    
    return 0;
}