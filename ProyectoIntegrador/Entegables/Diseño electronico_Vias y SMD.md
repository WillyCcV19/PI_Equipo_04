# Sistema de Monitoreo de Temperatura Subacuática

**ELABORADO POR:** Eber P.H.  
**PROYECTO:** PCB_Modulo_Sensores  

A continuación se presenta el desarrollo del circuito electrónico en EasyEDA para el **Módulo PCB — Sistema de Medición**, correspondiente a la versión de fabricación **THT** (Through-Hole Technology / tecnología de perforación e inserción).

---

| Vista | Tipo de Imagen | Descripción |
| :---: | :--- | :--- |
| <img src="/Imagenes/Simulaciones/21.png" width="500"/> | **Esquemático General THT** | Diagrama eléctrico dividido en Módulo de Temperatura (sensor DS18B20 y resistencia de 4.7kΩ), Módulo de Procesamiento (Arduino Nano) y Módulo de Visualización (conector I2C). |
| <img src="/Imagenes/Simulaciones/22.png" width="500"/> | **Diseño de PCB (Layout) THT** | Placa con perforaciones (*pads through-hole*) para los pines del Arduino Nano, sensor U1 en empaque TO-92, resistencia R1, conector I2C H2 y serigrafía institucional. |
| <img src="/Imagenes/Simulaciones/23.png" width="500"/> | **Render 3D THT** | Visualización tridimensional de la tarjeta ensamblada con el módulo Arduino Nano sobre conectores tipo header, resistencia axial de carbón y conectores de interfaz. |

**ELABORADO POR:** Verenisse Quispitongo
**PROYECTO:** MODULO_PCB  

---

## 1. Versión Soldadura por Agujeros
| Vista | Tipo de Imagen | Descripción |
| :---: | :--- | :--- |
| <img src="/Imagenes/Simulaciones/SCH_Schematic1_1-P1_2026-09-03.png" width="500"/> | **Esquemático General** | Diagrama eléctrico basado en el microcontrolador ESP32-WROOM-32 y un módulo óptico para la medición de turbidez, compuesto por un LED emisor y un fototransistor PT334-6C. La señal obtenida es enviada a una entrada del ESP32 para su procesamiento. |
| <img src="/Imagenes/Simulaciones/PCB_PCB1_2026-09-03.png" width="690"/> | **Diseño de PCB (Layout)** | Distribución de los componentes del sistema en la tarjeta PCB, incluyendo el ESP32-WROOM-32, resistencias, LED y fototransistor utilizados para el módulo de turbidez, junto con sus respectivas conexiones y plano de tierra GND. |
| <img src="/Imagenes/Simulaciones/3D_PCB1_2026-09-03.png" width="500"/> | **Render 3D** | Modelo tridimensional de la tarjeta electrónica diseñada en EasyEDA, mostrando la disposición física del ESP32 y los componentes correspondientes al módulo óptico de medición de turbidez. |

---
*Diseño y documentación realizados en **EasyEDA**.*
