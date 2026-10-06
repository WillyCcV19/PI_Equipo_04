## Matriz morfológica
<img src="/Imagenes/func/matriz_morfologica_new.png" width="1500"/>

# Criterios y pesos
| Criterio       | Peso |
|----------------|------| 
| Disponibilidad | 0.15 |
| Costo          | 0.20 |
| Espacio        | 0.20 |
| Complejidad    | 0.30 |
| Mantenimiento  | 0.15 |

# Evaluación respecto al concepto A
| Criterio | Concepto A (Base) | Concepto B | Concepto C |
|--|---|---|------------|
| Disponibilidad | 4 | 3 | 2          |
| Costo          | 2 | 4 | 1          |
| Espacio        | 4 | 3 | 2          |
| Complejidad    | 3 | 3 | 2          |
| Mantenimiento  | 4 | 2 | 3          |

# Comparación
|Criterio| Base(A) | B s A | C s A |
|--|---------|-------|-------|
| Disponibilidad | 0       | -1    | -2    |
| Costo          | 0       | 2     | -1    |
| Espacio        | 0       | -1    | -2    |
| Complejidad    | 0       | 0     | -1    |
| Mantenimiento  | 0       | -2    | -1    |
|Suma| 0       | -2    | -7    |

# Puntaje final
| Criterio       | Peso | Concepto A (Base) |Concepto B|Concepto C|Peso*Concepto A|Peso*Concepto B|Peso*Concepto C|
|----------------|------|------|--|--|--|--|--|
| Disponibilidad | 0.15 | 0.60 | 0.45 | 0.30 | 0 | -0.15 | -0.30 |
| Costo          | 0.20 | 0.40 | 0.80 | 0.20 | 0 | 0.40  | -0.20 |
| Espacio        | 0.20 | 0.80 | 0.60 | 0.40 | 0 | -0.20 | -0.40 |
| Complejidad    | 0.30 | 0.90 | 0.90 | 0.60 | 0 | 0     | -0.30 |
| Mantenimiento  | 0.15 | 0.60 | 0.30 | 0.45 | 0 | -0.30 | -0.15 |
| Suma           | 1    | 3.30 | 3.05 | 1.95 | 0 | -0.25 | -1.35 |

Concepto solución ganador: A

