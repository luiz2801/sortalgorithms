#ifndef TOJSON_H
#define TOJSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;
using namespace std;

// Função para limpar o arquivo JSON antes de adicionar os dados
void clearJson(const string& path) {
    ofstream outputFile(path);
    if (outputFile.is_open()) {
        outputFile.close();  // Apenas fecha o arquivo, removendo seu conteúdo
    } else {
        cerr << "Erro ao abrir o arquivo para limpar!" << endl;
    }
}

// Função para escrever os dados de comparação em formato JSON
void writeJson(const string& algorithm, long long time, int size) {
    // Cria o documento JSON
    Document document;
    document.SetObject();
    Document::AllocatorType& allocator = document.GetAllocator();
    string path = "plot/comparison.json";

    // Cria o objeto JSON para o algoritmo
    Value algorithmObj(kObjectType);

    // Adiciona os dados do algoritmo (time, size)
    algorithmObj.AddMember("time", Value(static_cast<double>(time / (float)1000000)).Move(), allocator);
    algorithmObj.AddMember("size", Value(static_cast<int>(size)).Move(), allocator);

    // Se o arquivo JSON já existe, carrega o conteúdo existente
    ifstream inputFile(path);
    if (inputFile.is_open()) {
        // Lê o conteúdo do arquivo
        string jsonStr((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        document.Parse(jsonStr.c_str());
        inputFile.close();
    }

    // Adiciona os resultados do algoritmo no JSON existente
    if (document.HasMember(algorithm.c_str())) {
        document[algorithm.c_str()].PushBack(algorithmObj, allocator);
    } else {
        Value algorithmArray(kArrayType);
        algorithmArray.PushBack(algorithmObj, allocator);
        document.AddMember(Value(algorithm.c_str(), allocator), algorithmArray, allocator);
    }

    // Cria um buffer para armazenar o JSON em formato de string
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    document.Accept(writer);

    // Abre o arquivo de saída (ou cria um novo)
    ofstream outputFile(path);
    if (outputFile.is_open()) {
        outputFile << buffer.GetString();
        outputFile.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
    }
}

#endif  // TOJSON_H
