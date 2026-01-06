class Puntero:
    def __init__(self, arreglo):
        self._arr = arreglo
        self._pos = 0

    def get(self):
        return self._arr[self._pos]

    def get_at(self, i):
        return self._arr[self._pos + i]

    def set_at(self, i, valor):
        self._arr[self._pos + i] = valor

    def avanzar(self):
        self._pos += 1

    def reset(self):
        self._pos = 0


class EstadisticasPuntero:
    def __init__(self, arreglo):
        self.puntero = Puntero(arreglo)
        self.tamanio = len(arreglo)

    def suma(self):
        total = 0
        for i in range(self.tamanio):
            total += self.puntero.get_at(i)
        return total

    def promedio(self):
        return self.suma() / self.tamanio

    def maximo(self):
        m = self.puntero.get_at(0)
        for i in range(1, self.tamanio):
            if self.puntero.get_at(i) > m:
                m = self.puntero.get_at(i)
        return m

    def minimo(self):
        m = self.puntero.get_at(0)
        for i in range(1, self.tamanio):
            if self.puntero.get_at(i) < m:
                m = self.puntero.get_at(i)
        return m


if __name__ == "__main__":
    e = EstadisticasPuntero([10, 25, 5, 30, 15])
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Maximo: {e.maximo()}")
    print(f"Minimo: {e.minimo()}")
