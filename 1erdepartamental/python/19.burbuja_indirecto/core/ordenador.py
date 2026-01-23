# Ordenador burbuja indirecto (preserva original)

#Clase OrdenadorIndirectoBurbuja
class OrdenadorIndirectoBurbuja:
    #Constructor 
    #Recibe el arreglo original de dato
    def __init__(self, datos):
        self.__datos_originales = datos
        self.__indices = list(range(len(datos)))
   # Método que implementa el ordenamiento burbuja indirecto
    def ordenar(self):
        n = len(self.__indices)
         # Ciclos del algoritmo burbuja
        for i in range(n - 1):
            for j in range(n - i - 1):
                # Compara los valores reales usando los índices
                if (
                    self.__datos_originales[self.__indices[j]]
                    > self.__datos_originales[self.__indices[j + 1]]
                ):
                    self.__indices[j], self.__indices[j + 1] = (
                        self.__indices[j + 1],
                        self.__indices[j],
                    )
     # Propiedad que devuelve una copia del arreglo de índices ordenados
    @property
    def indices(self):
        return self.__indices.copy()#  Se devuelve una copia para evitar modificaciones externas
    #Muestra los datos en orden usando los índices ordenados 
    def mostrar_ordenado(self):
        return [self.__datos_originales[i] for i in self.__indices] # Reconstruye el arreglo ordenado sin alterar el original
     # Se devuelve una copia por seguridad
    def mostrar_original(self):
        return self.__datos_originales.copy()
