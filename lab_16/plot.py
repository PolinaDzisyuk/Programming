import matplotlib.pyplot as plt

matrix_size = [0, 4, 20, 36, 52, 68, 84, 100, 500, 1000, 1500, 2000]

time_for_1thread = [0, 0.000444, 0.000551, 0.000769, 0.001295, 0.002269, 0.003528, 0.005552, 0.676569, 5.495549, 17.733426, 58.334117]
time_for_2thread = [0, 0.000487, 0.000508, 0.000671, 0.001098, 0.001451, 0.002558, 0.003010, 0.381243, 3.241283, 10.299421, 31.643639]
time_for_4thread = [0, 0.000605, 0.000637, 0.000585, 0.001056, 0.001150, 0.002055, 0.248110, 0.213640, 1.787352, 6.602323, 18.568714]
time_for_8thread = [0, 0.001176, 0.001426, 0.001409, 0.001268, 0.001386, 0.001446, 0.002326, 0.143069, 1.050260, 3.525122, 10.187327]
time_for_16thread = [0, 0.002184, 0.002289, 0.002288, 0.002095, 0.002230, 0.002534, 0.002601, 0.144685, 0.792744, 2.964014, 7.697051]

plt.plot(matrix_size, time_for_1thread, label="1")
plt.plot(matrix_size, time_for_2thread, label="2")
plt.plot(matrix_size, time_for_4thread, label="4")
plt.plot(matrix_size, time_for_8thread, label="8")
plt.plot(matrix_size, time_for_16thread, label="16")

plt.title("Размер матрицы vs потоки")
plt.xlabel("Размер матрицы (N)")
plt.ylabel("Время (сек)")

plt.grid(True)
plt.legend()

plt.show()