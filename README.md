# 📊 aport-sim

**Simulador de aportes para atingir proporções desejadas entre ativos.**  
Este projeto simula aportes periódicos em uma carteira de ativos com o objetivo de alcançar uma distribuição percentual pré-definida.

---

## 🛠️ Funcionalidades

- Cálculo automático do valor necessário para cada ativo.
- Simulação iterativa com aportes fixos.
- Verificação da meta atingida com tolerância configurável.
- Separação em módulos (`simulador.cpp`, `ativos.h`, etc.).
- Integração com CMake para fácil compilação.
- [Em breve] Testes automatizados com CTest.

---

## 📦 Instalação

```bash
git clone https://github.com/seu-usuario/aport-sim.git
cd aport-sim
mkdir build && cd build
cmake ..
make
