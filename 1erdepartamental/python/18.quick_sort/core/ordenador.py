# Ordenador quick sort


class OrdenadorQuick:
    def __init__(self):
        self.__particiones = 0

    def ordenar(self, datos):
        self.__particiones = 0
        if len(datos) > 1:
            self._quick_sort(datos, 0, len(datos) - 1)

    def _quick_sort(self, arr, bajo, alto):
        if bajo >= alto:
            return
        pi = self._particionar(arr, bajo, alto)
        self._quick_sort(arr, bajo, pi - 1)
        self._quick_sort(arr, pi + 1, alto)

    def _particionar(self, arr, bajo, alto):
        pivote = arr[alto]
        i = bajo - 1

        for j in range(bajo, alto):
            if arr[j] < pivote:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[alto] = arr[alto], arr[i + 1]
        self.__particiones += 1
        return i + 1

    @property
    def particiones(self):
        return self.__particiones
