# Ordenador quick sort
class OrdenadorQuick:
    def __init__(self):
        self.__particiones = 0 #Valor por defecto
    
    # Método principal para iniciar el ordenamiento
    def ordenar(self, datos): 
        self.__particiones = 0
        if len(datos) > 1: 
            self._quick_sort(datos, 0, len(datos) - 1)
    
    # Función recursiva que implementa el algoritmo quick sort
    def _quick_sort(self, arr, bajo, alto):
        if bajo >= alto:
            return
        pi = self._particionar(arr, bajo, alto)
        # Ordena la parte izquierda
        self._quick_sort(arr, bajo, pi - 1)
        # Ordena la parte derecha
        self._quick_sort(arr, pi + 1, alto)
    
    # Particiona el arreglo y coloca el pivote en su posición correcta
    def _particionar(self, arr, bajo, alto):
        pivote = arr[alto]
        i = bajo - 1
        # Recorre y compara elementos con el pivote
        for j in range(bajo, alto):
            if arr[j] < pivote:
                i += 1
                # Intercambia elementos menores al pivote
                arr[i], arr[j] = arr[j], arr[i]
        # Coloca el pivote en su posición final
        arr[i + 1], arr[alto] = arr[alto], arr[i + 1]
        self.__particiones += 1
        return i + 1
    
    # Propiedad para obtener el número de particiones realizadas
    @property
    def particiones(self):
        return self.__particiones