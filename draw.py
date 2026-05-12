import pandas as pd
import matplotlib.pyplot as plt

# 1. Читаем файл (убедись, что скрипт лежит в той же папке, что и results.csv)
try:
    df = pd.read_csv('results.csv')
except FileNotFoundError:
    print("Файл results.csv не найден!")
    exit()

# 2. Настраиваем размер графика
plt.figure(figsize=(10, 6))

# 3. Рисуем линии для каждого алгоритма
# Используем маркеры (o, s, ^, d) чтобы графики визуально отличались
plt.plot(df['Size'], df['Insertion'], marker='o', label='Вставками (Insertion)')
plt.plot(df['Size'], df['Pyramid'], marker='s', label='Пирамидальная (Heap)')
plt.plot(df['Size'], df['Merge'], marker='^', label='Слиянием (Merge)')
plt.plot(df['Size'], df['StdSort'], marker='d', linestyle='--', label='std::sort (Эталон)')

# 4. Оформляем внешний вид
plt.title('Зависимость времени сортировки от размера массива')
plt.xlabel('Количество элементов в массиве')
plt.ylabel('Время (секунды)')
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend() # Добавляем легенду

# 5. Сохраняем картинку для твоего отчета и показываем на экране
plt.tight_layout()
plt.savefig('sorting_graph.png', dpi=300)
plt.yscale('log') # Делает ось Y логарифмической
plt.show()