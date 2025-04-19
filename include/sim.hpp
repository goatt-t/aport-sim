#ifndef SIM_H_
#define SIM_H_

#include <vector>
#include "ativo.hpp"

constexpr double kContribution = 100.0;
constexpr double kEpsilon = 1e-4;
constexpr int kMaxIterations = 2000;       

double calcularTotal(const std::vector<Ativo>& ativos);
double calcularNecessidade(std::vector<Ativo>& ativos, double total);
void distribuirAporte(std::vector<Ativo>& ativos, double necessidadeTotal);
bool metasAtingidas(std::vector<Ativo>& ativos, double total);
void simularAportes(std::vector<Ativo>& ativos);
#endif