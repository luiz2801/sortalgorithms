#include <iostream>
#include <Python.h>


void loadPythonModule(){
    // Inicializa o interpretador Python
    Py_Initialize();

    // Nome do arquivo do script (sem ".py")
    PyObject *sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_DecodeFSDefault("."));
    
    PyObject *pName = PyUnicode_DecodeFSDefault("plot.plot");

    // Importa o módulo (o script Python precisa estar no mesmo diretório ou no PYTHONPATH)
    PyObject *pModule = PyImport_Import(pName);
    Py_XDECREF(pName);

    if (pModule != nullptr) {
        // Obtém a função desejada do script
        PyObject *pFunc = PyObject_GetAttrString(pModule, "plotar_grafico");

        // Verifica se a função pode ser chamada
        if (PyCallable_Check(pFunc)) {
            // Chama a função Python sem argumentos
            PyObject_CallObject(pFunc, nullptr);
        } else {
            std::cerr << "Erro: Função não encontrada ou não pode ser chamada.\n";
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
