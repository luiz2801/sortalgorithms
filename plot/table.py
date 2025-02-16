import json
import csv

def get_doc(path: str):
    # Carrega o conteúdo do arquivo JSON
    with open(path, "r") as f:
        doc = json.load(f)
    return doc

def salvar_csv():
    doc = get_doc("plot/comparison.json")
    
    # Define o nome do arquivo CSV de saída
    csv_filename = "tempos_execucao.csv"
    
    # Abre o arquivo CSV para escrita
    with open(csv_filename, mode="w", newline="") as file:
        writer = csv.writer(file)

        # Escreve o cabeçalho
        writer.writerow(["Tamanho do Vetor", "QuickSort", "HeapSort", "ShellSort"])

        # Obtém os tamanhos
        sizes = [obj.get("size") for obj in doc.get("HeapSort", [])]
        quick_times = {obj.get("size"): obj.get("time") for obj in doc.get("QuickSort", [])}
        heap_times = {obj.get("size"): obj.get("time") for obj in doc.get("HeapSort", [])}
        shell_times = {obj.get("size"): obj.get("time") for obj in doc.get("ShellSort", [])}

        # Escreve os dados
        for size in sizes:
            writer.writerow([
                size,
                quick_times.get(size, ""),
                heap_times.get(size, ""),
                shell_times.get(size, "")
            ])

    print(f"Os tempos de execução foram salvos em '{csv_filename}'.")

# Chama a função para salvar os dados
salvar_csv()
