#include "Paciente.h"
#include <iostream>

int Paciente::getId() const {
    return id;
}

StatusPaciente Paciente::getStatus() const {
    return status;
}

bool Paciente::darAlta() {
    if (status != StatusPaciente::Internado) {
        return false;
    }

    status = StatusPaciente::Alta;
    return true;
}


bool Paciente::registrarObito() {
    if (status != StatusPaciente::Internado) {
        return false;
    }
    
    status = StatusPaciente::Obito;
    return true;
}

Paciente::Paciente(int id, std::string nome, int batimento, double oxigenacao, double temperatura, Pressao pressao) {
    this->id = id;
    this->nome = nome;
    this->batimento = batimento;
    this->oxigenacao = oxigenacao;
    this->temperatura = temperatura;
    this->pressao = pressao;
    this->status = StatusPaciente::Internado;
}

void Paciente::mostrarDados() {
	std::cout << "ID: " << id << "| ";
    std::cout << "Nome: " << nome << "| ";
    std::cout << "Batimento: " << batimento << "| ";
    std::cout << "Oxigenacao: " << oxigenacao << "| ";
    std::cout << "Temperatura: " << temperatura << "| ";
    std::cout << "Pressao Sistolica: " << pressao.sistolica << "| ";
    std::cout << "Pressao Diastolica: " << pressao.diastolica << "| ";
}

void Paciente::atualizarSinaisVitais(int batimento, double oxigenacao, double temperatura, Pressao pressao) {
    this->batimento = batimento;
    this->oxigenacao = oxigenacao;
    this->temperatura = temperatura;
    this->pressao = pressao;
}