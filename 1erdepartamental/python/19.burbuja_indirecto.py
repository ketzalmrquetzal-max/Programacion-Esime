class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorBurbujaIndirecto:
    def __init__(self, datos):
        self.datos = datos
        self.indices = list(range(len(datos)))

    def ordenar(self):
        n = len(self.indices)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if self.datos[self.indices[j]] > self.datos[self.indices[j + 1]]:
                    self.indices[j], self.indices[j + 1] = (
                        self.indices[j + 1],
                        self.indices[j],
                    )
        return self.indices

    def acceder_ordenado(self):
        return [self.datos[i] for i in self.indices]


class OrdenadorBurbujaIndirectoPersonas:
    def __init__(self, personas):
        self.personas = personas
        self.indices = list(range(len(personas)))

    def ordenar_por_edad(self):
        n = len(self.indices)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if (
                    self.personas[self.indices[j]].edad
                    > self.personas[self.indices[j + 1]].edad
                ):
                    self.indices[j], self.indices[j + 1] = (
                        self.indices[j + 1],
                        self.indices[j],
                    )
        return self.indices

    def acceder_ordenado(self):
        return [self.personas[i] for i in self.indices]


if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorBurbujaIndirecto(datos)
    o.ordenar()
    print(f"Datos originales: {datos}")
    print(f"Indices ordenados: {o.indices}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorBurbujaIndirectoPersonas(personas)
    op.ordenar_por_edad()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
