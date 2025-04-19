#include <iostream>
#include <cmath>
#include "ativo.hpp"
#include "sim.hpp"
#include "AportSimConfig.h"

void version()
{
  std::cout << "Version : " << APORTSIM_VERSION_MAJOR <<
    "." << APORTSIM_VERSION_MINOR <<
    "." << APORTSIM_VERSION_PATCH << std::endl;
}

int main() {
    version();
    int n;
    std::vector<Ativo> ativos;

    std::cout << "Quantos ativos?\n";
    std::cin >> n;
    ativos.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Nome do ativo:" << i + 1;
        std::cin >> ativos[i].nome;
        std::cout << "Valor atual:";
        std::cin >> ativos[i].current;
        std::cout << "Proporção desejada:";
        std::cin >> ativos[i].target;
    }

    double total = calcularTotal(ativos);
    int iteracoes = 0;
    bool ok = false;

    while (!ok && iteracoes < kMaxIterations) {
        total += kContribution;
        double necessidade = calcularNecessidade(ativos, total);
        distribuirAporte(ativos, necessidade);
        ok = metasAtingidas(ativos, total);

        std::cout << "\nApós iteração " << iteracoes + 1 << " (aporte acumulado: " << (iteracoes + 1) * kContribution << "):\n";
        for (const auto& a : ativos) {
            double percentual = (a.current / total) * 100.0;
            std::cout << "  " << a.nome << ": " << a.current << " (" << percentual << "%) " << (a.meta ? "[OK]" : "[...]") << "\n";
        }
        ++iteracoes;
    }

    if (iteracoes >= kMaxIterations) {
        std::cout << "Loop excedeu número máximo de iterações.\n";
    }

    std::cout << "\nResultado final após " << iteracoes << " iterações e aporte total de " << iteracoes * kContribution << ":\n";
    for (const auto& a : ativos) {
        double percentual = (a.current / total) * 100.0;
        std::cout << "  " << a.nome << ": " << a.current << " (" << percentual << "%)\n";
    }
}
