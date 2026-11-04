        **RETOS PARA ESCALAR EL PROTOTIPO A UN ENTORNO OPERACIONAL**



Actualmente FishMon 365 se encuentra en TRL 4, correspondiente a la integración de componentes y pruebas en un entorno controlado. El avance hacia TRL 7 requiere un prototipo de mayor fidelidad y su demostración integrada en un centro real de crianza de trucha. La condición TRL declarada debe sustentarse con los informes y resultados de las pruebas efectivamente realizadas.

**1. Causas principales que pueden limitar el escalamiento**

Se priorizan las brechas que pueden comprometer la seguridad, confiabilidad, uso y futura comercialización del sistema. Los detalles técnicos secundarios se mantienen como actividades de validación, no como ejes independientes.

| **N.º** | **Causa principal**                                              | **Consecuencia para el proyecto**                                        | **Acción prioritaria**                                                           |
| ------- | ---------------------------------------------------------------- | ------------------------------------------------------------------------ | -------------------------------------------------------------------------------- |
| 1       | Descalibración y bioincrustación de sensores.                    | Lecturas erróneas, alertas falsas y mayor costo de mantenimiento.        | Definir limpieza, calibración y comparación con instrumentos de referencia.      |
| 2       | Fallas de impermeabilidad, flotabilidad o mecanismo de descenso. | Ingreso de agua, pérdida del módulo sumergible o profundidad incorrecta. | Ensayar estanqueidad, estabilidad, carga del cable y ciclos de subida/bajada.    |
| 3       | Autonomía y comunicación no demostradas en campo.                | Interrupción del monitoreo o pérdida de registros.                       | Medir consumo real, cobertura LoRa, pérdida de paquetes y recuperación de datos. |
| 4       | Fabricación sin especificaciones y controles uniformes.          | Diferencias de calidad entre unidades.                                   | Establecer BOM, planos, ensamblaje y pruebas de aceptación.                      |
| 5       | Manual y dashboard no validados con acuicultores.                | Configuración incorrecta, interpretación errónea o abandono del sistema. | Realizar pruebas de usabilidad y capacitación.                                   |
| 6       | Propiedad intelectual y titularidad sin definir.                 | Riesgo de divulgación y conflictos sobre explotación del desarrollo.     | Buscar antecedentes y acordar titularidad antes de divulgar detalles técnicos.   |
| 7       | Formalización y viabilidad comercial pendientes.                 | Dificultad para vender formalmente y sostener garantía y soporte.        | Definir empresa, RUC, costos, precio y servicio posventa.                        |



**2. Adaptación tecnológica y pruebas prioritarias**

La integración debe abarcar sensores, Arduino Nano, ESP32 con LoRa, batería, mecanismo de descenso y elevación, carcasa, módulo flotante, módulo sumergible y dashboard. La validación debe concentrarse en los siguientes puntos:

| **Subsistema**      | **Qué se debe comprobar**                                                                 | **Evidencia mínima**                                                            |
| ------------------- | ----------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| Sensores            | Calibración, tiempo de respuesta, estabilidad y efecto de bioincrustación.                | Registros antes/después de calibración y comparación con equipo de referencia.  |
| Carcasa y boya      | Estanqueidad, flotabilidad, estabilidad y resistencia a exposición ambiental.             | Protocolo de inmersión, inspección y prueba de estabilidad.                     |
| Mecanismo y cable   | Recorrido real, precisión de profundidad, carga, desgaste y recuperación ante atasco.     | Ensayos repetidos de subida/bajada y verificación independiente de profundidad. |
| Energía             | Autonomía con el ciclo real de medición y movimiento.                                     | Registro de consumo y duración de batería.                                      |
| LoRa y software     | Cobertura, paquetes perdidos, almacenamiento temporal, marcas de tiempo y sincronización. | Bitácora de comunicación y prueba de recuperación de datos.                     |
| Dashboard y alertas | Visualización correcta, actualización de datos y comportamiento ante valores anómalos.    | Pruebas funcionales y registro de errores.                                      |



La protección IPX8 no debe declararse como una certificación genérica de “sumersión continua”. El grado y las condiciones de ensayo deben definirse para el equipo concreto (profundidad, tiempo y configuración) y comprobarse mediante pruebas apropiadas. La estanqueidad del módulo sumergible, conectores y compartimentos debe evaluarse por separado.

**3. Normativa y reglamentos que deben considerarse**

3.1. NTP 320.004:2014, revisada en 2021

La NTP 320.004:2014 (revisada en 2021), titulada “Acuicultura. Buenas prácticas acuícolas en la producción de trucha arcoíris”, establece orientaciones para el manejo de la producción de trucha con el propósito de favorecer la inocuidad, la calidad, la competitividad, el cuidado ambiental y la seguridad de los trabajadores [1].

