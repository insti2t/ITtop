import matplotlib.pyplot as plt

# Данные для диаграммы
sizes = [30, 20, 25, 25]
labels = ['Яблоки', 'Бананы', 'Вишни', 'Дыни']

# Построение круговой диаграммы
plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=90)

# Равные пропорции (круг остается кругом, а не эллипсом)
plt.axis('equal')

plt.title('Пример круговой диаграммы')
plt.show()