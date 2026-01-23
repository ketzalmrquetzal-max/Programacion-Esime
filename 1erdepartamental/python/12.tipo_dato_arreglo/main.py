"""
Programa: Tipo Dato Arreglo
Demuestra colección tipada de objetos personalizados
"""

from core.coleccion import ColeccionProductos, Producto

if __name__ == "__main__":
    inventario = ColeccionProductos()

    inventario.agregar(Producto("Laptop", 15000))
    inventario.agregar(Producto("Mouse", 250))
    inventario.agregar(Producto("Teclado", 800))

    print("=== INVENTARIO ===")
    inventario.mostrar()
    print(f"\nTotal productos: {inventario.cantidad()}")
    print(f"Precio total: ${inventario.precio_total():.2f}")
    print(f"Precio promedio: ${inventario.precio_promedio():.2f}")
