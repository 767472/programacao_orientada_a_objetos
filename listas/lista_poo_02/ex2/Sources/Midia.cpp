#include "Midia.h"

Midia::Midia(std::string titulo, int ano, double duracao) 
    : titulo(titulo), ano(ano), duracao(duracao) {}

Midia::~Midia() {}

void Midia::infoDetalhada() const {
    std::cout << "Titulo: " << titulo << " | Ano: " << ano 
              << " | Duracao: " << duracao << " min\n";
}

bool Midia::combina(std::string termo) const {
    return titulo.find(termo) != std::string::npos;
}