class Persona:
    def __init__(self, nombre, ap, am, genero, edad):
        self.nombre = nombre
        self.ap = ap
        self.am = am
        self.genero = genero
        self.edad = edad

    def __str__(self):
        return f"{self.nombre} {self.ap}, {self.edad} años"


class Coche:
    def __init__(self, marca, modelo, precio, anio):
        self.marca = marca
        self.modelo = modelo
        self.precio = precio
        self.anio = anio

    def __str__(self):
        return f"{self.marca} {self.modelo} ({self.anio})"


class ListaPersonas:
    def __init__(self):
        self.personas = []

    def agregar(self, persona):
        self.personas.append(persona)

    def mostrar(self):
        for i, p in enumerate(self.personas):
            print(f"[{i}] {p}")


class ListaCoches:
    def __init__(self):
        self.coches = []

    def agregar(self, coche):
        self.coches.append(coche)

    def mostrar(self):
        for i, c in enumerate(self.coches):
            print(f"[{i}] {c}")


if __name__ == "__main__":
    lp = ListaPersonas()
    lp.agregar(Persona("Juan", "Perez", "Garcia", "M", 25))
    lp.agregar(Persona("Maria", "Lopez", "Sanchez", "F", 30))
    lp.mostrar()

    lc = ListaCoches()
    lc.agregar(Coche("Honda", "Civic", 350000, 2022))
    lc.agregar(Coche("Toyota", "Corolla", 320000, 2021))
    lc.mostrar()
