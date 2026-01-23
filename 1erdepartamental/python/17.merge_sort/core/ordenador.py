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
    #Función pricipal de ordenamiento
    def _merge_sort(self, arr, izq, der):
        if izq >= der:
            return
        medio = (izq + der) // 2
        self._merge_sort(arr, izq, medio)
        self._merge_sort(arr, medio + 1, der)
        self._fusionar(arr, izq, medio, der)
    
    def _fusionar(self, arr, izq, medio, der):
        izq_arr = arr[izq:medio + 1]
        der_arr = arr[medio + 1:der + 1]
        
        i = j = 0
        k = izq
        
        while i < len(izq_arr) and j < len(der_arr):
            if izq_arr[i] <= der_arr[j]:
                arr[k] = izq_arr[i]
                i += 1
            else:
                arr[k] = der_arr[j]
                j += 1
            k += 1
        
        while i < len(izq_arr):
            arr[k] = izq_arr[i]
            i += 1
            k += 1
        
        while j < len(der_arr):
            arr[k] = der_arr[j]
            j += 1
            k += 1
        
        self.__fusiones += 1
    
    @property
    def fusiones(self):
        return self.__fusiones
