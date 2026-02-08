#include "Musica.h"

Musica::Musica(std::string titulo, int ano, double duracao, std::string artista, int bitrate)
    : Midia(titulo, ano, duracao), artista(artista), bitrate(bitrate) {}

Musica::~Musica() {}

void Musica::reproduzir() const {
    std::cout << "Tocando musica: " << titulo << " (" << artista << ")\n";
}

void Musica::infoDetalhada() const {
    Midia::infoDetalhada();
    std::cout << "   -> Tipo: Musica | Artista: " << artista << " | Bitrate: " << bitrate << "kbps\n";
}

bool Musica::combina(std::string termo) const {
    // Busca no título ou no artista.
    return Midia::combina(termo) || artista.find(termo) != std::string::npos;
}