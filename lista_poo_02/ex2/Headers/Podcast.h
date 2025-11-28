#ifndef PODCAST_H
#define PODCAST_H

#include "Midia.h"
#include <vector>

class Podcast : public Midia {
private:
    std::string host;
    std::vector<std::string> convidados;

public:
    Podcast(std::string titulo, int ano, double duracao, std::string host);
    ~Podcast() override;

    void adicionarConvidado(std::string nome);
    
    void reproduzir() const override;
    void infoDetalhada() const override;
    bool combina(std::string termo) const override;
};

#endif