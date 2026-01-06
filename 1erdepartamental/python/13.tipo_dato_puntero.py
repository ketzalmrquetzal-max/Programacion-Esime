class Persona:
    def __init__(self, nombre, ap, am, genero, edad):
        self.nombre = nombre
        self.ap = ap
        self.am = am
        self.genero = genero
        self.edad = edad

    def __str__(self):
        return f"{self.nombre} {self.ap}, {self.edad} años"


class Puntero:
    def __init__(self, arreglo):
        self._arr = arreglo
        self._pos = 0

    def get(self):
        return self._arr[self._pos]

    def get_at(self, i):
        return self._arr[self._pos + i]

    def avanzar(self):
        self._pos += 1

    def reset(self):
        self._pos = 0

    def tamanio(self):
        return len(self._arr)


class ListaPersonasPuntero:
    def __init__(self):
        self._datos = []
        self.puntero = None

    def agregar(self, persona):
        self._datos.append(persona)
        self.puntero = Puntero(self._datos)

    def obtener(self, i):
        return self.puntero.get_at(i)

    def mostrar(self):
        for i in range(self.puntero.tamanio()):
            print(f"*p+{i}: {self.puntero.get_at(i)}")


if __name__ == "__main__":
    lp = ListaPersonasPuntero()
    lp.agregar(Persona("Juan", "Perez", "Garcia", "M", 25))
    lp.agregar(Persona("Maria", "Lopez", "Sanchez", "F", 30))
    lp.agregar(Persona("Pedro", "Ramirez", "Torres", "M", 22))
    lp.mostrar()
