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

# Análisis de Simulaciones FEA del Prototipo Subacuático [Eber P.]

## 1. Malla Volumétrica (Meshing)

| Visualización de Malla |
| :---: |
| <img src="/Imagenes/Simulaciones/1.png" width="600"/> |

### Análisis de Configuración
* **Parámetros:** Malla estándar tetrahédrica con $425.3\text{k}$ celdas y $647.7\text{k}$ nodos aplicada sobre un material de polímero ABS.
* **Implicancia:** Una densidad de malla adecuada garantiza la convergencia de los resultados de Von Mises y desplazamientos en zonas críticas como empalmes y agujeros de sujeción.
* **Estado Ideal:** Incrementar la densidad de elementos en radios de redondeo y en la sección del eje para evitar concentraciones ficticias de esfuerzo por discontinuidad de malla.

---

## 2. Esfuerzos de Von Mises y Concentración de Cargas

| Distribución Global de Esfuerzos | Punto Crítico en el Eje |
| :---: | :---: |
| <img src="/Imagenes/Simulaciones/2.png" width="450"/> | <img src="/Imagenes/Simulaciones/3.png" width="450"/> |

### Análisis de Resultados
* **Resultados Obtenidos:** Se observa un esfuerzo máximo concentrado en la base/muesca del eje motriz que alcanza los **$2,412.81\text{ kPa}$** ($2.41\text{ MPa}$), mientras que el cuerpo cilíndrico se mantiene en rangos mínimos (< $100\text{ kPa}$).
* **Implicancia:** El material utilizado (ABS) posee un límite elástico típico de $30$ a $40\text{ MPa}$. Dado que $2.41\text{ MPa} \ll 35\text{ MPa}$, la pieza opera dentro del régimen elástico de seguridad (Factor de Seguridad $\approx 14$).
* **Estado Ideal:** Mantener los esfuerzos por debajo del $50\%$ del límite de fluencia del material para prevenir la fatiga mecánica por fluctuaciones de carga repetitivas en entorno acuático.

---

## 3. Condiciones de Borde (Boundary Conditions)

| Soporte Fijo (*Fixed Support*) | Fuerza Puntuada/Lateral (*Force 2*) |
| :---: | :---: |
| <img src="/Imagenes/Simulaciones/4.png" width="450"/> | <img src="/Imagenes/Simulaciones/5.png" width="450"/> |
| **Carga Volumétrica / Gravedad (*Volume Load 3*)** | **Presión Hidrostática Exterior (*Pressure 4*)** |
| <img src="/Imagenes/Simulaciones/6.png" width="450"/> | <img src="/Imagenes/Simulaciones/7.png" width="450"/> |

### Análisis de Configuración y Cargas
1. **Soporte Fijo (Imagen 4):** Restringe todos los grados de libertad ($d_x=d_y=d_z=0$) en la cara frontal del eje (`face 2681@Part 1`).
2. **Fuerza Aplicada (Imagen 5):** Aplicación de una fuerza de $2\text{ N}$ en el eje $Y$ sobre una cara lateral del chasis (`face 35@Part 1`).
3. **Carga Volumétrica (Imagen 6):** Carga por volumen en el eje $Z$ de $1.177 \times 10^4\text{ N/m}^3$ ($11.77\text{ kN/m}^3$), simulando el efecto de gravedad/flotabilidad sobre las 3 partes integrales.
4. **Presión Externa (Imagen 7):** Presión uniforme de $9.81\text{ kPa}$ simulada sobre las 6 caras externas de la carcasa, equivalente a una profundidad de sumersión de aproximadamente **$1\text{ metro}$** en agua.

### Implicancia Global y Escenario Ideal
* **Implicancia:** Las condiciones representan fielmente una prueba estática sumergida a $1\text{ m}$ de profundidad con cargas mecánicas moderadas en el exterior.
* **Estado Ideal:** Para simulaciones dinámicas subacuáticas, se recomienda acoplar un análisis CFD (Dinámica de Fluidos Computacional) para obtener la distribución real de presiones por arrastre hidrodinámico en lugar de una presión estática uniforme.

enlace: https://www.simscale.com/workbench/?pid=1339278016017631614&rru=89b846dc-c79a-4b02-9db4-f9ea4e69ad09&ci=81a17026-98c0-4aaf-a822-a63f282d2d1f&mt=SIMULATION_RESULT&ct=SOLUTION_FIELD 
