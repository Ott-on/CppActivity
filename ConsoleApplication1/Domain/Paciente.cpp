#include "Paciente.h"
#include <iostream>

int Paciente::getId() const {
    return id;
}

StatusPaciente Paciente::getStatus() const {
    return status;
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
	std::cout << "ID: " << id << "\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Batimento: " << batimento << "\n";
    std::cout << "Oxigenacao: " << oxigenacao << "\n";
    std::cout << "Temperatura: " << temperatura << "\n";
    std::cout << "Pressao Sistolica: " << pressao.sistolica << "\n";
    std::cout << "Pressao Diastolica: " << pressao.diastolica << "\n";
}

void Paciente::atualizarSinaisVitais(int batimento, double oxigenacao, double temperatura, Pressao pressao) {
    this->batimento = batimento;
    this->oxigenacao = oxigenacao;
    this->temperatura = temperatura;
    this->pressao = pressao;
}