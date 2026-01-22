class Matriz:
    def __init__(self, filas, columnas, datos=None):
        self.filas = filas
        self.columnas = columnas
        if datos:
            self.datos = datos
        else:
            self.datos = [[0] * columnas for _ in range(filas)]

    def llenar(self, valores):
        idx = 0
        for i in range(self.filas):
            for j in range(self.columnas):
                if idx < len(valores):
                    self.datos[i][j] = valores[idx]
                    idx += 1

    def __mul__(self, otro):
        if isinstance(otro, (int, float)):
            r = Matriz(self.filas, self.columnas)
            for i in range(self.filas):
                for j in range(self.columnas):
                    r.datos[i][j] = self.datos[i][j] * otro
            return r
        elif isinstance(otro, Matriz):
            r = Matriz(self.filas, otro.columnas)
            for i in range(self.filas):
                for j in range(otro.columnas):
                    s = 0
                    for k in range(self.columnas):
                        s += self.datos[i][k] * otro.datos[k][j]
                    r.datos[i][j] = s
            return r

    def mostrar(self):
        for fila in self.datos:
            print([round(x, 2) for x in fila])


if __name__ == "__main__":
    A = Matriz(2, 3)
    A.llenar([1, 2, 3, 4, 5, 6])
    print("A:")
    A.mostrar()

    print("A * 2:")
    (A * 2).mostrar()

    B = Matriz(3, 2)
    B.llenar([7, 8, 9, 10, 11, 12])
    print("B:")
    B.mostrar()

    print("A * B:")
    (A * B).mostrar()
