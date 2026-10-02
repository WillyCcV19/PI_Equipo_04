# Práctica IoT: ESP32, MQTT y Node-RED

## 1. Objetivo

Implementar una comunicación IoT utilizando un ESP32, el protocolo MQTT y Node-RED, con el propósito de enviar datos de temperatura y humedad, visualizarlos en un dashboard y permitir el envío de comandos hacia el dispositivo.

---

## 2. Arquitectura implementada

La comunicación realizada durante la práctica puede representarse de la siguiente manera:

```text
Sensor
   ↓
 ESP32
   ↓
  WiFi
   ↓
Broker MQTT
   ↓
 Node-RED
   ↓
Dashboard
```

El ESP32 obtiene los datos del sensor y los publica mediante MQTT. Node-RED se suscribe al topic correspondiente, procesa la información recibida y finalmente la muestra mediante diferentes elementos gráficos.

Node-RED permite conectar dispositivos, API y servicios mediante un editor visual basado en nodos. :chatgpt-content-reference{index="4"}

---

## 4. Configuración en Node-RED

Se creó un flujo en Node-RED encargado de recibir los datos publicados por el ESP32.
El topic utilizado para recibir la información fue:

```text
equipo04/sensor/datos
```

Los datos recibidos fueron separados para mostrar:

- Temperatura.
- Humedad.
- Identificación del dispositivo.

También se agregó un control tipo **Switch LED**, mediante el cual se pueden enviar comandos al ESP32.

### Flujo implementado

<img width="1600" height="727" alt="image" src="https://github.com/user-attachments/assets/a459d8d6-28ef-4f75-be66-1a8762ff960c" />

En la imagen se observa el nodo MQTT de entrada conectado a distintos nodos de procesamiento y posteriormente a los elementos del dashboard.

---

## 5. Configuración del broker MQTT

Para establecer la comunicación se configuró Node-RED con el broker MQTT utilizado durante la práctica.
Se establecieron las credenciales correspondientes para permitir la autenticación con el broker.

### Configuración de seguridad

<img width="1600" height="722" alt="image" src="https://github.com/user-attachments/assets/23696d7d-bee1-436e-b656-6832135de5ee" />

Posteriormente, en el nodo de entrada MQTT se configuró el topic:

```text
equipo04/sensor/datos
```

El mensaje fue configurado para recibirse como un **objeto JSON**, facilitando la extracción de los valores de temperatura, humedad y dispositivo.

### Configuración del topic

<img width="1600" height="726" alt="image" src="https://github.com/user-attachments/assets/a405973d-2fd8-45be-9f6c-15609ad2f75e" />

El broker actúa como intermediario entre el ESP32 y Node-RED, permitiendo que ambos puedan intercambiar información sin comunicarse directamente entre sí.

---

## 6. Visualización de los datos

Luego de establecer correctamente la comunicación, los datos recibidos fueron mostrados en el dashboard de Node-RED.
El dashboard permitió visualizar:

- Nombre del dispositivo.
- Temperatura en °C.
- Humedad relativa en %.
- Control del LED.
- Gráfica de variación de la temperatura.

### Dashboard

<img width="526" height="803" alt="image" src="https://github.com/user-attachments/assets/825ec56b-f97e-4c04-a3ee-4f64c433f694" />

Durante la prueba se obtuvo, por ejemplo:

```text
Dispositivo: ESP32_Equipo04
Temperatura: 24 °C
Humedad: 61 %
```

Esto permitió comprobar que los datos enviados desde el ESP32 estaban llegando correctamente al broker MQTT y posteriormente a Node-RED.

---

## 7. Gráfica en tiempo real

Además de los indicadores, se utilizó una gráfica para observar la variación de los datos a lo largo del tiempo.

<img width="523" height="972" alt="image" src="https://github.com/user-attachments/assets/baeebd8f-9622-4ef7-87ed-ba4c4de42de1" />

La gráfica permite observar los cambios producidos en las mediciones conforme el ESP32 continúa enviando información.
Node-RED y MQTT pueden trabajar conjuntamente para recibir información de dispositivos IoT y también enviar comandos, permitiendo comunicación en tiempo real. 

---

## 8. Resultado

Se logró establecer correctamente la comunicación entre el ESP32, el broker MQTT y Node-RED. Los valores de temperatura y humedad fueron recibidos mediante el topic `equipo04/sensor/datos` y posteriormente mostrados en un dashboard mediante indicadores y una gráfica.También se implementó un control para el LED, demostrando que la comunicación puede realizarse en ambos sentidos: desde el ESP32 hacia Node-RED para enviar datos y desde Node-RED hacia el ESP32 para enviar comandos.

---

## 9. Conclusión

La práctica permitió comprender de manera aplicada el funcionamiento de una arquitectura IoT utilizando MQTT. El ESP32 actuó como dispositivo encargado de obtener y publicar los datos, el broker MQTT permitió gestionar la comunicación y Node-RED fue utilizado para procesar y visualizar la información mediante un dashboard. De esta manera se implementó un sistema básico de monitoreo y control en tiempo real.
