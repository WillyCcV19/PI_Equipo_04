# Modelo de ONSHAPE para las tres primeras tablas
- Enlace: https://cad.onshape.com/documents/f734143c3763251624e8f45f/w/73cf6cb80b72b76e410a83a7/e/c8a476fd1b14d66486f749a2

# Intento de simulación de torsión en el eje del motor [John K.]
| Desplazamiento | Fuerza aplicada |
| - | - |
|<img src="/Imagenes/Simulaciones/sim1.png" width="500"/>|<img src="/Imagenes/Simulaciones/sim2.png" width="500"/>|
- Enlace: https://www.simscale.com/workbench/?pid=2451549434362735231&mi=spec:2c72ec2e-be86-4e93-a868-d52075bf7e47%2Cservice:SIMULATION%2Cstrategy:1

# Intento de simular estrés ente dientes de engranajes en el eje Z [Ruben C.]
| Desplazamiento | Fuerza aplicada |
| - | - |
|<img src="/Imagenes/Simulaciones/engranaje1.png" width="500"/>|<img src="/Imagenes/Simulaciones/engranaje2.png" width="500"/>|
- Enlace: https://www.simscale.com/workbench/?pid=1817896418183541406&rru=10d6d244-946f-4d87-aea3-fc026517d39b&ci=cf5c803a-1f93-4714-8b29-649fc48cddcf&mt=SIMULATION_RESULT&ct=SOLUTION_FIELD
- Justificación de fuerzas: Se aplicó una fuerza de 10 N en la dirección negativa del eje Z sobre la superficie del diente, con el objetivo de representar la carga mecánica que actúa sobre dicho elemento durante la interacción con el engranaje. Esta carga permite evaluar los esfuerzos y desplazamientos generados en el mecanismo bajo una condición de trabajo
  
<!-- # Intento de simular estrés ente dientes de engranajes en el eje X [Willy C.]
| Desplazamiento | Fuerza aplicada |
| - | - |
|<img src="/Imagenes/Simulaciones/Engranaje3.png" width="500"/>|<img src="/Imagenes/Simulaciones/Engranaje4.png" width="500"/>|E -->

# Intento de simulación térmica de una tapa expuesta al calor constante del ambiente [Willy C.]
| Temperatura | Calor aplicado |
| - | - |
|<img src="/Imagenes/Simulaciones/tapa1.png" width="500"/>|<img src="/Imagenes/Simulaciones/tapa2.png" width="500"/>|

- Enlace: https://www.simscale.com/workbench/?pid=4948183645136788433&rru=1fb664e7-1cb2-45bc-9f54-3f9133b5a362&ci=6be5e5a6-04b1-4e66-90bd-8e9614bb8f21&mt=SIMULATION_RESULT&ct=SOLUTION_FIELD


# Intento simulación del prototipo bajo el agua [Verenisse Q.]
| Desplazamiento | Fuerza aplicada |
| - | - |
|<img src="/Imagenes/Simulaciones/Screenshot 2026-08-27 164937.png" width="500"/>|<img src="/Imagenes/Simulaciones/Screenshot 2026-08-27 164458.png" width="500"/>|E

- Enlace: https://www.simscale.com/workbench/?pid=7910411673370197413&rru=d45b564a-62aa-4933-944a-83a83b4e83f7&ci=8ae51837-1f54-4004-bab8-7fe913920dd5&mt=SIMULATION_RESULT&ct=SOLUTION_FIELD 


# Análisis de Simulaciones FEA del Prototipo Subacuático (Prueba Boya) [Eber P. H.]

## 1. Malla Volumétrica e Inspección de Calidad (Meshing)

| Discretización del Modelo (Malla) | Inspección de Aspect Ratio (Calidad) |
| :---: | :---: |
| <img src="/Imagenes/Simulaciones/5.png" width="450"/> | <img src="/Imagenes/Simulaciones/6.png" width="450"/> |

### Análisis de Configuración y Resultados
* **Parámetros de Malla (Imagen 1):** Malla estándar tetraédrica (*Standard Algorithm*) con finura de nivel $5$, generando un total de **$52.4\text{k}$ celdas** y **$97\text{k}$ nodos** distribuidos en la geometría del ensamble (`Assembly 1`).
* **Calidad de Elementos (Imagen 2):** El filtro de *Aspect Ratio* revela que la gran mayoría de elementos se encuentran cerca de $1$ (ideal). Existen pequeñas concentraciones locales en bordes delgados de acople donde el *aspect ratio* alcanza valores máximos de hasta $42.64$.
* **Implicancia:** La densidad actual de malla es numéricamente estable y ligera para simulaciones estáticas rápidas. Sin embargo, las zonas con un *aspect ratio* elevado en la interfaz entre partes pueden distorsionar ligeramente los gradientes locales de esfuerzo o deformación.
* **Estado Ideal:** Aplicar refinamientos locales de malla (*Mesh Refinements*) con tamaño de elemento controlado en las aristas de contacto e interfaces cónicas para reducir el *aspect ratio* por debajo de $10$ en todo el dominio.

