#include <iostream>
#include "Paciente.h"
#include <vector>

Paciente* encontrarPaciente(int idBusca, std::vector<Paciente>& pacientes) {
	for (int i = 0; i < pacientes.size(); i++) {
		if (pacientes[i].getId() == idBusca) {
			return &pacientes[i];
		} 
	}
	return nullptr;
}

void atualizarPaciente(int idBusca, int novoBatimento, double novaOxigenacao, double novaTemperatura, Pressao novaPressao, std::vector<Paciente>& pacientes) {
	Paciente* encontrado = encontrarPaciente(idBusca, pacientes);	
	
	if (encontrado != nullptr) {
		encontrado->atualizarSinaisVitais(novoBatimento, novaOxigenacao, novaTemperatura, novaPressao);
	}
}

int main()
{
	std::vector<Paciente> pacientes;

    Pressao pressao1 = {120.0, 80.0};
    Pressao pressao2 = {118.0, 78.0};

    Paciente paciente(1,"Paciente 001", 80, 98.9, 37.0, pressao1);
	Paciente paciente2(2,"Paciente 002", 75, 80.8, 37.2, pressao2);

	pacientes.push_back(paciente);
	pacientes.push_back(paciente2);
		
	atualizarPaciente(1, 85, 98.8, 37.2, pressao1, pacientes);

	Paciente* encontrado = encontrarPaciente(999, pacientes);
	
	if (encontrado != nullptr) {
		encontrado->mostrarDados();
	}

	return 0;
}