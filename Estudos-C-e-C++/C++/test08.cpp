#include <iostream>

int main() {
int idade_usuario;
std::cout << "Por favor digite a sua idade e digite enter: ";
std::cin >> idade_usuario;

if (idade_usuario>=18){
    std::cout << "Usuario maior de idade!\n";
}
else {
    std::cout << "Usuario menor de idade!\n";
}

    return 0;
}