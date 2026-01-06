class Persona:
    def __init__(self, nombre, ap, am, genero, edad):
        self.nombre = nombre
        self.ap = ap
        self.am = am
        self.genero = genero
        self.edad = edad

    def nombre_completo(self):
        return f"{self.nombre} {self.ap} {self.am}"

    def __str__(self):
        return f"{self.nombre_completo()}, {self.edad} años"


class Auto:
    def __init__(self, marca, modelo, precio, anio):
        self.marca = marca
        self.modelo = modelo
        self.precio = precio
        self.anio = anio

    def __str__(self):
        return f"{self.marca} {self.modelo} ({self.anio}) - ${self.precio:,.2f}"


if __name__ == "__main__":
    p = Persona("Hugo", "Dominguez", "Lopez", "M", 19)
    print(p)

    a = Auto("Honda", "Civic", 350000, 2022)
    print(a)
