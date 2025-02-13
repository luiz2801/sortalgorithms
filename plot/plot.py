import json
import matplotlib.pyplot as plt

def get_doc(path: str):
    with open(path, "r") as f:
        doc = json.load(f)
        f.close()
    return doc

def clean_doc(path: str):
    with open(path, "w"):
        pass
    

def plotar_grafico():
    # Ler o conteúdo do arquivo JSON
    path = "plot/comparison.json"
    doc = get_doc(path)
    clean_doc(path)

    # Extrair os dados necessários
    sizes = [obj.get("size") for obj in doc["QuickSort"]]  # só precisa pegar uma vez, afinal todos são iguais
    quick_times = [obj.get("time") for obj in doc["QuickSort"]]
    shell_times = [obj.get("time") for obj in doc["ShellSort"]]
    heap_times = [obj.get("time") for obj in doc["HeapSort"]]

    # Plotar os resultados
    plt.figure(figsize=(10, 6))
    plt.plot(sizes, quick_times, label="QuickSort", marker='o')
    plt.plot(sizes, shell_times, label="ShellSort", marker='s')
    plt.plot(sizes, heap_times, label="HeapSort", marker='^')

    plt.xlabel('Tamanho do Vetor (n)')
    plt.ylabel('Tempo de Execução (s)')
    plt.title('Comparação de Tempos de Ordenação')
    plt.xscale('log', base=2)  # Escala logarítmica para o eixo x
    plt.yscale('log')  # Escala logarítmica para o eixo y (opcional, dependendo dos dados)
    plt.legend()
    plt.grid(True)
    plt.show()
