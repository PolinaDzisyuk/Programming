import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-2, 2, 100)
y = np.linspace(-2,2, 100)

X, Y = np.meshgrid(x, y)

Z = 50 * np.exp(-(X**2 + Y**2)) + 20
x0, y0 = 0.8, 0.6
z0 = 50 * np.exp(-(x0**2 + y0**2)) + 20
print(f"T({x0}, {y0}) = {z0}")
if z0 > 35 :
    print('да')
else:
    print('нет')

fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='coolwarm')
ax.set_xlabel('x'); ax.set_ylabel('y'); ax.set_zlabel('z')
plt.show()