Para FishMon 365, la relación principal es el registro y seguimiento de variables de calidad del agua, oxígeno disuelto, temperatura, pH, turbidez y conductividad  a distintas profundidades. El historial y las alertas pueden apoyar al productor en la vigilancia de las condiciones del cultivo y en la toma de decisiones.

| **Qué significa para el productor**                                              | **Aporte de FishMon 365**                                                      | **Límite del sistema**                                                                                             |
| -------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------ |
| Debe aplicar buenas prácticas de manejo y controlar las condiciones de cultivo.  | Entrega mediciones e historial de variables del agua por profundidad y tiempo. | No reemplaza la gestión del cultivo, alimentación, control de biomasa, prevención sanitaria ni análisis oficiales. |
| Debe mantener registros y actuar ante condiciones que puedan afectar el cultivo. | Puede facilitar registros y alertas configuradas para apoyar la supervisión.   | Una alerta no identifica por sí sola la causa ni ejecuta una acción correctiva.                                    |



La NTP es, como regla general, una norma técnica voluntaria, salvo que una disposición obligatoria la incorpore y exija su aplicación [2]. Por tanto, sirve como referencia para diseñar y validar FishMon 365, pero el uso del dispositivo no certifica al productor ni demuestra por sí solo el cumplimiento de la norma. Para citar requisitos específicos se debe consultar el texto íntegro de INACAL y mencionar el numeral correspondiente.

3.2. SANIPES y requisitos sanitarios del centro acuícola

SANIPES es la autoridad sanitaria competente en el ámbito pesquero y acuícola. Los centros de cultivo deben revisar los trámites y requisitos sanitarios que les sean aplicables, incluida la habilitación sanitaria y la documentación y programas exigidos según el tipo de establecimiento [3].

La responsabilidad debe distinguirse: el productor responde por las obligaciones sanitarias y operativas de su centro; FishMon 365 es una herramienta de monitoreo y no concede habilitación sanitaria, no sustituye inspecciones ni certifica buenas prácticas. Antes de una prueba piloto se recomienda un acuerdo con el centro que defina ubicación, duración, responsabilidades, acceso, mantenimiento, datos y retiro del prototipo.

3.3. MTC: comunicación LoRa y homologación

Como FishMon 365 utiliza comunicación LoRa, se debe verificar que la banda, potencia, antena y configuración del equipo cumplan las condiciones técnicas establecidas por el Ministerio de Transportes y Comunicaciones (MTC). En Perú se contempla el rango 915–928 MHz para determinados dispositivos de baja potencia, sujeto a las condiciones regulatorias aplicables; no basta con que el módulo LoRa sea comercial para asumir que el producto integrado cumple.

Antes de comercializar, se debe consultar al MTC si el modelo final requiere homologación como equipo de telecomunicaciones. La evaluación debe considerar el módulo, la antena, la potencia, la banda y la configuración final del producto [4].

3.4. Calibración, seguridad eléctrica y residuos electrónicos

ISO/IEC 17025:2017 establece requisitos de competencia para laboratorios de ensayo y calibración. Puede utilizarse como referencia para seleccionar laboratorios y respaldar comparaciones o calibraciones; no significa que FishMon 365 deba certificarse bajo esa norma [5].

La batería y los módulos de carga deben contar con especificaciones y protecciones adecuadas. Se deben evaluar cortocircuito, sobrecorriente, polaridad, sobrecarga, temperatura y humedad. Además, la empresa debe revisar si le corresponden obligaciones como fabricante, importador o comercializador bajo el régimen peruano de residuos de aparatos eléctricos y electrónicos (RAEE), y definir el retorno o disposición de equipos y baterías [6].

**4. Propiedad intelectual, patentes y protección del desarrollo**

Antes de publicar planos, mecanismo interno, firmware y detalles que puedan revelar una solución novedosa, el equipo debe revisar antecedentes y definir la titularidad con la universidad, integrantes y posibles financiadores. La protección se tramita ante INDECOPI conforme al régimen de propiedad industrial [7].

| **Elemento del proyecto**                              | **Protección que podría evaluarse**        | **Condición o límite**                                                                                         |
| ------------------------------------------------------ | ------------------------------------------ | -------------------------------------------------------------------------------------------------------------- |
| Mecanismo novedoso de descenso, guiado o recuperación. | Modelo de utilidad o patente de invención. | Debe cumplir los requisitos legales de novedad y, según la modalidad, nivel inventivo y aplicación industrial. |
| Diseño exterior de la boya.                            | Diseño industrial.                         | Protege la apariencia, no el funcionamiento.                                                                   |
| Nombre y logotipo FishMon 365.                         | Registro de marca.                         | Debe verificarse que no exista una marca anterior confundible.                                                 |
| Código del dashboard y firmware.                       | Derecho de autor.                          | Debe conservarse evidencia de autoría y titularidad.                                                           |



