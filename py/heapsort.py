import time
import random
import matplotlib
matplotlib.use('TkAgg')  # Define o backend gráfico
import matplotlib.pyplot as plt  # Importa corretamente para plotagem

# Função de Heapsort
def heapify(arr, n, i):
    largest = i  # Inicializa o maior como raiz
    left = 2 * i + 1  # Filho esquerdo
    right = 2 * i + 2  # Filho direito

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)  # Continua ajustando a subárvore

def heapsort(arr):
    n = len(arr)

    # Construir o heap (reorganizar o array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extrair elementos do heap um por um
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Troca
        heapify(arr, i, 0)

# Listas para armazenar tamanhos e tempos
tamanhos = []
tempos = []

# Loop para aumentar o tamanho do array e medir o tempo de execução
for n in range(100, 2000001, 10000):  # Corrigido limite para 20.000
    arr = [random.randint(0, 1000) for _ in range(n)]  # Criar um array aleatório de tamanho n
    
    inicio = time.perf_counter()
    heapsort(arr)  # Ordenação com heapsort
    fim = time.perf_counter()
    
    tamanhos.append(n)
    tempos.append(fim - inicio)  # Salvar tempo de execução

# Criar o gráfico
plt.figure(figsize=(1000, 500))
plt.plot(tamanhos, tempos, marker='o', linestyle='-', color='r', label="Tempo de execução - Heapsort")

# Configurações do gráfico
plt.xlabel("Tamanho do Array")
plt.ylabel("Tempo de Execução (segundos)")
plt.title("Tempo de Execução do Heapsort")
plt.legend()
plt.grid(True)

# Mostrar o gráfico
plt.show()
