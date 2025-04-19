#ifndef ATIVO_H_
#define ATIVO_H_
#include <string>

struct Ativo {
    std::string nome;
    double current;
    double target;  
    double ratio;   
    bool meta;       
};
#endif