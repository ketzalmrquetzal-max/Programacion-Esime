class Saludo:
    def __init__(self, mensaje="Hola Mundo"):
        self.mensaje = mensaje

    def mostrar(self):
        print(self.mensaje)

    def saludar_persona(self, nombre):
        return f"Hola {nombre}"


if __name__ == "__main__":
    s = Saludo()
    s.mostrar()
    print(s.saludar_persona("Hugo"))
