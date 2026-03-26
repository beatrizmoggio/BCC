#include <iostream>

template<typename T>

void trocar(T& a, T&b){
    T trocar = a;
    a = b;
    b = trocar;
}

int main(){
    int x = 10;
    int y = 5;

    trocar(x, y);
    std::cout << "int: " << x << " e " << y << "\n";

    float f1 = 5.4;
    float f2 = 7.9;

    trocar(f1, f2);
    std::cout << "float: " << f1 << " e " << f2 << "\n";

    return 0;
}
