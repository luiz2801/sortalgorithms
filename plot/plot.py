import json
import matplotlib
matplotlib.use('GTK3Agg')
import matplotlib.pyplot as plt

def get_doc(path: str):
    # Carrega o conteúdo do arquivo JSON
    with open(path, "r") as f:
        doc = json.load(f)
        return doc
def plotar_grafico():
    doc = get_doc("plot/comparison.json")
    #"plot/comparison.json"
    # Extrai os tamanhos e tempos de execução para cada algoritmo
    sizes = [obj.get("size") for obj in doc.get("ShellSort", [])]
    quick_times = [obj.get("time") for obj in doc.get("QuickSort", [])]
    iterative_times = [obj.get("time") for obj in doc.get("QuickIterative", [])]
    heap_times = [obj.get("time") for obj in doc.get("HeapSort", [])]
    shell_times = [obj.get("time") for obj in doc.get("ShellSort", [])]
    shell_times_ordered = [obj.get("time") for obj in doc.get("ShellSort Ordenado", [])]

    # Verifica se há dados para plotar
    if not sizes:
        print("Nenhum dado encontrado para os algoritmos.")
        return

    # Cria o gráfico
    plt.figure(figsize=(10, 6))
    if quick_times:
        plt.plot(sizes, quick_times, label="QuickSort", marker='o')
    if iterative_times:
        plt.plot(sizes, iterative_times, label="QuickIterative", marker='s')
    if heap_times:
        plt.plot(sizes, heap_times, label="HeapSort", marker='^')
    if shell_times:
       plt.plot(sizes, shell_times, label="ShellSort", marker='d')
    if shell_times_ordered:
       plt.plot(sizes, shell_times_ordered, label="ShellSort Ordenado", marker='d')
    

    # Adiciona rótulos e título
    plt.xlabel('Tamanho do Vetor (n)')
    plt.ylabel('Tempo de Execução (s)')
    plt.title('Comparação de Tempos de Execução dos Algoritmos de Ordenação em um Vetor')

    # Configura a escala logarítmica para o eixo x
    plt.xscale('log', base=2)
    #plt.yscale('log')  # Escala logarítmica para o eixo y
    #plt.xscale('linear')
    plt.yscale('linear')



    # Exibe a legenda e a grade
    plt.legend()
    plt.grid(True)

    # Exibe o gráfico
    plt.show()