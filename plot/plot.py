import json
import matplotlib as plt

doc = json.load("../comparison.json")
times = []
n_comparisons = []
sizes = []

for time in doc["QuickSort"]:
    times.append(time)

for time in doc["Shell"]:
    times.append(time)

for time in doc["Heap"]:
    times.append(time)


# Plotar os resultados
plt.figure(figsize=(10, 6))
plt.plot(sizes, quick_time, label="QuickSort", marker='o')
plt.plot(sizes, shell_time, label="ShellSort", marker='s')
plt.plot(sizes, heap_time, label="HeapSort", marker='^')

plt.xlabel('Tamanho do Vetor (n)')
plt.ylabel('Tempo de Execução (s)')
plt.title('Comparação de Tempos de Ordenação')
plt.xscale('log', base=2)  # Escala logarítmica para o eixo x
plt.yscale('log')  # Escala logarítmica para o eixo y (opcional, dependendo dos dados)
plt.legend()
plt.grid(True)
plt.show()