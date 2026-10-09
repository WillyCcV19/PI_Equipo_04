# Caracterización inicial del sensor de Oxígeno disuelto "Gravity Analog Dissolved Oxygen Sensor SEN0237-A"

## Objetivo: Obtener voltajes en condiciones de 100% y 0% de oxígeno disuelto en agua
- Caracterizar de manera preliminar la respuesta del sensor de oxígeno disuelto en aire, agua aireada y agua con sulfito de sodio
- Identificar lecturas de referencia para una posterior calibración

## Detalles
- Para lograr una concentración cercana (no verificada) de 0% oxígeno disuelto se disolvió 1 gramo de sulfito de sodio en 30mL de agua destilada (era la unidad mínima de mi balanza)
- Para lograr un aproximado (no verificado) de 100% se agitó el agua vigorosamente y se lo dejó airear numerosas veces
- El osciloscopio posee 8 cuadros de altura (con precisión variable por cada uno)
- Las mediciones son de RMS hechas durante 12 segundos (12 cuadros horizontales, 1 segundo cada uno)

# Primer intento: 
- 1.85v aire (500mv res)
  
| Tiempo | Voltaje (mv) | Precisión por cuadro (mv) |
|--|--|--|
|1:30|200|500|
|4:15|40|500|
|6:12|27|500|
|7:44|44|20|
|10:30|38|20|
|11:30|36|20|
|12:30|34|20|
|13:30|33|20|
|14:30|32|20|

# Segundo intento: agua con sulfito de sodio
- 1.79v al aire 

| Tiempo | Voltaje (mv) | Precisión por cuadro (mv) |
|--|--|--|
|1:30|122|500|
|2:00|100|50|
|4:00|46|50|
|4:30|44|50|
|5:30|37|20|
|6:30|33|20|
|9:30|25|20|
|11:00|25|20|
|15:30|22|20|

# Primer intento de agua agitada
1.78v al aire

| Tiempo | Voltaje (mv) | Precisión por cuadro (mv) |
|--|--|--|
|1:30|1200|500|
|2:30|1030|500|
|3:30|940|500|
|4:30|870|500|
|5:00|850|500|

# Misma agua, sin agitar más
- 1.76v al aire

| Tiempo | Voltaje (mv) | Precisión por cuadro (mv) |
|--|--|--|
|1:30|1030|500|
|2:00|970|500|
|2:30|930|500|
|3:00|910|500|
|4:00|860|500|
|5:00|840|500|

# Segundo intento: agua nuevamente agitada
- 1.78v al aire

| Tiempo | Voltaje (mv) | Precisión por cuadro (mv) |
|--|--|--|
|1:30|1200|500|
|2:00|1130|500|
|2:30|1040|500|
|3:00|1000|500|
|4:00|940|500|
|5:00|900|500|

# Tener en cuenta
- Todas las mediciones hechas a 24 grados celsius
- Las pruebas fueron hechas en casa
- Se midió con el circuito amplificador que viene de fábrica con el sensor
- Es un informe preliminar antes de calibrar en laboratorio


## Reacción del sensor de Oxígeno disuelto ante un cambio brusco de su entorno

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img3.jpeg" width="100%">
      <br>
      <em>Respuesta del sensor al sumergirlo en solución con sulfito de sodio</em>
    </td>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img2.jpeg" width="100%">
      <br>
      <em>Respuesta del sensor al removerlo de la solución</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img4.jpeg" width="100%">
      <br>
      <em>Primeros segundos al sumergirse en agua aireada</em>
    </td>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img5.jpeg" width="100%">
      <br>
      <em>Medición realizada 90 segundos después</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img6.jpeg" width="100%">
      <br>
      <em>Reacción del sensor al removerlo tras 5 minutos sumergido en agua aireada </em>
    </td>
    <td align="center">
      <img src="/Imagenes/ModuloElec/reporte_preliminar/img7.jpeg" width="100%">
      <br>
      <em>Materiales utilizados</em>
    </td>
  </tr>
</table>
