# Ordenador quick sort indirecto

#classs ordenadorIndirecto 
class OrdenadorIndirectoQuick:
    # Constructor
    # Recibe el arreglo original y crea un arreglo de índices
    def __init__(self, datos):
        self.__datos_originales = datos
        self.__indices = list(range(len(datos)))
    # Método público para iniciar el ordenamiento
    def ordenar(self):
        if len(self.__indices) > 1: # Solo se ordena si hay más de un elemento
            self._quick_sort(0, len(self.__indices) - 1) # Llama al algoritmo Quick Sort sobre los índices
    # Implementación recursiva de Quick Sort
    def _quick_sort(self, bajo, alto):
        if bajo >= alto:
            return
         # Obtiene la posición final del pivote
        pi = self._particionar(bajo, alto)
        self._quick_sort(bajo, pi - 1)
        self._quick_sort(pi + 1, alto) 
     # Método que coloca el pivote en su posición correcta
    def _particionar(self, bajo, alto):
        pivote = self.__datos_originales[self.__indices[alto]] # Se elige como pivote el último elemento (según los índices)
        i = bajo - 1

        # Recorre el arreglo de índices
        for j in range(bajo, alto):
            if self.__datos_originales[self.__indices[j]] < pivote: # Compara valores reales usando los índices

                i += 1
                self.__indices[i], self.__indices[j] = ( # Intercambia los índices
                    self.__indices[j],
                    self.__indices[i],
                )
        # Coloca el pivote en su posición final 
        self.__indices[i + 1], self.__indices[alto] = (
            self.__indices[alto],
            self.__indices[i + 1],
        )
        return i + 1
    #Propiedades para obtner una copia de los idices ordenados
    @property
    def indices(self):
        return self.__indices.copy()
    #Devuelve el arreglo ordenado usado los idices
    def mostrar_ordenado(self):
        return [self.__datos_originales[i] for i in self.__indices]
    #Devuelve el arreglo original sin modificar
    def mostrar_original(self):
        return self.__datos_originales.copy()
