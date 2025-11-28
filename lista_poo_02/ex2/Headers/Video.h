#ifndef VIDEO_H
#define VIDEO_H

#include "Midia.h"

class Video : public Midia {
private:
    std::string resolucao;
    std::string codec;

public:
    Video(std::string titulo, int ano, double duracao, std::string resolucao, std::string codec);
    ~Video() override;

    void reproduzir() const override;
    void infoDetalhada() const override;
    bool combina(std::string termo) const override;
};

#endif