La patente de invención tiene una vigencia de 20 años y el modelo de utilidad de 10 años desde la presentación, conforme a la normativa aplicable. La protección es territorial: una solicitud peruana no concede automáticamente derechos en otros países. Las principales limitaciones son antecedentes similares, falta de novedad y nivel inventivo, divulgación previa, costos y desacuerdos sobre titularidad [7].

Acciones inmediatas: (i) buscar antecedentes en INDECOPI, WIPO y Espacenet; (ii) identificar qué parte del prototipo aporta una ventaja técnica; (iii) documentar inventores y titularidad; y (iv) mantener confidencialidad hasta decidir si se presenta una solicitud.

**5. Formalización empresarial, RUC y comercialización**

El RUC es el registro tributario administrado por SUNAT. No se necesita para desarrollar el prototipo, pero sí debe considerarse antes de realizar ventas formales habituales. La empresa deberá cumplir las obligaciones tributarias y emitir comprobantes de pago según el régimen que corresponda [8].

| **Etapa**                           | **Acción necesaria**                                                                                          | **Resultado esperado**                                     |
| ----------------------------------- | ------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| Definir titularidad y socios.       | Acordar aportes, responsabilidades y quién será titular de FishMon 365.                                       | Evitar conflictos sobre el proyecto y su comercialización. |
| Constituir empresa, si corresponde. | Evaluar S.A.C., S.R.L. u otra forma con asesoría legal y contable.                                            | Persona jurídica inscrita.                                 |
| Formalizar ante SUNAT.              | Inscribir RUC, obtener Clave SOL y declarar actividad económica y régimen tributario.                         | RUC activo y obligaciones identificadas.                   |
| Preparar ventas.                    | Emitir comprobantes y elaborar ficha técnica, cotización y contrato.                                          | Venta formal y condiciones claras.                         |
| Proteger al cliente.                | Definir garantía, exclusiones, mantenimiento, atención de reclamos y tratamiento de datos cuando corresponda. | Relación comercial transparente.                           |



El RUC no equivale a una patente, certificación técnica ni autorización sanitaria. Tampoco garantiza que el producto esté listo para venderse. Antes de comercializar deben estar definidas las prestaciones demostradas, garantía, mantenimiento, repuestos y soporte, evitando prometer precisión, autonomía y resistencia que no se hayan ensayado.

**6. Manual de usuario, capacitación y facilidad de uso**

El manual y el dashboard deben ser comprensibles para productores que no necesariamente tienen formación en electrónica y programación. La facilidad de uso debe comprobarse con usuarios potenciales.

| **Brecha**                              | **Requisito concreto**                                                                                                      | **Validación**                                                           |
| --------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| Manual demasiado técnico.               | Guía breve, ilustrada y en español: instalación, encendido, configuración de profundidad, lectura, alertas y mantenimiento. | El productor completa tareas siguiendo la guía.                          |
| Dashboard confuso.                      | Mostrar variable, valor, unidad, profundidad, fecha/hora y estado de conexión.                                              | El usuario interpreta correctamente cada lectura.                        |
| Alertas poco claras.                    | Indicar qué condición requiere atención y qué debe verificar el usuario; no presentarla como diagnóstico.                   | El usuario distingue una alerta de una recomendación o diagnóstico.      |
| Errores de instalación o mantenimiento. | Incluir lista de comprobación, limpieza, calibración y canal de soporte.                                                    | El usuario configura el equipo y reconoce cuándo requiere mantenimiento. |



Antes de TRL 7 se recomienda una prueba de usabilidad con acuicultores. Registrar tareas completadas, errores, tiempo empleado y necesidad de asistencia; utilizar los resultados para corregir el manual y la interfaz.

**7. Fabricación, servicio posventa y viabilidad económica**

7.1. Fabricación y control de calidad

| **Aspecto**    | **Actividad requerida**                                                                                                        | **Evidencia**                        |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------ |
| Documentación. | Preparar lista de materiales (BOM), planos y especificaciones de sensores, electrónica, batería, carcasa, boya, cable y motor. | BOM y planos con versión controlada. |
| Ensamblaje.    | Definir el orden de montaje y las verificaciones por etapa.                                                                    | Procedimiento de ensamblaje.         |
| Prueba final.  | Verificar sensores, profundidad, comunicación, estanqueidad, estabilidad y consumo.                                            | Registro de aceptación por unidad.   |
| Trazabilidad.  | Asignar número de serie y registrar componentes, firmware, reparaciones y pruebas.                                             | Historial individual del equipo.     |



