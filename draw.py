import pandas as pd
import matplotlib.pyplot as plt

try:
    df = pd.read_csv('results.csv')
except FileNotFoundError:
    print("Файл results.csv не найден!")
    exit()

plt.figure(figsize=(10, 6))
plt.plot(df['Size'], df['Insertion'], marker='o', label='Вставками (Insertion)')
plt.plot(df['Size'], df['Pyramid'], marker='s', label='Пирамидальная (Heap)')
plt.plot(df['Size'], df['Merge'], marker='^', label='Слиянием (Merge)')
plt.plot(df['Size'], df['StdSort'], marker='d', linestyle='--', label='std::sort (Эталон)')

plt.title('Зависимость времени сортировки от размера массива')
plt.xlabel('Количество элементов в массиве')
plt.ylabel('Время (секунды)')
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()

plt.tight_layout()
plt.savefig('sorting_graph.png', dpi=300)
plt.yscale('log')
plt.show()