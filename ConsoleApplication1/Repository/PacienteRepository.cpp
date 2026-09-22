#include "PacienteRepository.h"

void PacienteRepository::adicionarPaciente(const Paciente& paciente) {
	pacientes.push_back(paciente);
}

Paciente* PacienteRepository::buscarPaciente(int id) {
	for (int i = 0; i < pacientes.size(); i++) {
		if (pacientes[i].getId() == id) {
			return &pacientes[i];
		}
	} return nullptr;
}

bool PacienteRepository::removerPaciente(int id) {
	for (int i = 0; i < pacientes.size(); i++) {
		if (pacientes[i].getId() == id) {
			pacientes.erase(pacientes.begin() + i);
			return true;
		}
	}
	return false;
}