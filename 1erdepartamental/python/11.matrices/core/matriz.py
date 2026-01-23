# Operaciones con matrices

#Clase matriz
class Matriz:
    #Constructor
    #Inicia la matriz en ceros
    def __init__(self, filas, columnas):
        self.__datos = [[0] * columnas for _ in range(filas)]
        self.__filas = filas
        self.__columnas = columnas
    #Función que asigna un  valor a una posición
    def set(self, i, j, valor):
        self.__datos[i][j] = valor
    #Función  que va a obtener un valor de una posición 
    def get(self, i, j):
        return self.__datos[i][j]
    #Permite multiplicación esclar y matricial
    def __mul__(self, otro):
        #Multiplicación escalar (matriz * número)
        if isinstance(otro, (int, float)):
            resultado = Matriz(self.__filas, self.__columnas)
            for i in range(self.__filas):
                for j in range(self.__columnas):
                    resultado.set(i, j, self.__datos[i][j] * otro)
            return resultado

        # Multiplicación matricial
        #Va a verificar que las dimensiones sean compatibles 
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
    

    #Método especial _str_
    def __str__(self):
        return "\n".join([str(fila) for fila in self.__datos])
