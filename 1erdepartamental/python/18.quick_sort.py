class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def __str__(self):
        return f"{self.nombre}({self.edad})"


class OrdenadorQuickSort:
    def __init__(self, datos):
        self.datos = datos.copy()

    def ordenar(self):
        self.datos = self._quick_sort(self.datos)
        return self.datos

    def _quick_sort(self, arr):
        if len(arr) <= 1:
            return arr
        pivote = arr[len(arr) // 2]
        menores = [x for x in arr if x < pivote]
        iguales = [x for x in arr if x == pivote]
        mayores = [x for x in arr if x > pivote]
        return self._quick_sort(menores) + iguales + self._quick_sort(mayores)


class OrdenadorQuickSortPersonas:
    def __init__(self, personas):
        self.personas = personas.copy()

    def ordenar_por_edad(self):
        self.personas = self._quick_sort(self.personas, "edad")
        return self.personas

    def _quick_sort(self, arr, criterio):
        if len(arr) <= 1:
            return arr
        pivote = getattr(arr[len(arr) // 2], criterio)
        menores = [x for x in arr if getattr(x, criterio) < pivote]
        iguales = [x for x in arr if getattr(x, criterio) == pivote]
        mayores = [x for x in arr if getattr(x, criterio) > pivote]
        return (
            self._quick_sort(menores, criterio)
            + iguales
            + self._quick_sort(mayores, criterio)
        )


if __name__ == "__main__":
    o = OrdenadorQuickSort([64, 34, 25, 12, 22, 11, 90])
    print(f"Enteros: {o.ordenar()}")

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorQuickSortPersonas(personas)
    print(f"Por edad: {[str(p) for p in op.ordenar_por_edad()]}")
