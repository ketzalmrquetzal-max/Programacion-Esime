# ============================================
# PROGRAMA: Operaciones con Matrices
# DESCRIPCIÓN: Implementa una clase para trabajar con matrices y sus operaciones
# ============================================


class Matriz:
    """
    Clase que representa una matriz y sus operaciones.

    Una matriz es un arreglo bidimensional de números organizados en filas y columnas.
    Ejemplo de matriz 2x3:
        [1, 2, 3]
        [4, 5, 6]
    """

    def __init__(self, filas, columnas, datos=None):
        """
        Constructor de la matriz.

        Parámetros:
            filas (int): Número de filas
            columnas (int): Número de columnas
            datos (list): Opcional, matriz pre-llenada (lista de listas)

        Si no se proporcionan datos, crea una matriz de ceros.
        """
        self.filas = filas
        self.columnas = columnas
        if datos:
            self.datos = datos  # Usa los datos proporcionados
        else:
            # Crea una matriz de ceros usando list comprehension
            # [[0, 0, 0], [0, 0, 0]] para una matriz 2x3
            self.datos = [[0] * columnas for _ in range(filas)]

    def llenar(self, valores):
        """
        Llena la matriz con una lista de valores en orden de filas.

        Parámetros:
            valores (list): Lista plana de valores

        Ejemplo:
            Para una matriz 2x3, valores=[1,2,3,4,5,6] crea:
            [1, 2, 3]
            [4, 5, 6]
        """
        idx = 0
        for i in range(self.filas):
            for j in range(self.columnas):
                if idx < len(valores):
                    self.datos[i][j] = valores[idx]
                    idx += 1

    def __mul__(self, otro):
        """
        Sobrecarga del operador * para multiplicación.
        Soporta dos tipos de multiplicación:
        1. Escalar: matriz * número
        2. Matricial: matriz * matriz

        Parámetros:
            otro: Puede ser un número (int/float) o una Matriz

        Returns:
            Matriz: Nueva matriz con el resultado
        """
        # Caso 1: Multiplicación por escalar
        if isinstance(otro, (int, float)):
            r = Matriz(self.filas, self.columnas)
            for i in range(self.filas):
                for j in range(self.columnas):
                    r.datos[i][j] = self.datos[i][j] * otro
            return r

        # Caso 2: Multiplicación matricial
        elif isinstance(otro, Matriz):
            # Validación: columnas de A debe = filas de B
            # Para A(m×n) × B(n×p) = C(m×p)
            r = Matriz(self.filas, otro.columnas)
            for i in range(self.filas):
                for j in range(otro.columnas):
                    s = 0
                    # Producto punto de fila i de A con columna j de B
                    for k in range(self.columnas):
                        s += self.datos[i][k] * otro.datos[k][j]
                    r.datos[i][j] = s
            return r

    def mostrar(self):
        """
        Muestra la matriz en formato legible.
        Redondea los valores a 2 decimales para mejor presentación.
        """
        for fila in self.datos:
            print([round(x, 2) for x in fila])


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    # Crea una matriz A de 2×3
    A = Matriz(2, 3)
    A.llenar([1, 2, 3, 4, 5, 6])
    print("A:")
    A.mostrar()  # [[1, 2, 3], [4, 5, 6]]

    # Multiplicación por escalar
    print("A * 2:")
    (A * 2).mostrar()  # [[2, 4, 6], [8, 10, 12]]

    # Crea una matriz B de 3×2
    B = Matriz(3, 2)
    B.llenar([7, 8, 9, 10, 11, 12])
    print("B:")
    B.mostrar()  # [[7, 8], [9, 10], [11, 12]]

    # Multiplicación matricial: A(2×3) × B(3×2) = C(2×2)
    print("A * B:")
    (A * B).mostrar()
