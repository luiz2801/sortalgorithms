#include <fstream>
#include <iostream>

void clearJson(const std::string& filePath) {
    // Abre o arquivo em modo 'out' e 'trunc' para apagá-lo
    std::ofstream file(filePath, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON para apagar: " << "plot/comparison.json" << "\n";
        return;
    }

    // O arquivo é apagado ao ser aberto no modo trunc, então não é necessário fazer mais nada.
    file.close();
    std::cout << "Conteúdo do arquivo JSON '" << "plot/comparison.json" << "' apagado com sucesso.\n";
}
