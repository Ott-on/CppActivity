#pragma once
#include <string>
#include "Pressao.h"

class Paciente
{
private:
	int id;
	std::string nome;
	int batimento;
	double oxigenacao;
	double temperatura;
	Pressao pressao;

public:
	Paciente(
		int id,
		std::string nome,
		int batimento,
		double oxigenacao,
		double temperatura,
		Pressao pressao
	);
	int getId();
	void atualizarSinaisVitais(int batimento, double oxigenacao, double temperatura, Pressao pressao);
	void mostrarDados();
};