7.2. Servicio posventa

| **Servicio**            | **Qué debe quedar definido**                                                              |
| ----------------------- | ----------------------------------------------------------------------------------------- |
| Garantía.               | Plazo, cobertura, exclusiones y procedimiento de atención.                                |
| Mantenimiento.          | Frecuencia de limpieza, calibración e inspección de sensores, cable, carcasa y mecanismo. |
| Repuestos y reparación. | Disponibilidad de sondas, cables, conectores y componentes críticos.                      |
| Soporte.                | Instalación, capacitación, asistencia técnica y actualización de firmware.                |



7.3. Viabilidad económica

El costo total no debe limitarse al precio de los componentes. Debe incluir fabricación, mano de obra, ensamblaje, pruebas, instalación, calibración, conectividad, limpieza, reposición de sensores, garantía y soporte.

| **Variable económica**       | **Qué se debe calcular o validar**                                                     |
| ---------------------------- | -------------------------------------------------------------------------------------- |
| Costo de fabricación.        | Materiales, electrónica, carcasa, sensores, mano de obra y pruebas por unidad.         |
| Costo de operación.          | Energía, conectividad, limpieza, calibración y reemplazo de componentes.               |
| Precio y aceptación.         | Entrevistas y pilotos con acuicultores para conocer necesidades y disposición de pago. |
| Sostenibilidad del servicio. | Costo de garantía, atención técnica, mantenimiento y stock de repuestos.               |



**8. Actividades pendientes para avanzar hacia TRL 7**

| **Etapa**                            | **Actividades principales**                                                                                                     | **Evidencia esperada**                                                                |
| ------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| TRL 4 – laboratorio.                 | Integración y pruebas controladas de sensores, mecanismo, electrónica, LoRa y dashboard.                                        | Protocolos, resultados y registro de fallas.                                          |
| TRL 5 – entorno relevante.           | Pruebas con agua real, ciclos de movimiento, autonomía, comunicación, calibración y estanqueidad.                               | Informe de pruebas y comparación con instrumentos de referencia.                      |
| TRL 6 – prototipo de alta fidelidad. | Prototipo integrado, repetible y cercano al producto; validar mantenimiento, recuperación y usabilidad.                         | Prototipo funcional e informe de demostración en entorno relevante.                   |
| TRL 7 – entorno operacional.         | Instalar y operar en un centro real de crianza de trucha; registrar estabilidad, mediciones, autonomía, fallas y mantenimiento. | Bitácora de campo, datos, acta de instalación, manual validado e informe operacional. |



La patente, el RUC y la aceptación comercial son requisitos de preparación para proteger y comercializar el producto, pero no sustituyen la evidencia tecnológica necesaria para declarar TRL 7.

REFERENCIAS

[1] INACAL, NTP 320.004:2014 (revisada en 2021), “Acuicultura. Buenas prácticas acuícolas en la producción de trucha arcoíris”, 2.ª ed., 2021. https\://rnia.produce.gob.pe/publican-norma-tecnica-peruana-sobre-buenas-practicas-acuicolas-en-la-produccion-de-trucha-arco-iris-version-2021/

[2] INACAL, “Preguntas frecuentes sobre normalización y Normas Técnicas Peruanas”. https\://www\.inacal.gob.pe/principal/categoria/preguntas-frecuentes-normalizacion

[3] SANIPES, “Habilitación sanitaria de centros de cultivo acuícola”, TUPA. https\://www\.sanipes.gob.pe/tupa/tupa__13.php

[4] MTC, “Homologación de equipos y aparatos de telecomunicaciones que generan emisiones radioeléctricas”. https\://www\.gob.pe/22738-solicitar-certificado-de-homologacion-para-un-equipo-y-o-aparato-de-telecomunicaciones-que-genera-emisiones-radioelectricas

[5] ISO/IEC, ISO/IEC 17025:2017, General requirements for the competence of testing and calibration laboratories, 2017.

[6] MINAM, D. S. N.° 009-2019-MINAM, Régimen Especial de Gestión y Manejo de Residuos de Aparatos Eléctricos y Electrónicos, 2019. https\://www\.gob.pe/institucion/minam/normas-legales/354138-009-2019-minam

[7] Comunidad Andina, Decisión 486, Régimen Común sobre Propiedad Industrial, 2000. https\://www\.comunidadandina.org/

[8] SUNAT, “Inscripción al RUC para persona jurídica”. https\://www\.gob.pe/276-registro-o-constitucion-de-empresa-inscripcion-al-ruc-para-persona-juridica




