# Sistema de Monitoreo de Temperatura Subacuática

**ELABORADO POR:** Eber  
**PROYECTO:** MODULO_PCB  

A continuación se presenta el desarrollo del circuito electrónico en EasyEDA para el sistema subacuático, dividido en sus dos versiones de fabricación: **SMD** (montaje superficial / soldadura por encima) y **THT** (perforaciones / soldadura por agujeros).

---

## 1. Versión SMD (Surface-Mount Device) - Soldadura Superficial

En esta versión los componentes se sueldan directamente sobre la superficie de la placa de circuito impreso.

| Vista | Tipo de Imagen | Descripción |
| :---: | :--- | :--- |
| <img src="/Imagenes/Simulaciones/11.png" width="500"/> | **Esquemático General SMD** | Diagrama eléctrico basado en el microcontrolador ATmega328P-AU, sensor de temperatura DS18B20Z en formato SMD y puerto de comunicación I2C. |
| <img src="/Imagenes/Simulaciones/12.png" width="500"/> | **Diseño de PCB (Layout) SMD** | Distribución de componentes de montaje superficial con encapsulados TQFP-32 y pasivos 0805, mostrando las líneas de interconexión. |
| <img src="/Imagenes/Simulaciones/13.png" width="500"/> | **Render 3D SMD** | Modelo tridimensional de la tarjeta electrónica ensamblada con componentes de perfil bajo para una placa compacta. |

---

## 2. Versión THT (Through-Hole Technology) - Soldadura por Agujeros

En esta versión los componentes atraviesan la placa mediante perforaciones para ser soldados por el reverso.

| Vista | Tipo de Imagen | Descripción |
| :---: | :--- | :--- |
| <img src="/Imagenes/Simulaciones/14.png" width="500"/> | **Esquemático General THT** | Diseño eléctrico simplificado utilizando un módulo Arduino Nano como unidad de procesamiento y componentes discretos con terminales de inserción. |
| <img src="/Imagenes/Simulaciones/15.png" width="500"/> | **Diseño de PCB (Layout) THT** | Placa con perforaciones (*pads through-hole*) para pines de Arduino Nano, resistencia de carbón y sensor en empaque TO-92. |
| <img src="/Imagenes/Simulaciones/16.png" width="500"/> | **Render 3D THT** | Visualización tridimensional de la tarjeta montada con el desarrollo modular sobre Arduino Nano y conectores tipo header hembra/macho. |

---

**ELABORADO POR:** Verenisse Quispitongo
**PROYECTO:** MODULO_PCB  

---

## 1. Versión Soldadura por Agujeros
| Vista | Tipo de Imagen | Descripción |
| :---: | :--- | :--- |
| <img src="/Imagenes/Simulaciones/SCH_Schematic1_1-P1_2026-09-03.png" width="500"/> | **Esquemático General** | Diagrama eléctrico basado en el microcontrolador ESP32-WROOM-32 y un módulo óptico para la medición de turbidez, compuesto por un LED emisor y un fototransistor PT334-6C. La señal obtenida es enviada a una entrada del ESP32 para su procesamiento. |
| <img src="/Imagenes/Simulaciones/PCB_PCB1_2026-09-03.png" width="690"/> | **Diseño de PCB (Layout)** | Distribución de los componentes del sistema en la tarjeta PCB, incluyendo el ESP32-WROOM-32, resistencias, LED y fototransistor utilizados para el módulo de turbidez, junto con sus respectivas conexiones y plano de tierra GND. |
| <img src="/Imagenes/Simulaciones/13.png" width="500"/> | **Render 3D** | Modelo tridimensional de la tarjeta electrónica diseñada en EasyEDA, mostrando la disposición física del ESP32 y los componentes correspondientes al módulo óptico de medición de turbidez. |

---
*Diseño y documentación realizados en **EasyEDA**.*
