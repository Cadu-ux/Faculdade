#include <iostream>

int main() {
    int idade = 17;
    std::cout << "verificando idade: " << idade << " anos.\n";
    if (idade>=18){
        std::cout << "Usuario maior de idade,acesso permitido.";
    }
    else {
        std::cout << "Usuario menor de idade,acesso negado.";

    }
    std::cout << "Programa terminado.";
    return 0;
}