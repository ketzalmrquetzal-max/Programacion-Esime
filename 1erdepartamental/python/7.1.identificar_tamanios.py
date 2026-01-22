# ============================================
# PROGRAMA: Identificar Tamaños de Datos
# DESCRIPCIÓN: Analiza memoria de diferentes tipos
# ============================================

import sys


class AnalizadorTamanios:
    """
    Analiza tamaños en bytes de tipos Python.

    sys.getsizeof() incluye overhead del objeto
    """

    def __init__(self):
        self.__tipos = {}

    @property
    def tipos(self):
        """Retorna copia del diccionario"""
        return self.__tipos.copy()

    def analizar_basicos(self):
        """Mide tipos primitivos de Python"""
        self.__tipos["int"] = sys.getsizeof(0)
        self.__tipos["float"] = sys.getsizeof(0.0)
        self.__tipos["bool"] = sys.getsizeof(True)
        self.__tipos["str"] = sys.getsizeof("")
        self.__tipos["list"] = sys.getsizeof([])
        self.__tipos["dict"] = sys.getsizeof({})

    def mostrar(self):
        for tipo, tam in self.__tipos.items():
            print(f"{tipo}: {tam} bytes")


class Persona:
    """Clase simple para medir objetos personalizados"""

    def __init__(self, nombre, edad):
        self.__nombre = nombre
        self.__edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad


class TamanioObjeto:
    """Wrapper para sys.getsizeof()"""

    def __init__(self, obj):
        self.__obj = obj

    def obtener_tamanio(self):
        """Solo mide el contenedor, no objetos referenciados"""
        return sys.getsizeof(self.__obj)


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    a = AnalizadorTamanios()
    a.analizar_basicos()
    a.mostrar()

    print()
    p = Persona("Juan", 25)
    t = TamanioObjeto(p)
    print(f"Objeto Persona: {t.obtener_tamanio()} bytes")
