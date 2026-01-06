class EstadisticasArreglo:
    def __init__(self, arreglo):
        self.datos = arreglo

    def suma(self):
        total = 0
        for n in self.datos:
            total += n
        return total

    def promedio(self):
        return self.suma() / len(self.datos)

    def maximo(self):
        m = self.datos[0]
        for n in self.datos:
            if n > m:
                m = n
        return m

    def minimo(self):
        m = self.datos[0]
        for n in self.datos:
            if n < m:
                m = n
        return m

    def agregar(self, valor):
        self.datos.append(valor)


if __name__ == "__main__":
    e = EstadisticasArreglo([10, 25, 5, 30, 15])
    print(f"Datos: {e.datos}")
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Maximo: {e.maximo()}")
    print(f"Minimo: {e.minimo()}")
