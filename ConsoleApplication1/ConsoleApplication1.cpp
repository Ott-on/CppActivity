#include "Repository/PacienteRepository.h"
#include "Infrastructure/Log/Log.h"
#include "Services/PacienteService.h"
#include <iostream>

int main()
{
    // Dependências
    PacienteRepository repository;
    Log log;

    // Service recebe as dependências
    PacienteService service(repository, log);

    // Dados iniciais do paciente
    Pressao pressao;
    pressao.sistolica = 120;
    pressao.diastolica = 80;

    Paciente paciente(
        1,
        "Joao da Silva",
        140,
        95.5,
        36.7,
        pressao
    );

    // Cadastro
    std::cout << "=== CADASTRO ===\n";

    if (service.cadastrarPaciente(paciente))
    {
        std::cout << "Paciente cadastrado com sucesso!\n";
    }
    else
    {
        std::cout << "Falha ao cadastrar paciente.\n";
    }

    // Consulta
    std::cout << "\n=== CONSULTA ===\n";

    Paciente* pacienteEncontrado = service.consultarPaciente(1);

    if (pacienteEncontrado != nullptr)
    {
        pacienteEncontrado->mostrarDados();
    }
    else
    {
        std::cout << "Paciente nao encontrado.\n";
    }

    // Dar alta
    std::cout << "\n=== DAR ALTA ===\n";

    if (service.darAltaPaciente(1))
    {
        std::cout << "Alta registrada com sucesso!\n";
    }
    else
    {
        std::cout << "Nao foi possivel dar alta.\n";
    }

    // Tentar dar alta novamente
    std::cout << "\n=== TENTAR DAR ALTA NOVAMENTE ===\n";

    if (service.darAltaPaciente(1))
    {
        std::cout << "Alta registrada com sucesso!\n";
    }
    else
    {
        std::cout << "Nao foi possivel dar alta novamente.\n";
    }

    return 0;
}