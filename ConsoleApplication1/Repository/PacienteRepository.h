#pragma once

#include <vector>
#include "../Domain/Paciente.h"

class PacienteRepository
{
public:
    void adicionarPaciente(const Paciente& paciente);
    Paciente* buscarPaciente(int id);
	bool removerPaciente(int id);

private:
    std::vector<Paciente> pacientes;
};