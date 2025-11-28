#include "Podcast.h"

Podcast::Podcast(std::string titulo, int ano, double duracao, std::string host)
    : Midia(titulo, ano, duracao), host(host) {}

Podcast::~Podcast() {}

void Podcast::adicionarConvidado(std::string nome) {
    convidados.push_back(nome);
}

void Podcast::reproduzir() const {
    std::cout << "Ouvindo Podcast com " << host << ": " << titulo << "\n";
}

void Podcast::infoDetalhada() const {
    Midia::infoDetalhada();
    std::cout << "   -> Tipo: Podcast | Host: " << host << "\n";
    std::cout << "   -> Convidados: ";
    for (const auto& c : convidados) {
        std::cout << c << ", ";
    }
    std::cout << "\n";
}

bool Podcast::combina(std::string termo) const {
    if (Midia::combina(termo) || host.find(termo) != std::string::npos) {
        return true;
    }
    // Procura na lista de convidados
    for (const auto& c : convidados) {
        if (c.find(termo) != std::string::npos) return true;
    }
    return false;
}