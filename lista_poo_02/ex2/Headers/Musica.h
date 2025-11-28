#ifndef MUSICA_H
#define MUSICA_H

#include "Midia.h"

class Musica : public Midia {
private:
    std::string artista;
    int bitrate; // kbps

public:
    Musica(std::string titulo, int ano, double duracao, std::string artista, int bitrate);
    ~Musica() override;

    void reproduzir() const override;
    void infoDetalhada() const override;
    bool combina(std::string termo) const override;
};

#endif