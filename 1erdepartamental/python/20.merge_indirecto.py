class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorMergeSortIndirecto:
    def __init__(self, datos):
        self.datos = datos
        self.indices = list(range(len(datos)))

    def ordenar(self):
        self.indices = self._merge_sort(self.indices)
        return self.indices

    def _merge_sort(self, idx):
        if len(idx) <= 1:
            return idx
        medio = len(idx) // 2
        izq = self._merge_sort(idx[:medio])
        der = self._merge_sort(idx[medio:])
        return self._merge(izq, der)

    def _merge(self, izq, der):
        resultado = []
        i = j = 0
        while i < len(izq) and j < len(der):
            if self.datos[izq[i]] <= self.datos[der[j]]:
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1
        resultado.extend(izq[i:])
        resultado.extend(der[j:])
        return resultado

    def acceder_ordenado(self):
        return [self.datos[i] for i in self.indices]


class OrdenadorMergeSortIndirectoPersonas:
    def __init__(self, personas):
        self.personas = personas
        self.indices = list(range(len(personas)))

    def ordenar_por_edad(self):
        self.indices = self._merge_sort(self.indices)
        return self.indices

    def _merge_sort(self, idx):
        if len(idx) <= 1:
            return idx
        medio = len(idx) // 2
        izq = self._merge_sort(idx[:medio])
        der = self._merge_sort(idx[medio:])
        return self._merge(izq, der)

    def _merge(self, izq, der):
        resultado = []
        i = j = 0
        while i < len(izq) and j < len(der):
            if self.personas[izq[i]].edad <= self.personas[der[j]].edad:
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1
        resultado.extend(izq[i:])
        resultado.extend(der[j:])
        return resultado

    def acceder_ordenado(self):
        return [self.personas[i] for i in self.indices]


if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorMergeSortIndirecto(datos)
    o.ordenar()
    print(f"Datos originales: {datos}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorMergeSortIndirectoPersonas(personas)
    op.ordenar_por_edad()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
