# Simulador de puntero para Python


class Puntero:
    def __init__(self, datos):
        self.__datos = datos
        self.__indice = 0

    def get_at(self):
        if self.__indice >= len(self.__datos):
            raise IndexError("Índice fuera de rango")
        return self.__datos[self.__indice]

    def avanzar(self):
        self.__indice += 1

    def reset(self):
        self.__indice = 0

    def en_rango(self):
        return self.__indice < len(self.__datos)
