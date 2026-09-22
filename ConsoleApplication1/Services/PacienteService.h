#pragma once

#include "../Domain/Paciente.h"
#include "../Repository/PacienteRepository.h"

class PacienteService
{
public:
	PacienteService(PacienteRepository& repository);
	Paciente* consultarPaciente(int id);
    bool cadastrarPaciente(const Paciente& paciente);
	bool atualizarPaciente(int id, int novoBatimento, double novaOxigenacao, double novaTemperatura, Pressao novaPressao);
	bool removerPaciente(int id);
private:
	PacienteRepository& repository;
};