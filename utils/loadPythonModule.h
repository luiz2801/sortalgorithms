#include <iostream>
#include <Python.h>

#ifndef LOADPYTHONMODULE_H
#define LOADPYTHONMODULE_H

//void loadPythonModule();  // Apenas a declaração da função




void chamarFuncaoPython(const char* funcName) {
    // Inicializa o interpretador Python
    Py_Initialize();
    
    // Adiciona o diretório atual ao sys.path
    PyObject *sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_DecodeFSDefault("."));
    
    // Nome do módulo Python
    PyObject *pName = PyUnicode_DecodeFSDefault("plot.plot");
    
    // Importa o módulo
    PyObject *pModule = PyImport_Import(pName);
    Py_XDECREF(pName);
    
    if (pModule != nullptr) {
        // Obtém a função desejada do script Python
        PyObject *pFunc = PyObject_GetAttrString(pModule, funcName);
        
        // Verifica se a função pode ser chamada
        if (PyCallable_Check(pFunc)) {
            // Chama a função Python sem argumentos
            PyObject_CallObject(pFunc, nullptr);
        } else {
            std::cerr << "Erro: Função " << funcName << " não encontrada ou não pode ser chamada.\n";
        }
        
        Py_XDECREF(pFunc);
        Py_XDECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Erro: Não foi possível importar o script Python.\n";
    }
    
    // Finaliza o interpretador Python
    Py_Finalize();
}

#endif