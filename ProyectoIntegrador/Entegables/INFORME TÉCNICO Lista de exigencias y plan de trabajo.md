# **1\. Lista de Exigencias** 

**Tabla 1: Lista de Exigencias**

| LISTA DE EXIGENCIAS |  |  | Páginas: 7 |
| ----- | :---: | ----- | ----- |
|  |  |  | **Edición: Rev. 2** |
| **PROYECTO:** |  | **FISHMON 360 — Diseño de dispositivo portátil para el monitoreo de la calidad del agua en sistemas de cultivo de trucha.**  | **Fecha: 20/08/2026** |
|  |  |  | **Revisado: 02/10/26** |
| **CLIENTE:**  |  | **UNIVERSIDAD PERUANA CAYETANO HEREDIA** | **Elaborado: J.K,W.C,V.Q.,E.P,R.C.** |
| Fecha (cambios) | Deseo o Exigencia | **Descripción** | **Responsable** |
| 25/09/26 | E | **Función Principal:** Monitorear la calidad del agua en sistemas de cultivo de trucha mediante una boya sumergible  y detectar condiciones potencialmente desfavorables para el cultivo mediante la medición de los parámetros: pH (0-14 ±0.1), turbidez (0-1000 NTU), conductividad (0-2000 µS/cm), temperatura (0-40 °C) y oxígeno disuelto (0-30 mg/L ±0.1 mg/L).  Los datos se transmitirán de forma continua a la plataforma IoT.  | **J.K,W.C,V.Q.,E.P,R.C.** |
| 13/11/26 | E | **Geometría:** El dispositivo, junto con sus sensores y demás implementos necesarios para su operación, deberá poder ser almacenado dentro de una envolvente máximo de 40 x 9.2 x 13.7 cm, establecida como límite superior de portabilidad tomando como referencias las dimensiones del transceptor Motorola SCR-536. | **J.K. V.Q.** |
| 13/11/26 | E | **Cinemática:** El diseño y la disposición de los sensores deben garantizar una correcta inmersión y contacto con el agua sin generar salpicaduras ni comprometer la seguridad del operador. El diseño garantiza estabilidad hidrodinámica. La muestra de agua debe permanecer en reposo o con un caudal mínimo para asegurar lecturas precisas y representativas. | **V.Q.** |
| 13/11/26 | D | **Fuerzas**: Durante la manipulación y uso en campo se deberá garantizar que la presión ejercida por el agua, el movimiento de la muestra y los impactos accidentales no comprometan la integridad estructural del dispositivo ni la precisión de las mediciones. Asimismo, el equipo deberá resistir caídas desde una altura de hasta 1 m sin afectar el funcionamiento de los sensores ni la estabilidad del sistema. |  **W.C.** |
| 16/10/26 | E | **Energía**: Debe ser capaz de almacenar energía para su uso sin estar conectado a la línea eléctrica. También, tener una protección para dicha solución de almacenamiento y contar con una opción de alimentación directa para fuentes alternativas. | **J.K** |
| 30/10/26 | E | **Materia:**  ***Materia de ingreso:*** Agua proveniente de sistemas de cultivo de trucha, como estanques, canales de abastecimiento o sistemas de recirculación acuícola. . El dispositivo debe soportar salpicaduras y exposición directa al agua sin comprometer la integridad de los sensores ni de los componentes electrónicos internos (IP65)[(*Ingress Protection (IP) Ratings*, s. f.)](https://www.zotero.org/google-docs/?ZjJo6Z). \+ ***Materia de salida:*** Datos procesados de pH, turbidez, conductividad, temperatura y oxígeno disuelto, clasificados en rangos y categorías según rangos de referencia aplicables al cultivo de trucha , tomando como referencia criterios técnicos establecidos para su cultivo (Ministerio de la Producción \[PRODUCE\], s. f.).  listos para visualización en pantalla y envío a la plataforma IoT. | **E.P** |
| 16/10/26 | E | **Señales (Información)**: Deberá contar con las siguientes señales de entrada y salida. Señales de entrada: Señal de encendido y apagado: Sirve para energizar y detener el funcionamiento a voluntad del usuario. Señal de inicio de medición: El usuario determina cuando se inicia la medición y almacenamiento de valores. Señal de información de sensores: Recibe las señales de los sensores para su posterior procesamiento. Señales de salida: Señal de conclusión de medición: Indica al usuario acerca de la conclusión de las mediciones, indicando que está libre para ser usado nuevamente. Señal de información de uso: En caso de recibir la señal de inicio de medición durante el procesamiento de parámetros indicará que el dispositivo se encuentra en uso. Señal para indicación de alertas: Permite notificar al usuario de eventos importantes. Señales de estado de los sensores: Permite visualizar el valor obtenido de cada sensor. | **V.Q.** |
| 30/10/26 | E | **Control:** El sistema de control debe permanecer estable en todas las etapas de funcionamiento, asegurando lecturas precisas y consistentes de pH, turbidez, conductividad, temperatura y oxígeno disuelto\*\*. El microcontrolador debe gestionar la secuencia de toma de datos, controlar el tiempo de muestreo y garantizar que la medición se realice sólo cuando la muestra se encuentre en reposo. Además, debe comparar los resultados con los rangos de referencia establecidos para el cultivo de trucha. Cuando alguno de los parámetros se encuentre fuera del rango establecido, deberá producir una alerta visual y/o sonora (Ministerio de la Producción \[PRODUCE\], s. f.)  e indicar el parámetro que presenta la condición desfavorable. | **R.C. J.K.** |
| 16/10/26 | E | **Electrónico (hardware):** Se usará el hardware necesario para la lectura de los sensores con el fin de obtener un diagnóstico acerca del estado del agua. Para ello se utilizará un controlador para el procesamiento de entradas y salidas | **J.K** |
| 30/10/26 | E | **Software:** Se utilizará un programa de código abierto para el control del sistema, y la interpretación de señales entrantes de los sensores. También, debe: Tener rutinas de calibración de sensores con uso de valores de referencia. Ser capaz de notificar al usuario con un diagnóstico basado en los valores obtenidos por los sensores. Almacenar en memoria los datos y ser capaz de transferir el contenido a otro dispositivo para mejor visualización. Tener una interfaz intuitiva y fácil de usar. | **W.C. J.K.** |
| 30/10/26 | D | **Comunicaciones:** El dispositivo debe Comunicarse con los sensores mediante conexión directa en sus correspondientes protocolos. Contar con una pantalla integrada para visualización inmediata en campo y toma de decisión rápida. Almacenar los datos recolectados en tarjeta de memoria extraíble para su posterior transferencia a otro dispositivo sin acceso a internet. Enviar los datos de manera inalámbrica a una plataforma web y almacenarlos en la nube en caso de tener acceso a internet. | **W.C.** |
| 13/11/26 | E/D | **Seguridad:** El dispositivo alerta cuando algún parámetro excede los límites ECA, previniendo el consumo de agua no apta y protegiendo al usuario y potenciales consumidores de la fuente de agua. Deseo: Cumplir con las condiciones establecidas en FCC 47 CFR § 15.19(a)(3): “(1) este dispositivo no debe causar interferencia dañina, y (2) este dispositivo debe aceptar cualquier interferencia recibida, incluyendo aquellos que puedan causar operación indeseada”[(*Federal Communications Commission | The United States of America*, 2025\)](https://www.zotero.org/google-docs/?xY0IFV). | **E.P.**  |
| 13/11/26 | D | **Ergonomía**: El dispositivo deberá ser un dispositivo fácil de manipular y sostener, sin bordes que puedan enganchar con la ropa u otro equipo. La masa total no deberá exceder de 1.75 kilogramos, tomando como referencia la masa del dispositivo SCR-536 (sin baterías) | **V.Q.** |
|    20/11/26                                                                                                                                           | D | **Fabricación:** El dispositivo deberá poder ser fabricado con materiales disponibles en el mercado nacional, priorizando componentes electrónicos y sensores requeridos que puedan ser adquiridos localmente, importados o fabricados. La carcasa y sus piezas estructurales deberán ser de materiales resistentes a la corrosión, con sellos para asegurar impermeabilidad. El diseño permitirá un ensamblaje sencillo en talleres locales, facilitando su reparación y transporte. Los materiales de fabricación deberán cumplir con estándares de seguridad y no liberar sustancias tóxicas al agua, de acuerdo con el **DECRETO SUPREMO Nº 007-98-SA**[(*Decreto Supremo N.° 007-98-SA*, s. f.)](https://www.zotero.org/google-docs/?G2i036), artículo 37 del Reglamento de DIGESA. Se garantizará un acabado de alta calidad en las superficies de contacto con el agua, siguiendo las recomendaciones de la **norma ISO 25178**[(*ISO \- Standards*, s. f.)](https://www.zotero.org/google-docs/?UBxzTT)**.** | **R.C.**                                       |
| 20/11/26 | D | **Control de calidad:** El diseño y la fabricación del dispositivo deben contemplar todas las exigencias planteadas en esta lista, de manera que cumpla con un funcionamiento confiable y alineado a las necesidades de monitoreo en campo. Esto incluye que satisfaga los requisitos de diseño en cuanto a dimensiones, tolerancias, selección de materiales resistentes a la corrosión y sellado adecuado para uso en exteriores. Asimismo, debe cumplir con buenas prácticas de calibración (pH, turbidez, conductividad, temperatura y oxígeno disuelto), verificación de datos mediante soluciones patrón y validación en laboratorio para asegurar precisión. Se considerarán aspectos de sanidad (evitar contaminación de muestras), seguridad del usuario, resistencia ambiental (lluvia, polvo) y sostenibilidad, garantizando que el producto sea apto para el mercado comunitario y escalable para uso institucional. | **E.P.** |
| 13/10/26 | E | **Montaje:** No habrá necesidad de fijar el producto por tratarse de un dispositivo de mano. | **W.C** |
| 27/10/26 | E | **Transporte:** El dispositivo contará con un peso de un kilogramo aproximadamente. y dimensiones adecuadas para ser transportado fácilmente hacia zonas rurales. Para reubicación en interiores, deberá ser lo suficientemente compacto para manipularlo manualmente sin necesidad de equipo de carga, asegurando que sus sensores y componentes internos no sufran daños durante el transporte. | **E.P.** |
| 27/11/26 | E | **Uso:** El dispositivo funcionará en sistemas de cultivo de trucha, incluyendo estanques, canales y ambientes acuícolas de agua dulce como **Santa Eulalia**. Deberá soportar las condiciones de temperatura y humedad propias del entorno de operación.  | **R.C. V.Q.** |
| 27/11/26 | E | **Mantenimiento: Componentes mecánicos y eléctricos:** El dispositivo debe permitir acceso fácil para inspección y reemplazo de cables, conectores y estructura sin herramientas especiales. **Componentes electrónicos:** Los sensores, pantalla y batería deben poder reemplazarse fácilmente en caso de falla, siguiendo un diseño modular. **Calibración y software:** Debe permitir la calibración periódica de sensores y actualización del sistema a través de la interfaz o conexión directa.  | **R.C.** |
|  | E | **Costos:** Estimamos un costo por horario de diseño de S/. 50 distribuidas entre los integrantes del grupo por las 150 horas de trabajo, obteniendo S/. 7500 en costos de diseño. Los costos de materiales se estima que no pasará de los S/. 2500 para tener un equipo funcional y costos de venta accesible. | **E.P.** |
| 13/10/26 | E | **Plazos:** El proyecto empezó el jueves 20 de agosto y se espera su finalización el jueves 4 de diciembre con un total de 150 horas de trabajo.  | **J.K** |

[(Batina & Šiljeg, 2025; Bresnahan et al., 2020; Custodio et al., 2021; «Data on the spatial and temporal variability of physical-chemical water quality indicators of the Cunas River, Peru», 2021; *Decreto Supremo N.° 004-2017-MINAM*, s. f.; Misman et al., 2023; Omer, 2019; Rangecroft et al., 2023\)](https://www.zotero.org/google-docs/?JtbUCQ)

[(Li, 2022; Zhou et al., 2012; Zhu, 2014\)](https://www.zotero.org/google-docs/?CIytTr)

**Normativas**

*Comisión Electrotécnica Internacional (IEC). Grados de protección IP. Recuperado de: https://www.iec.ch/ip-ratings*  
*Federal Communications Commission (FCC). Estándar FCC Part-15. Recuperado de: https://www.ecfr.gov/current/title-47/part-15*  
*Ministerio de Salud (MINSA). Decreto Supremo Nº 007-98-SA. Reglamento de DIGESA. Recuperado de: https://www.gob.pe/institucion/minsa/normas-legales/256394-007-98-sa*  
*Organización Internacional de Normalización (ISO). Norma ISO 25178\. Especificación de acabado de superficies. Recuperado de: https://www.iso.org/standard/67237.html*  
*Ministerio de la Producción (PRODUCE) / FONDEPES. Manual para una acuicultura sostenible: Cultivo de Trucha. Lima, Perú. Recuperado de: https://www.gob.pe/institucion/fondepes/informes-publicaciones/2448662-manual-de-cultivo-de-trucha*  
[*Decreto Supremo N.° 004-2017-MINAM*. (s. f.). Recuperado 21 de septiembre de 2025, de https://www.gob.pe/institucion/minam/normas-legales/3671-004-2017-minam](https://www.zotero.org/google-docs/?efYqpS)   
[*Decreto Supremo N.° 007-98-SA*. (s. f.). Recuperado 2 de octubre de 2025, de https://www.gob.pe/institucion/minsa/normas-legales/256394-007-98-sa?](https://www.zotero.org/google-docs/?efYqpS)  
[*ISO \- Standards*. (s. f.). ISO. Recuperado 2 de octubre de 2025, de https://www.iso.org/standards.html](https://www.zotero.org/google-docs/?efYqpS)   
[*Federal Communications Commission | The United States of America*. (2025, septiembre 8). https://www.fcc.gov/](https://www.zotero.org/google-docs/?efYqpS)   
[*Ingress Protection (IP) ratings*. (s. f.). Recuperado 2 de octubre de 2025, de https://www.iec.ch/ip-ratings](https://www.zotero.org/google-docs/?efYqpS)   
*Ministerio de la Producción (PRODUCE) / FONDEPES. Manual para una acuicultura sostenible: Cultivo de Trucha. Lima, Perú.         https://www.gob.pe/institucion/fondepes/informes-publicaciones/2448662-manual-de-cultivo-de-trucha* 

**Justificación del proyecto**

*Comisión Electrotécnica Internacional (IEC). Grados de protección IP. Recuperado de: https://www.iec.ch/ip-ratings*  
*Federal Communications Commission (FCC). Estándar FCC Part-15. Recuperado de: https://www.ecfr.gov/current/title-47/part-15*  
*Ministerio de Salud (MINSA). Decreto Supremo Nº 007-98-SA. Reglamento de DIGESA. Recuperado de: https://www.gob.pe/institucion/minsa/normas-legales/256394-007-98-sa*  
*Organización Internacional de Normalización (ISO). Norma ISO 25178\. Especificación de acabado de superficies. Recuperado de: https://www.iso.org/standard/67237.html*  
*Ministerio de la Producción (PRODUCE) / FONDEPES. Manual para una acuicultura sostenible: Cultivo de Trucha. Lima, Perú. Recuperado de: [https://www.gob.pe/institucion/fondepes/informes-publicaciones/2448662-manual-de-cultivo-de-trucha](https://www.gob.pe/institucion/fondepes/informes-publicaciones/2448662-manual-de-cultivo-de-trucha)*  
*Effect of a low water concentration in chloride, sodium and potassium on oocyte maturation, oocyte hydration, ovulation and egg quality in rainbow trout. Recuperado de:*  
	*[https://www.sciencedirect.com/science/article/abs/pii/S0044848621010371](https://www.sciencedirect.com/science/article/abs/pii/S0044848621010371)*  
*First description of Weissella ceti associated with mortalities in farmed rainbow trout (Oncorhynchus mykiss) in Peru. Recuperado de:*  
	*[https://www.sciencedirect.com/science/article/abs/pii/S0044848620304439](https://www.sciencedirect.com/science/article/abs/pii/S0044848620304439)*  
*Effects of temperature, dissolved oxygen, and their interaction on the growth performance and condition of rainbow trout(Oncorhynchus mykiss). Recuperado de:*  
	*[https://www.sciencedirect.com/science/article/abs/pii/S0306456521000954](https://www.sciencedirect.com/science/article/abs/pii/S0306456521000954)*  
*Effects of aeration and oxygenation on growth and survival of rainbow trout in a commercial serial pass, flow \- through raceway system. Recuperado de:*   
	*[https://www.sciencedirect.com/science/article/pii/S2352513418301431](https://www.sciencedirect.com/science/article/pii/S2352513418301431)*  
*Infection with dormant Mycobacterium salmoniphilum in rainbow trout Oncorhynchus mykiss at low water temperatures. Recuperado de: [https://www.sciencedirect.com/science/article/pii/S2352513426002346](https://www.sciencedirect.com/science/article/pii/S2352513426002346)*  
*Water pollution and the assessment of water quality parameters: a review. Desalination Water Treat. Recuperado de: [https://www.sciencedirect.com/science/article/pii/S1944398624010130](https://www.sciencedirect.com/science/article/pii/S1944398624010130)*  
*Water Quality Parameters. En: Water quality \- Science, Assessments and Policy. Recuperaod de:* [https://www.intechopen.com/chapters/69568](https://www.intechopen.com/chapters/69568)  
**Fuentes técnicas y referencias de diseño**  
U.S. War Department. TECHNICAL MANUAL of RADIO SETS SCR-536-A, SCR-536-B, AND SCR-536-C (1943). Recuperado de: [https://www.radiomanual.info/schemi/Surplus\_NATO/SCR-536A\_C\_serv\_user\_TM11-235\_1943.pdf](https://www.radiomanual.info/schemi/Surplus_NATO/SCR-536A_C_serv_user_TM11-235_1943.pdf)

**Plan de Trabajo:** 

| PLAN DE TRABAJO |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| :---: | :---- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | :---: |
| ACTIVIDAD |  | SEMANAS |  |  |  |  |  |  |  |  |  |  |  |  |  |  | HORAS DE TRABAJO |
|  |  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |  |
| 1 | Lista de exigencias |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 4 |
| 2 | Plan de trabajo |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 2 |
| 3 | Estado del arte y normativa para el cultivo de trucha  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 5 |
| 4 | Estructura de funciones |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 4 |
| 5 | Conceptos de solución |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 4 |
| 6 | Conceptos de solución integrados |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 2 |
| 7 | Proyecto preliminar óptimo |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 3 |
| 8 | Memoria de cálculos aproximados  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 5 |
| 9 | Sustanciación parcial |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 6 |
| 10 | Proyecto preliminar óptimo corregido  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 5 |
| 11 | Memoria de cálculos definitivos  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 6 |
| 12 | Planos de ensamblaje  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 4 |
| 13 | Lista de piezas  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 4 |
| 14 | Proyecto definitivo  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 3 |
| 15 | Fabricación y montaje  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 5 |
| 16 | Informe técnico final  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 2 |
| 17 | Sustentación y documentos finales  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 1 |
| TOTAL DE HORAS PROGRAMADAS |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 65 |

