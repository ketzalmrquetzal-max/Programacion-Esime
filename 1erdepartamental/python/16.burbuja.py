class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorBurbuja:
    def __init__(self, datos):
        self.datos = datos.copy()

    def ordenar(self):
        n = len(self.datos)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if self.datos[j] > self.datos[j + 1]:
                    self.datos[j], self.datos[j + 1] = self.datos[j + 1], self.datos[j]
        return self.datos


class OrdenadorBurbujaPersonas:
    def __init__(self, personas):
        self.personas = personas.copy()

    def ordenar_por_edad(self):
        n = len(self.personas)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if self.personas[j].edad > self.personas[j + 1].edad:
                    self.personas[j], self.personas[j + 1] = (
                        self.personas[j + 1],
                        self.personas[j],
                    )
        return self.personas

    def ordenar_por_nombre(self):
        n = len(self.personas)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if self.personas[j].nombre > self.personas[j + 1].nombre:
                    self.personas[j], self.personas[j + 1] = (
                        self.personas[j + 1],
                        self.personas[j],
                    )
        return self.personas


if __name__ == "__main__":
    o = OrdenadorBurbuja([64, 34, 25, 12, 22, 11, 90])
    print(f"Enteros: {o.ordenar()}")

    o2 = OrdenadorBurbuja(["d", "a", "c", "b", "e"])
    print(f"Caracteres: {o2.ordenar()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorBurbujaPersonas(personas)
    print(f"Por edad: {[str(p) for p in op.ordenar_por_edad()]}")
