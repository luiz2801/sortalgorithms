import json
import matplotlib.pyplot as plt

def plotar_grafico():
    with open("plot/comparison.json") as f:
        doc = json.load(f)

    sizes = [obj.get("size") for obj in doc["QuickSort"]] # só precisa pegar uma vez, afinal todos são iguais
    quick_times = [obj.get("time") for obj in doc["QuickSort"]]
    shell_times = [obj.get("time") for obj in doc["ShellSort"]]
    heap_times = [obj.get("time") for obj in doc["HeapSort"]]
    f.close()


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