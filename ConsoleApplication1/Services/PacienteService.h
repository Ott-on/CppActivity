#pragma once

#include "../Domain/Paciente.h"
#include "../Repository/PacienteRepository.h"
#include "../Infrastructure/Log/Log.h"

class PacienteService
{
public:
	PacienteService(PacienteRepository& repository, Log& log);
	Paciente* consultarPaciente(int id);
    bool cadastrarPaciente(const Paciente& paciente);
	bool atualizarPaciente(int id, int novoBatimento, double novaOxigenacao, double novaTemperatura, Pressao novaPressao);
	bool removerPaciente(int id);
	bool darAltaPaciente(int id);
	bool registrarObitoPaciente(int id);
private:
	Log& log;
	PacienteRepository& repository;
};