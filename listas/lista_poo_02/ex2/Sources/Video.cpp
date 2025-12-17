#include "Video.h"

Video::Video(std::string titulo, int ano, double duracao, std::string resolucao, std::string codec)
    : Midia(titulo, ano, duracao), resolucao(resolucao), codec(codec) {}

Video::~Video() {}

void Video::reproduzir() const {
    std::cout << "Reproduzindo video: " << titulo << " [" << resolucao << "]\n";
}

void Video::infoDetalhada() const {
    Midia::infoDetalhada();
    std::cout << "   -> Tipo: Video | Res: " << resolucao << " | Codec: " << codec << "\n";
}

bool Video::combina(std::string termo) const {
    return Midia::combina(termo) || resolucao.find(termo) != std::string::npos;
}