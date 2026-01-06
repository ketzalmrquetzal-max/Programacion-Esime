import sys


class AnalizadorTamanios:
    def __init__(self):
        self.tipos = {}

    def analizar_basicos(self):
        self.tipos["int"] = sys.getsizeof(0)
        self.tipos["float"] = sys.getsizeof(0.0)
        self.tipos["bool"] = sys.getsizeof(True)
        self.tipos["str"] = sys.getsizeof("")
        self.tipos["list"] = sys.getsizeof([])
        self.tipos["dict"] = sys.getsizeof({})

    def mostrar(self):
        for tipo, tam in self.tipos.items():
            print(f"{tipo}: {tam} bytes")


class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad


class TamanioObjeto:
    def __init__(self, obj):
        self.obj = obj

    def obtener_tamanio(self):
        return sys.getsizeof(self.obj)


if __name__ == "__main__":
    a = AnalizadorTamanios()
    a.analizar_basicos()
    a.mostrar()

    p = Persona("Juan", 25)
    t = TamanioObjeto(p)
    print(f"Objeto Persona: {t.obtener_tamanio()} bytes")
