## Ejercicio 1: Lectura de un potenciómetro con ESP32
## Mejorar el código anterior haciendo uso de un promediado de los datos y convirtiendo los
valores del ADC a valores de voltaje.

En este ejercicio se conectó un potenciómetro al ESP32 utilizando el pin analógico GPIO 34. Primero se realizó la lectura directa de los valores del ADC y se visualizaron en el monitor serial.
Posteriormente, se mejoró la lectura tomando 10 muestras consecutivas y calculando su promedio, con el fin de obtener un valor más estable.
Finalmente, el valor promedio del ADC se convirtió a voltaje mediante la relación entre el rango del ADC y el voltaje de referencia de 3.3 V.

### Código utilizado
<img width="1600" height="944" alt="image" src="https://github.com/user-attachments/assets/dfb474d4-aaea-479c-9268-c1a3ff628181" />
### Circuito Implementado


## Ejercicio 2: Conexión del ESP32 a una red WiFi

En este ejercicio se creó una red WiFi utilizando el hotspot de un smartphone. Luego, el ESP32 se conectó a dicha red mediante el nombre y contraseña configurados.
Una vez establecida la conexión, se mostró en el monitor serial la dirección IP asignada al ESP32.

### Evidencias
<img width="1600" height="930" alt="image" src="https://github.com/user-attachments/assets/85a3aa75-629b-46dd-be8a-101ab75625be" />
### Resultado
Se logró conectar correctamente el ESP32 a la red WiFi creada desde el smartphone y visualizar en el monitor serial la dirección IP asignada.



Ejercicio3:
<img width="1600" height="958" alt="image" src="https://github.com/user-attachments/assets/b31444c2-0532-44db-a79c-1a000f861c1b" />
