import pandas as pd
import matplotlib.pyplot as plt

# Cargar archivos CSV
bf = pd.read_csv("tiempos_BF.csv")
cad = pd.read_csv("tiempos_DaC.csv")

# Graficar líneas
plt.plot(bf['n'], bf['t_mean'], label='Brute Force', marker='o')
plt.plot(cad['n'], cad['t_mean'], label='Divide and Conquer', marker='s')

# Etiquetas
plt.xlabel('Input size (n)')
plt.ylabel('Running time (nanoseconds)')
plt.yscale('log')  # Opcional: escala logarítmica en eje Y

# Leyenda y guardado
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.title('Comparación de Tiempos de Ejecución')
plt.savefig('comparacion_tiempos.png')
plt.show()
