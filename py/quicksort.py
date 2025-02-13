import time
import random
import matplotlib
matplotlib.use('TkAgg')  # Define o backend gráfico
import matplotlib.pyplot as plt  # Agora importa corretamente o módulo de plotagem

# Função de Quicksort
def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

# Listas para armazenar tamanhos e tempos
tamanhos = []
tempos = []

# Loop para aumentar o tamanho do array e medir o tempo de execução
for n in range(10, 2000000, 1000):  # Corrigido limite para 20.000
    arr = [random.randint(0, 10000) for _ in range(n)]  # Criar um array aleatório de tamanho n
    
    inicio = time.perf_counter()
    quicksort(arr)  # Ordenação com quicksort
    fim = time.perf_counter()
    
    tamanhos.append(n)
    tempos.append(fim - inicio)  # Salvar tempo de execução

# Criar o gráfico
plt.figure(figsize=(50, 100))
plt.plot(tamanhos, tempos, marker='o', linestyle='-', color='b', label="Tempo de execução")

# Configurações do gráfico
plt.xlabel("Tamanho do Array")
plt.ylabel("Tempo de Execução (segundos)")
plt.title("Tempo de Execução do Quicksort")
plt.legend()
plt.grid(True)

# Mostrar o gráfico
plt.show()
