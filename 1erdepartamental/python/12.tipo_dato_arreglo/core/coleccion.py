# Colección tipada de productos

#Clase 1
class Producto:
    def __init__(self, nombre, precio):
        self.__nombre = nombre
        self.__precio = precio

    @property
    def nombre(self):
        return self.__nombre

    @property
    def precio(self):
        return self.__precio

    def __lt__(self, otro):
        return self.__precio < otro.__precio

    def __str__(self):
        return f"{self.__nombre}: ${self.__precio:.2f}"

#Clase 2
class ColeccionProductos:
    def __init__(self):
        self.__productos = [] #Lista Vacia con la que el objeto nace

    def agregar(self, producto):
        self.__productos.append(producto)#agregamos caracteres a esa lñista vacia 

    def cantidad(self):
        return len(self.__productos)#numero de elementos en la lista 

    def precio_total(self):
        return sum(p.precio for p in self.__productos)

    def precio_promedio(self):
        return self.precio_total() / len(self.__productos) if self.__productos else 0

    def mostrar(self):
        for i, p in enumerate(self.__productos):
            print(f"{i}: {p}")
