class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorMergeSort:
    def __init__(self, datos):
        self.datos = datos.copy()

    def ordenar(self):
        self.datos = self._merge_sort(self.datos)
        return self.datos

    def _merge_sort(self, arr):
        if len(arr) <= 1:
            return arr
        medio = len(arr) // 2
        izq = self._merge_sort(arr[:medio])
        der = self._merge_sort(arr[medio:])
        return self._merge(izq, der)

    def _merge(self, izq, der):
        resultado = []
        i = j = 0
        while i < len(izq) and j < len(der):
            if izq[i] <= der[j]:
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1
        resultado.extend(izq[i:])
        resultado.extend(der[j:])
        return resultado


class OrdenadorMergeSortPersonas:
    def __init__(self, personas):
        self.personas = personas.copy()

    def ordenar_por_edad(self):
        self.personas = self._merge_sort(self.personas, "edad")
        return self.personas

    def _merge_sort(self, arr, criterio):
        if len(arr) <= 1:
            return arr
        medio = len(arr) // 2
        izq = self._merge_sort(arr[:medio], criterio)
        der = self._merge_sort(arr[medio:], criterio)
        return self._merge(izq, der, criterio)

    def _merge(self, izq, der, criterio):
        resultado = []
        i = j = 0
        while i < len(izq) and j < len(der):
            if getattr(izq[i], criterio) <= getattr(der[j], criterio):
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1
        resultado.extend(izq[i:])
        resultado.extend(der[j:])
        return resultado


if __name__ == "__main__":
    o = OrdenadorMergeSort([64, 34, 25, 12, 22, 11, 90])
    print(f"Enteros: {o.ordenar()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorMergeSortPersonas(personas)
    print(f"Por edad: {[str(p) for p in op.ordenar_por_edad()]}")
