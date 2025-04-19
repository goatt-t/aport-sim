#include <cmath>
#include "ativo.hpp"
#include "sim.hpp"
#include "ativo.hpp"

double calcularTotal(const std::vector<Ativo>& ativos) {
    double soma = 0.0;
    for (const auto& a : ativos){
        soma += a.current;
    }
    return soma;
}

double calcularNecessidade(std::vector<Ativo>& ativos, double total) {
    double necessidadeTotal = 0.0;
    for (auto& a : ativos) {
        double falta = a.target * total - a.current;
        a.ratio = (falta > 0) ? falta : 0.0;
        necessidadeTotal += a.ratio;
    }
    return necessidadeTotal;
}

void distribuirAporte(std::vector<Ativo>& ativos, double necessidadeTotal) {
    for (auto& a : ativos) {
        a.ratio = (necessidadeTotal > 0.0) ? (a.ratio / necessidadeTotal) * kContribution : 0.0;
        a.current += a.ratio;
    }
}

bool metasAtingidas(std::vector<Ativo>& ativos, double total) {
    bool todas = true;
    for (auto& a : ativos) {
        double proporcaoAtual = a.current / total;
        a.meta = std::fabs(proporcaoAtual - a.target) < kEpsilon;
        if (!a.meta){
            todas = false;
        }
    }
    return todas;
}