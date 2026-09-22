#pragma once
#include <string>
#include "Pressao.h"
#include "StatusPaciente.h"

class Paciente
{
private:
	int id;
	std::string nome;
	int batimento;
	double oxigenacao;
	double temperatura;
	Pressao pressao;
	StatusPaciente status;

public:
	Paciente(
		int id,
		std::string nome,
		int batimento,
		double oxigenacao,
		double temperatura,
		Pressao pressao
	);
	int getId() const;
	bool darAlta();
	bool registrarObito();
	StatusPaciente getStatus() const;
	void atualizarSinaisVitais(int batimento, double oxigenacao, double temperatura, Pressao pressao);
	void mostrarDados();
};

