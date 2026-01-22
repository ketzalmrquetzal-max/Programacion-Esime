class Sumador:
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b

    def sumar(self):
        return self.a + self.b

    def establecer(self, a, b):
        self.a = a
        self.b = b


if __name__ == "__main__":
    s = Sumador(10, 25)
    print(f"{s.a} + {s.b} = {s.sumar()}")
    s.establecer(100, 200)
    print(f"{s.a} + {s.b} = {s.sumar()}")
