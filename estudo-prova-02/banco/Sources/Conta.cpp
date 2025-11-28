#include "Conta.h"
#include <iostream>
#include <iomanip>
#include <ctime>

// Definição do membro estático
int Conta::proximoIdTransacao = 1;

Conta::Conta()
    : numeroConta(""), cliente(nullptr), saldo(0.0) {}

Conta::Conta(const std::string& numeroConta, Cliente* cliente, double saldoInicial)
    : numeroConta(numeroConta), cliente(cliente), saldo(saldoInicial) {}

Conta::~Conta() {
    // limpa transações alocadas
    for (Transacao* t : transacoes) {
        delete t;
    }
    transacoes.clear();
}

std::string Conta::getNumeroConta() const {
    return numeroConta;
}

Cliente* Conta::getCliente() const {
    return cliente;
}

double Conta::getSaldo() const {
    return saldo;
}

std::vector<Transacao*> Conta::getTransacoes() const {
    return transacoes;
}

bool Conta::sacar(double valor) {
    if (valor <= 0.0) return false;
    double taxa = calcularTaxa();
    double total = valor + taxa;
    if (saldo < total) return false;

    saldo -= total;
    // descrição simples; ajuste conforme necessário
    adicionarTransacao(TipoTransacao::SAQUE, valor, "Saque");
    return true;
}

bool Conta::depositar(double valor) {
    if (valor <= 0.0) return false;
    double taxa = calcularTaxa();
    double liquido = valor - taxa;
    if (liquido < 0.0) return false;

    saldo += liquido;
    adicionarTransacao(TipoTransacao::DEPOSITO, valor, "Depósito");
    return true;
}

bool Conta::transferir(Conta* contaDestino, double valor) {
    if (!contaDestino) return false;
    if (valor <= 0.0) return false;

    double taxa = calcularTaxa();
    double total = valor + taxa;
    if (saldo < total) return false;

    saldo -= total;
    contaDestino->saldo += valor;

    // registrando transações em ambas as contas
    adicionarTransacaoTransferencia(TipoTransacao::TRANSFERENCIA, valor, contaDestino->getNumeroConta(),
                                    "Transferência para " + contaDestino->getNumeroConta());
    // como estamos dentro da mesma classe, podemos acessar método protegido da outra instância
    contaDestino->adicionarTransacaoTransferencia(TipoTransacao::TRANSFERENCIA, valor, this->getNumeroConta(),
                                                  "Recebido de " + this->getNumeroConta());
    return true;
}

void Conta::exibirExtrato() const {
    std::cout << "Extrato da conta: " << numeroConta << " | Saldo: " << std::fixed << std::setprecision(2) << saldo << "\n";
    if (transacoes.empty()) {
        std::cout << "Nenhuma transação registrada.\n";
        return;
    }

    for (const Transacao* t : transacoes) {
        if (!t) continue;
        // Ajuste a chamada abaixo conforme a API da sua classe Transacao
        // Ex.: std::cout << t->toString() << "\n";
        std::cout << "[Transacao id=" << /* supondo método getId() */ /*t->getId()*/ "??"
                  << "] (ajuste a exibição conforme Transacao) \n";
    }
}

void Conta::exibirExtratoPorPeriodo(const std::time_t& dataInicio, const std::time_t& dataFim) const {
    std::cout << "Extrato da conta: " << numeroConta << " (Periodo)\n";
    bool encontrou = false;
    for (const Transacao* t : transacoes) {
        if (!t) continue;
        // Ajuste conforme a API da sua Transacao:
        // std::time_t data = t->getData();
        // if (data >= dataInicio && data <= dataFim) { std::cout << t->toString() << "\n"; encontrou = true; }
    }
    if (!encontrou) {
        std::cout << "Nenhuma transação no período informado.\n";
    }
}

void Conta::exibirInformacoes() const {
    std::cout << "Conta: " << numeroConta << " | Cliente: ";
    if (cliente) {
        // supondo que Cliente tenha getNome()
        std::cout << cliente->getNome();
    } else {
        std::cout << "N/D";
    }
    std::cout << " | Saldo: " << std::fixed << std::setprecision(2) << saldo << "\n";
}

// Observação: Ajuste o uso do construtor de Transacao abaixo conforme a definição real
void Conta::adicionarTransacao(TipoTransacao tipo, double valor, const std::string& descricao) {
    // Exemplo genérico de criação; adapte os parâmetros à sua classe Transacao
    std::time_t agora = std::time(nullptr);
    // Supondo que Transacao tenha um construtor como:
    // Transacao(int id, TipoTransacao tipo, double valor, const std::string& descricao, const std::time_t& data);
    Transacao* t = new Transacao(proximoIdTransacao++, tipo, valor, descricao, agora);
    transacoes.push_back(t);
}

void Conta::adicionarTransacaoTransferencia(TipoTransacao tipo, double valor,
                                            const std::string& contaDestino,
                                            const std::string& descricao) {
    std::time_t agora = std::time(nullptr);
    // Supondo construtor que aceita também contaDestino
    Transacao* t = new Transacao(proximoIdTransacao++, tipo, valor, descricao + " [" + contaDestino + "]", agora);
    transacoes.push_back(t);
}