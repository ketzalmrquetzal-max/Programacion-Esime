# Ordenador quick sort indirecto


class OrdenadorIndirectoQuick:
    def __init__(self, datos):
        self.__datos_originales = datos
        self.__indices = list(range(len(datos)))

    def ordenar(self):
        if len(self.__indices) > 1:
            self._quick_sort(0, len(self.__indices) - 1)

    def _quick_sort(self, bajo, alto):
        if bajo >= alto:
            return
        pi = self._particionar(bajo, alto)
        self._quick_sort(bajo, pi - 1)
        self._quick_sort(pi + 1, alto)

    def _particionar(self, bajo, alto):
        pivote = self.__datos_originales[self.__indices[alto]]
        i = bajo - 1

        for j in range(bajo, alto):
            if self.__datos_originales[self.__indices[j]] < pivote:
                i += 1
                self.__indices[i], self.__indices[j] = (
                    self.__indices[j],
                    self.__indices[i],
                )

        self.__indices[i + 1], self.__indices[alto] = (
            self.__indices[alto],
            self.__indices[i + 1],
        )
        return i + 1

    @property
    def indices(self):
        return self.__indices.copy()

    def mostrar_ordenado(self):
        return [self.__datos_originales[i] for i in self.__indices]

    def mostrar_original(self):
        return self.__datos_originales.copy()
