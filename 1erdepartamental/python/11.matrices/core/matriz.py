# Operaciones con matrices


class Matriz:
    def __init__(self, filas, columnas):
        self.__datos = [[0] * columnas for _ in range(filas)]
        self.__filas = filas
        self.__columnas = columnas

    def set(self, i, j, valor):
        self.__datos[i][j] = valor

    def get(self, i, j):
        return self.__datos[i][j]

    def __mul__(self, otro):
        # __mul__ permite usar operador * para escalar Y matrices
        if isinstance(otro, (int, float)):
            # Multiplicación escalar (matriz * número)
            resultado = Matriz(self.__filas, self.__columnas)
            for i in range(self.__filas):
                for j in range(self.__columnas):
                    resultado.set(i, j, self.__datos[i][j] * otro)
            return resultado

        # Multiplicación matricial
        if self.__columnas != otro.__filas:
            raise ValueError("Dimensiones incompatibles")

        resultado = Matriz(self.__filas, otro.__columnas)
        for i in range(self.__filas):
            for j in range(otro.__columnas):
                suma = sum(
                    self.__datos[i][k] * otro.__datos[k][j]
                    for k in range(self.__columnas)
                )
                resultado.set(i, j, suma)
        return resultado

    def __str__(self):
        return "\n".join([str(fila) for fila in self.__datos])
