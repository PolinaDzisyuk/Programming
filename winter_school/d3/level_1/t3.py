import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100)
y = np.linspace(-5,5, 100)

X, Y = np.meshgrid(x, y)

Z = 10 - np.sqrt(X**2 + Y**2)
x0, y0 = 2.0, 2.0
z0 =10 - np.sqrt(x0**2 + y0**2)
print(f"H({x0}, {y0}) = {z0:.4f}")
if z0 >= 7 :
    print('да')
else:
    print('нет')

fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='rainbow')
ax.set_xlabel('x'); ax.set_ylabel('y'); ax.set_zlabel('z')
plt.show()