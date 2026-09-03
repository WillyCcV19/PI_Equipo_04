# Sistema de Monitoreo de Temperatura Subacuática

ELABORADO POR EBER

A continuación se presentan los diagramas del diseño electrónico desarrollado en EasyEDA para el proyecto **MODULO_PCB** (Sistema de Monitoreo de Temperatura Subacuática).

---

| Vista / Esquema | Descripción del Componente | Enlace de EasyEDA / Repositorio |
| :---: | :--- | :---: |
| <img src="/Imagenes/11.png" width="400"/> | **Esquemático General del Circuito (Schematic)**<br><br>Diagrama esquemático completo dividido en tres bloques funcionales principales:<br>- **Módulo de Procesamiento:** Basado en el microcontrolador ATmega328P-AU con su circuito de oscilador externo (16 MHz) y capacitores de desacople.<br>- **Módulo de Temperatura (SMD):** Incorpora el sensor de temperatura digital DS18B20Z con su respectiva resistencia de *pull-up* (4.7kΩ) y conector H1.<br>- **Módulo de Visualización:** Conector H2 para comunicación I2C (SDA, SCL) con resistencias de *pull-up* (R3, R4). | [Ver en EasyEDA](LINK_AQUI) |
| <img src="/Imagenes/12.png" width="400"/> | **Diseño e Interconexión de la PCB (Layout / Ratsnest)**<br><br>Vista del diseño de la placa de circuito impreso mostrando la distribución de las huellas (*footprints*) en formato SMD (TQFP-32 para el ATmega328P, SOIC-8 para el DS18B20Z, componentes 0805 para resistencias/capacitores) y las líneas de conexión (*ratsnest*) previa al ruteo final de pistas. | [Ver en EasyEDA](LINK_AQUI) |
| <img src="/Imagenes/13.png" width="400"/> | **Modelo 3D de la Placa Ensamblada**<br><br>Renderizado tridimensional de la PCB terminada con todos los componentes montados sobre la superficie:<br>- Microcontrolador ATmega328P (U2)<br>- Sensor DS18B20Z (U1)<br>- Oscilador de cristal (X1)<br>- Conectores hembra de interfaz (H1 y H2)<br>- Componentes pasivos (R1-R4, C1-C3) | [Ver en EasyEDA](LINK_AQUI) |

---

*Nota: Este proyecto fue diseñado y realizado en **EasyEDA**.*
