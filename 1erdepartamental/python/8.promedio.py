class Estadisticas:
    def __init__(self, n1, n2, n3, n4, n5):
        self.numeros = [n1, n2, n3, n4, n5]

    def suma(self):
        total = 0
        for n in self.numeros:
            total += n
        return total

    def promedio(self):
        return self.suma() / len(self.numeros)

    def maximo(self):
        m = self.numeros[0]
        for n in self.numeros:
            if n > m:
                m = n
        return m

    def minimo(self):
        m = self.numeros[0]
        for n in self.numeros:
            if n < m:
                m = n
        return m


if __name__ == "__main__":
    e = Estadisticas(10, 25, 5, 30, 15)
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Maximo: {e.maximo()}")
    print(f"Minimo: {e.minimo()}")
