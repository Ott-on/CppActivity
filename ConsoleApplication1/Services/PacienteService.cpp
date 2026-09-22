#include "PacienteService.h"

bool PacienteService::cadastrarPaciente(const Paciente& paciente) {
	if (repository.buscarPaciente(paciente.getId())) {
		return false; 
	}
	repository.adicionarPaciente(paciente);
	return true;
}

bool PacienteService::atualizarPaciente(int id, int novoBatimento, double novaOxigenacao, double novaTemperatura, Pressao novaPressao) {
	Paciente* paciente = repository.buscarPaciente(id);
	
	if (paciente != nullptr) {
		paciente->atualizarSinaisVitais(novoBatimento, novaOxigenacao, novaTemperatura, novaPressao);
		return true;
	}
	else {
		return false;
	}
}

Paciente *PacienteService::consultarPaciente(int id) {
	return repository.buscarPaciente(id);
}

bool PacienteService::removerPaciente(int id) {
	Paciente* paciente = repository.buscarPaciente(id);

	if (paciente == nullptr) {
		return false;
	}

	if (paciente->getStatus() == StatusPaciente::Internado) {
		return false;
	}

	repository.removerPaciente(id);
	return true;

}