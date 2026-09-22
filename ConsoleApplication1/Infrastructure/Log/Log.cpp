#include "Log.h"
#include <fstream>

void Log::registrar(const std::string& mensagem) {
	std::ofstream arquivo("log.txt", std::ios::app);
	
	arquivo << mensagem << '\n';
}