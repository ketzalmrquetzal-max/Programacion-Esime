# Ordenador merge sort indirecto


class OrdenadorIndirectoMerge:
    def __init__(self, datos):
        self.__datos_originales = datos
        self.__indices = list(range(len(datos)))

    def ordenar(self):
        if len(self.__indices) > 1:
            self._merge_sort(0, len(self.__indices) - 1)

    def _merge_sort(self, izq, der):
        if izq >= der:
            return
        medio = (izq + der) // 2
        self._merge_sort(izq, medio)
        self._merge_sort(medio + 1, der)
        self._fusionar(izq, medio, der)

    def _fusionar(self, izq, medio, der):
        izq_arr = self.__indices[izq : medio + 1]
        der_arr = self.__indices[medio + 1 : der + 1]

        i = j = 0
        k = izq

        while i < len(izq_arr) and j < len(der_arr):
            if (
                self.__datos_originales[izq_arr[i]]
                <= self.__datos_originales[der_arr[j]]
            ):
                self.__indices[k] = izq_arr[i]
                i += 1
            else:
                self.__indices[k] = der_arr[j]
                j += 1
            k += 1

        while i < len(izq_arr):
            self.__indices[k] = izq_arr[i]
            i += 1
            k += 1

        while j < len(der_arr):
            self.__indices[k] = der_arr[j]
            j += 1
            k += 1

    @property
    def indices(self):
        return self.__indices.copy()

    def mostrar_ordenado(self):
        return [self.__datos_originales[i] for i in self.__indices]

    def mostrar_original(self):
        return self.__datos_originales.copy()
