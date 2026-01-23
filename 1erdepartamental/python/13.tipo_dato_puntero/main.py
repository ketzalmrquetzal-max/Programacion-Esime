"""
Programa: Tipo Dato Puntero
Demuestra puntero tipado con objetos personalizados
"""

from core.estadisticas import EstadisticasEstudiantes, Estudiante

if __name__ == "__main__":
    stats = EstadisticasEstudiantes()

    stats.agregar(Estudiante("Ana", 9.5))
    stats.agregar(Estudiante("Luis", 8.7))
    stats.agregar(Estudiante("Carlos", 9.8))

    print(f"Promedio general: {stats.promedio_general():.2f}")
    print(f"Mejor estudiante: {stats.mejor_estudiante()}")
