#include "PacienteService.h"

PacienteService::PacienteService(PacienteRepository& repository, Log& log) : repository(repository), log(log) {}

bool PacienteService::cadastrarPaciente(const Paciente& paciente) {
	if (repository.buscarPaciente(paciente.getId())) {
		log.registrar("Tentativa de cadastro: paciente ja existe");
		return false; 
	}
	repository.adicionarPaciente(paciente);
	log.registrar("Paciente cadastrado: " + std::to_string(paciente.getId()));
	return true;
}

bool PacienteService::atualizarPaciente(int id, int novoBatimento, double novaOxigenacao, double novaTemperatura, Pressao novaPressao) {
	Paciente* paciente = repository.buscarPaciente(id);
	
	if (paciente != nullptr) {
		paciente->atualizarSinaisVitais(novoBatimento, novaOxigenacao, novaTemperatura, novaPressao);
		log.registrar("Paciente atualizado: " + std::to_string(paciente->getId()));
		return true;
	}
	else {
		log.registrar("Tentativa de atualizacao: paciente nao encontrado");
		return false;
	}
}

Paciente *PacienteService::consultarPaciente(int id) {
	Paciente* paciente = repository.buscarPaciente(id);

	if (paciente == nullptr) {
		log.registrar("Tentativa de consulta: paciente nao encontrado");
	}
	else {
		log.registrar("Paciente consultado: " + std::to_string(id));
	}
	return paciente;
}

bool PacienteService::removerPaciente(int id) {
	Paciente* paciente = repository.buscarPaciente(id);

	if (paciente == nullptr) {
		log.registrar("Tentativa de remocao: paciente nao encontrado");
		return false;
	}

	if (paciente->getStatus() == StatusPaciente::Internado) {
		log.registrar("Tentativa de remocao: paciente ainda internado");
		return false;
	}

	if(paciente->getStatus() == StatusPaciente::Alta)
		log.registrar("Paciente removido: " + std::to_string(id) + " - motivo: Alta");
	else
		log.registrar("Paciente removido: " + std::to_string(id) + " - motivo: Obito");
	
	repository.removerPaciente(id);

	return true;

}

bool PacienteService::darAltaPaciente(int id) {
	Paciente* paciente = repository.buscarPaciente(id);

	if (paciente == nullptr) {
		log.registrar("Tentativa de dar alta: paciente nao encontrado");
		return false;
	}
	
	if (paciente->darAlta()) {
		log.registrar("Registro de Alta: paciente " + std::to_string(id));
		return true;
	}

	log.registrar("Tentativa de dar alta: paciente ja finalizado");
	return false;
}

bool PacienteService::registrarObitoPaciente(int id) {
	Paciente* paciente = repository.buscarPaciente(id);
	
	if (paciente == nullptr) {
		log.registrar("Tentativa de registrar obito: paciente nao encontrado");
		return false;
	}
	
	if(paciente->registrarObito()) {
		log.registrar("Registro de Obito: paciente " + std::to_string(id));
		return true;
	}

	log.registrar("Tentativa de dar obito: paciente ja finalizado");
	return false;
}