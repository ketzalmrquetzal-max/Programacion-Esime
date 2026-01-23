# Ordenador burbuja indirecto (preserva original)


class OrdenadorIndirectoBurbuja:
    def __init__(self, datos):
        self.__datos_originales = datos
        self.__indices = list(range(len(datos)))

    def ordenar(self):
        n = len(self.__indices)
        for i in range(n - 1):
            for j in range(n - i - 1):
                if (
                    self.__datos_originales[self.__indices[j]]
                    > self.__datos_originales[self.__indices[j + 1]]
                ):
                    self.__indices[j], self.__indices[j + 1] = (
                        self.__indices[j + 1],
                        self.__indices[j],
                    )

    @property
    def indices(self):
        return self.__indices.copy()

    def mostrar_ordenado(self):
        return [self.__datos_originales[i] for i in self.__indices]

    def mostrar_original(self):
        return self.__datos_originales.copy()