---

## 2. Definición del Modelo Global y Gravedad

| Configuración de Gravedad en el Modelo |
| :---: |
| <img src="/Imagenes/Simulaciones/1.png" width="600"/> |

### Análisis de Configuración
* **Gravedad:** Se configuró una aceleración gravitacional con magnitud nula en magnitud global ($0\text{ m/s}^2$) pero con vector de dirección de **$e_y = -9.81\text{ m/s}^2$** sobre el eje $Y$ (*Gravity direction*).
* **Interpretación:** La aceleración está correctamente orientada hacia la base cónica del prototipo ($Y$ negativo), representando el peso propio de la estructura en condiciones terrestres/acuáticas.
* **Implicancia Global:** Al asignar el vector $-9.81\text{ m/s}^2$ en el componente $e_y$, el software calcula la fuerza volumétrica ejercida por la masa total del prototipo bajo aceleración gravitacional estándar.
* **Escenario Ideal:** Asegurarse de que el parámetro *Gravity magnitude* concuerde con el vector activo o definir explícitamente el empuje hidrostático neto de flotabilidad si la boya estará totalmente sumergida en equilibrio dinámico.

---

## 3. Asignación de Material (PLA)

| Propiedades Mecánicas del Material |
| :---: |
| <img src="/Imagenes/Simulaciones/2.png" width="600"/> |

### Análisis de Configuración
* **Material:** Polímero **PLA** (Ácido Poliláctico) configurado como material elástico e isotrópico (*Linear Elastic / Isotropic*).
* **Parámetros:** Módulo de Young $E = 3.5 \times 10^9\text{ Pa}$ ($3.5\text{ GPa}$), Coeficiente de Poisson $\nu = 0.36$ y Densidad $\rho = 1250\text{ kg/m}^3$.
* **Interpretación:** El PLA ofrece un módulo elástico superior al ABS convencional ($\sim 2.0\text{ GPa}$), brindando mayor rigidez estructural contra la presión externa, aunque con menor tenacidad al impacto.
* **Implicancia Global:** El modelo considera propiedades teóricas de PLA sólido e isotrópico. En impresión 3D FDM real, la resistencia mecánica final dependerá del porcentaje de relleno (*infill*), la orientación de capas y el patrón de impresión.
* **Escenario Ideal:** Para validar piezas impresas en 3D bajo agua, se deben ajustar las propiedades a un comportamiento ortotrópico o reducir el módulo efectivo de Young para simular la degradación o la anisotropía propia del proceso de manufactura aditiva.

---

## 4. Condiciones de Borde y Justificación de Cargas

| Soporte Fijo (*Fixed Support 1*) | Presión Externa (*Pressure 2*) |
| :---: | :---: |
| <img src="/Imagenes/Simulaciones/3.png" width="450"/> | <img src="/Imagenes/Simulaciones/4.png" width="450"/> |

### Análisis de Configuración
1. **Soporte Fijo (Imagen 3):** Restringe todos los desplazamientos ($d_x=d_y=d_z=0$) en dos caras cónicas inferiores (`face 35@Part 1` y `face 146@Part 1`).
2. **Presión Aplicada (Imagen 4):** Carga de presión uniforme de **$5000\text{ Pa}$** ($5\text{ kPa}$) asignada a las mismas caras seleccionadas (`face 35@Part 1` y `face 146@Part 1`).

### Justificación de Fuerzas e Interpretación
* **Justificación de la Presión:** La presión de $5\text{ kPa}$ simula la carga hidrostática ejercida por la columna de agua a una profundidad de sumersión estática de aproximadamente **$0.51\text{ metros}$** ($P = \rho \cdot g \cdot h$).
* **Interpretación de Restricciones:** El soporte fijo en la base actúa como punto de anclaje rígido (móvil o restrictor de boya) impidiendo el movimiento global del cuerpo durante la resolución estática.
* **Implicancia Global:** La combinación de soporte fijo y presión simula la deformación local en el faldón cónico inferior bajo compresión de agua poco profunda.
* **Escenario Ideal:** Asignar la presión hidrostática en todas las caras exteriores expuestas al fluido (incluyendo el cuerpo cilíndrico superior) y utilizar resortes elásticos o restricciones flexibles en lugar de soportes fijos rígidos para simular la flotación libre del prototipo.

#### Link: https://www.simscale.com/workbench/?pid=2862143116457342959&rru=d122725c-00fd-4e09-98c6-4a44592150f8&sh=1&ci=5ed1f582-abfd-44d1-b3d3-334811d490f9&ct=MESH&mt=SIMULATION_RESULT
