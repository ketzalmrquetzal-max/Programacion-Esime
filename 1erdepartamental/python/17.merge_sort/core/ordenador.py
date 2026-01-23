# Ordenador merge sort
#Clase ordenadorMarge
class OrdenadorMerge:
    #Constructor
    #Inicializa el contador de fusiones
    def __init__(self):
        self.__fusiones = 0
    #Función principal de ordamiento 
    def ordenar(self, datos):
        self.__fusiones = 0
        #Va a verificar que los datos que el arreglo tenga más de un elemento
        if len(datos) > 1:
            #Función principal de ordenamiento
            self._merge_sort(datos, 0, len(datos) - 1)
    # Función recursiva merge sort
    def _merge_sort(self, arr, izq, der):
        if izq >= der:# Caso base de la recursividad
            return
        medio = (izq + der) // 2  #Calcula el punto medio 
        self._merge_sort(arr, izq, medio) #Ordena la mitad izquierda
        self._merge_sort(arr, medio + 1, der)#Ordena la mitad derecha 
        self._fusionar(arr, izq, medio, der)#Fusiona ambas mitades 
    #Función que va a fucionar 2 sub arreglos ordenados 
    def _fusionar(self, arr, izq, medio, der):
        izq_arr = arr[izq:medio + 1]  # Subarreglo izquierdo
        der_arr = arr[medio + 1:der + 1]   # Subarreglo derecho
        
        i = j = 0
        k = izq
        #Comparación y fusión de elemntos
        while i < len(izq_arr) and j < len(der_arr):
            if izq_arr[i] <= der_arr[j]:
                arr[k] = izq_arr[i]
                i += 1
            else:
                arr[k] = der_arr[j]
                j += 1
            k += 1
        # Copia los elementos restantes del subarreglo izquierdo
        while i < len(izq_arr):
            arr[k] = izq_arr[i]
            i += 1
            k += 1
        # Copia los elementos restantes del subarreglo derecho
        while j < len(der_arr):
            arr[k] = der_arr[j]
            j += 1
            k += 1
        # Incrementa el contador de fusiones
        self.__fusiones += 1
    #Decorador getter fusiones 
    @property
    def fusiones(self):
        return self.__fusiones
