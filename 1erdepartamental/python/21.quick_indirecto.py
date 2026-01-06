class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorQuickSortIndirecto:
    def __init__(self, datos):
        self.datos = datos
        self.indices = list(range(len(datos)))

    def ordenar(self):
        self.indices = self._quick_sort(self.indices)
        return self.indices

    def _quick_sort(self, idx):
        if len(idx) <= 1:
            return idx
        pivote_val = self.datos[idx[len(idx) // 2]]
        menores = [i for i in idx if self.datos[i] < pivote_val]
        iguales = [i for i in idx if self.datos[i] == pivote_val]
        mayores = [i for i in idx if self.datos[i] > pivote_val]
        return self._quick_sort(menores) + iguales + self._quick_sort(mayores)

    def acceder_ordenado(self):
        return [self.datos[i] for i in self.indices]


class OrdenadorQuickSortIndirectoPersonas:
    def __init__(self, personas):
        self.personas = personas
        self.indices = list(range(len(personas)))

    def ordenar_por_edad(self):
        self.indices = self._quick_sort(self.indices)
        return self.indices

    def _quick_sort(self, idx):
        if len(idx) <= 1:
            return idx
        pivote_edad = self.personas[idx[len(idx) // 2]].edad
        menores = [i for i in idx if self.personas[i].edad < pivote_edad]
        iguales = [i for i in idx if self.personas[i].edad == pivote_edad]
        mayores = [i for i in idx if self.personas[i].edad > pivote_edad]
        return self._quick_sort(menores) + iguales + self._quick_sort(mayores)

    def acceder_ordenado(self):
        return [self.personas[i] for i in self.indices]


if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorQuickSortIndirecto(datos)
    o.ordenar()
    print(f"Datos originales: {datos}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorQuickSortIndirectoPersonas(personas)
    op.ordenar_por_edad()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
