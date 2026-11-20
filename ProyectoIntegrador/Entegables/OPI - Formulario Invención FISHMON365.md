FORMULARIO N° OPI –       *(A llenar por la oficina)*

FORMULARIO N° OPI – *(A llenar por la oficina)*

**FORMULARIO DE DECLARACIÓN DE INVENCIÓN[^1]**

Este Formulario de declaración de Invención es el medio de comunicación oficial entre investigador/docente/estudiante/administrativo y la Oficina de Propiedad Intelectual (OPI) de la UPCH en cuanto a desarrollos científicos-tecnológicos, resultados de investigación básica o aplicada, desarrollo tecnológico, madurez tecnológica que resulten en una posible invención[^2], a fin de evaluar su potencial de registro como propiedad industrial para una eventual explotación comercial.

La información contenida en este documento es de carácter confidencial y sólo se divulgará entre individuos involucrados en el proceso de evaluación. No será divulgada entre otros, sin que existan acuerdos de confidencialidad entre ellos. Una vez completo debe ser enviado al correo [duie.opi@oficinas-upch.pe](mailto:duie.opi@oficinas-upch.pe) para dar inicio al proceso.

**1\. Datos de la invención**

| Código SIDISI[^3] |  | No registra. Proyecto desarrollado en el curso Proyecto Integrador (Ingeniería informática, UPCH). |  |  |  |  |  |
| ----- | :---- | ----- | :---: | :---- | ----- | :---: | :---: |
| Título de proyecto SIDISI |  | No aplica |  |  |  |  |  |
| Fechas de proyecto |  | Inicio | 18/08/2026 |  |  | Fin | 3/12/2026 |
| Título de la invención |  | **Sistema autónomo multiparámetro y multinivel para el monitoreo de la calidad del agua en la crianza de trucha arco iris** |  |  |  |  |  |
| Título corto de la invención (si aplica) |  | **FishMon 365** |  |  |  |  |  |
| Resumen (describir brevemente el problema técnico que resuelve la invención, y luego la invención en sí). |  | La crianza de trucha arco iris requiere vigilar variables de calidad del agua que pueden variar con la profundidad; las mediciones manuales o realizadas en un solo punto pueden no representar adecuadamente la columna de agua. FishMon 365 propone una boya IoT compuesta por un módulo flotante y un módulo sumergible móvil que mide oxígeno disuelto, temperatura, pH, turbidez y conductividad en distintos niveles de profundidad. El módulo sumergible integra sensores y un Arduino Nano; el módulo flotante integra un ESP32 con LoRa, alimentación y un mecanismo de descenso/elevación. Los datos se asocian con la profundidad de medición, se transmiten a un receptor/gateway y se visualizan en un dashboard con historial y alertas. La propuesta busca integrar monitoreo multiparámetro y multinivel en una arquitectura adaptable a diferentes instalaciones acuícolas. |  |  |  |  |  |
| Sector tecnológico |  | Acuicultura, monitoreo ambiental, Internet de las Cosas (IoT) y sistemas embebidos |  |  |  |  |  |
| Tipo de invención |  | Producto y procedimiento de monitoreo |  |  |  |  |  |
| ¿Ha hecho pública la invención? |  | Sí |  |  |  |  |  |
|  | Colocar enlace de publicación | https://github.com/WillyCcV19/PI_Equipo_04.git |  |  |  |  |  |
| En caso de que haya hecho pública la invención, cree que una persona con conocimientos similares a los de usted puede **replicar** el mismo producto y/o procedimiento. |  | Sí |  |  |  |  |  |
| ¿Considera que la invención es nueva a nivel mundial? |  | No |  |  |  |  |  |
| ¿La invención mejora sustancialmente la **tecnología ya conocida**[^4]? |  | Sí |  |  |  |  |  |
| En caso de que la respuesta sea “**Sí**” a la pregunta anterior. ¿Puede describir en qué consiste esa mejora sustancial? |  | La mejora propuesta radica en la integración funcional de: (i) un módulo flotante de control/comunicación y un módulo sumergible móvil; (ii) medición de cinco variables de calidad del agua; (iii) posicionamiento del módulo de sensado en niveles superior, medio e inferior; (iv) asociación de cada registro con su profundidad; (v) comunicación LoRa y dashboard con historial y alertas; y (vi) configuración de las posiciones de medición según la profundidad útil de la instalación. La diferenciación debe evaluarse frente a las reivindicaciones del estado de la técnica. |  |  |  |  |  |
| En caso de que la invención sea de producto ¿ha desarrollado un **prototipo**[^5]? |  | Sí |  |  |  |  |  |
| Acerca del mercado para la invención. |  | ¿Existe un producto similar? |  |  | Sí |  |  |
|  |  | ¿Cuál(es)? |  |  | Durante la revisión de antecedentes se identificaron sistemas tecnológicos y patentes relacionados con monitoreo de calidad del agua y acuicultura. Entre los antecedentes tecnológicos se encuentra el proyecto de PROCIENCIA orientado al desarrollo de un sistema IoT multiparámetro para la gestión automatizada de la calidad del agua en estanques de cultivo de trucha arco iris, considerando variables como temperatura, pH y oxígeno disuelto. También se identificó WiFish, una plataforma IoT para acuicultura que utiliza un ESP32, sensores de pH y temperatura, comunicación inalámbrica, almacenamiento en la nube, visualización remota y generación de alertas. Asimismo, se revisaron las siguientes patentes: CN216791993U, "Handheld water quality measuring instrument", relacionada con un instrumento portátil para medición de calidad del agua y protección de sus componentes. CN102809637A, "Handheld water quality measuring instrument", correspondiente a un instrumento multiparámetro que integra sensores para conductividad o salinidad, pH, gases disueltos, oxígeno disuelto y otras variables, además de almacenamiento de datos. CN103969414A, "Wireless water quality multi-parameter monitoring system", que incorpora sensores, baterías, circuitos de control y comunicación inalámbrica para monitoreo multiparámetro de calidad del agua. WO2022119461A1, "Aquaculture monitoring device", orientada específicamente al monitoreo acuícola. Esta solución utiliza una estructura flotante, sensores de temperatura, pH y oxígeno disuelto, procesamiento electrónico, alimentación y conectividad inalámbrica, además de permitir el registro de mediciones y la generación de notificaciones frente a valores críticos. Estos antecedentes sirvieron como referencia para conocer las tecnologías existentes y formular una propuesta que incorpore características adicionales asociadas al monitoreo multinivel. |  |  |
|  |  | Su invención, ¿tiene ventajas competitivas? Mencionar |  |  | Sí. Las principales ventajas propuestas de FishMon 365 son: integración de cinco sensores para monitorear de manera conjunta variables relevantes para la crianza de trucha arco iris: oxígeno disuelto, temperatura, pH, turbidez y conductividad; adquisición de datos en distintos niveles de profundidad; módulo sumergible móvil con mecanismo de descenso y elevación; asociación de cada medición con la profundidad en la que fue obtenida; uso de relés para controlar la activación de determinados sensores o circuitos, reduciendo posibles interferencias eléctricas entre las mediciones; comunicación de largo alcance mediante LoRa; visualización de datos históricos mediante dashboard; generación de alertas frente a valores fuera de los rangos establecidos; orientación específica hacia sistemas de crianza de trucha arco iris; arquitectura modular que separa el módulo flotante del módulo de sensado sumergible. |  |  |
| Mencione algunos países donde cree que sea imprescindible proteger la invención legalmente[^6] |  | País 1 |  | Perú |  |  |  |
|  |  | País 2 |  | Chile |  |  |  |
|  |  | País 3 |  | Colombia |  |  |  |
|  |  | País 4 |  | Ecuador |  |  |  |
|  |  | País 5 |  | Bolivia |  |  |  |
| ¿Ha hecho un estudio de mercado de su invención[^7]? |  | No |  |  |  |  |  |

**2\. Titularidad**

¿La invención se ha desarrollado con otra entidad?

| NO | X | SI |  | En caso afirmativo completar el siguiente cuadro |
| :---- | :---- | :---- | :---- | :---- |
<!-- -->
| Nombre de la institución 1 |  |  |  |  |
| :---- | :---- | :---- | :---- | :---- |
| País |  |  |  |  |
| RUC |  |  |  |  |
| Dirección |  |  |  |  |
| Persona de contacto |  |  |  |  |
| Correo |  |  |  |  |
| Teléfono |  |  |  |  |
| ¿Se cuenta con convenio firmado sobre el desarrollo del proyecto? | NO |  | SI (Adjuntar) |  |
| ¿Se ha establecido el % de cotitularidad? | NO |  | SI ¿Cuánto?[^8] |  |

**3\. Datos de los inventores**

**3.1 Inventores pertenecientes a la UPCH**

| Datos del inventor N° 1 |  |
| :---: | ----- |
| Apellidos, nombres | Kenneth Karita John |
| Nacionalidad | Argentina |
| N° DNI/CE | AAB246036 |
| Facultad/unidad de gestión a la pertenece | Facultad de Ciencias e Ingeniería |
| Tipo de usuario (Docente, estudiante, administrativo etc) | Estudiante |
| Domicilio | Callao-Bellavista Jr. Grau |
| Celular | +51 979 144 378 |
| E-mail | john.karita@upch.pe |
| Aporte en el desarrollo de la invención | Líder del desarrollo electrónico del proyecto. Responsable del diseño de la arquitectura de hardware, elaboración de esquemáticos, diseño de placas PCB, integración de componentes electrónicos, desarrollo y ensamblaje del hardware, así como de la coordinación técnica de la parte electrónica de FishMon 365. |
<!-- -->
| Datos del inventor N° 2 |  |
| :---: | ----- |
| Apellidos, nombres | Pauccara Huancara Eber |
| Nacionalidad | Perú |
| N° DNI/CE | 72043108 |
| Facultad/unidad de gestión a la pertenece | Facultad de Ciencias e Ingeniería |
| Tipo de usuario (Docente, estudiante, administrativo etc) | Estudiante |
| Domicilio | Jr. Vargas Machucas |
| Celular | +51 926 135 229 |
| E-mail | eber.pauccara@upch.pe |
| Aporte en el desarrollo de la invención | Responsable del desarrollo e implementación del modelado del sistema, elaboración de diseños conceptuales y apoyo en la documentación técnica, organización de evidencias y registro del avance del proyecto FishMon 365. |
<!-- -->
| Datos del inventor N° 3 |  |
| ----- | :---: |
| Apellidos, nombres | Quispitongo Leon Verenisse Mary |
| Nacionalidad | Perú |
| N° DNI/CE | 70645154 |
| Facultad/unidad de gestión a la pertenece | Facultad de Ciencias e Ingeniería |
| Tipo de usuario (Docente, estudiante, administrativo etc) | Estudiante |
| Domicilio | Jr. Victor Criado y Tejada |
| Celular | 956252453 |
| E-mail | verenisse.quispitongo@upch.pe |
| Aporte en el desarrollo de la invención | Responsable de investigación, apoyo en el diseño y revisión del modelado 3D, elaboración de documentación técnica y verificación de la correcta implementación, integración y funcionamiento conceptual de los subsistemas de FishMon 365. |
<!-- -->
| Datos del inventor N° 4 |  |
| ----- | ----- |
| Apellidos, nombres | Ccatamayo Vasquez Willy Simeon |
| Nacionalidad | Perú |
| N° DNI/CE | 71701284 |
| Facultad/unidad de gestión a la pertenece | Facultad de Ciencias e Ingeniería |
| Tipo de usuario (Docente, estudiante, administrativo etc) | Estudiante |
| Domicilio | av. Andrés Avelino Cáceres |
| Celular | 965280455 |
| E-mail | willy.ccatamayo |
| Aporte en el desarrollo de la invención | Responsable de programación, apoyo en el diseño del modelado 3D, implementación de la comunicación LoRa entre los módulos del sistema y desarrollo de la lógica para transmisión, recepción y visualización de los datos obtenidos por FishMon 365. |
<!-- -->
| Datos del inventor N° 5 |  |
| ----- | ----- |
| Apellidos, nombres | Cabrera Cermeno Ruben Andre |
| Nacionalidad | Perú |
| N° DNI/CE | 73117309 |
| Facultad/unidad de gestión a la pertenece | Facultad de Ciencias e Ingeniería |
| Tipo de usuario (Docente, estudiante, administrativo etc) | Estudiante |
| Domicilio | Calle Jose Gabriel Aguilar |
| Celular | 975048294 |
| E-mail | ruben.cabrera@upch.pe |
| Aporte en el desarrollo de la invención | Responsable de apoyo en el diseño del modelado 3D, elaboración de documentación técnica y desarrollo del esquema funcional del sistema FishMon 365, contribuyendo a definir la relación y funcionamiento de sus principales subsistemas. |

**3.2 Inventores de otras instituciones (solo si aplica)**

| Apellidos, nombres | N° DNI/ CE | Institución a la pertenece | Dirección | Correo |
| :---- | :---- | :---- | :---- | :---- |
|  |  |  |  |  |
|  |  |  |  |  |
|  |  |  |  |  |

**4\. Uso de recursos genéticos y/o conocimientos tradicionales**

Si la obtención de los resultados a proteger ha implicado el uso de recursos genéticos, indicar:

| País de procedencia del recurso genético |  |  |  |  |  |  |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- |
| Fecha de acceso al recurso genético |  |  |  |  |  |  |
| Condiciones de acceso al recurso genético | acceso in situ |  |  |  | acceso ex situ |  |
| ¿Cuenta con la autorización de la autoridad competente? | NO |  |  | SÍ (Adjuntar) |  |  |

**5\. Información adicional**

| ¿Dispone de recursos económicos previstos que puedan ser destinados a cubrir los gastos de protección de los resultados de investigación? | NO | X | SÍ (Señalar con cuánto presupuesto cuenta) |  |  |  |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- |
| ¿Qué pasos/etapas considera usted que faltan para obtener un producto comercializable a partir de su invención? | Completar la integración del prototipo; calibrar/validar individualmente los cinco sensores; validar estanqueidad e inmersión; verificar precisión y repetibilidad del mecanismo de descenso/elevación; validar posicionamiento real frente a la profundidad programada; integrar Arduino Nano–ESP32–LoRa–gateway–backend–dashboard; realizar pruebas de autonomía, alcance LoRa y resistencia mecánica; ejecutar pruebas en entorno acuícola representativo; optimizar diseño para manufactura y mantenimiento; realizar estudio de mercado, costos y modelo de negocio; efectuar búsqueda de patentabilidad/libertad de operación y definir estrategia de protección; realizar pilotos con usuarios y preparar escalamiento. |  |  |  |  |  |
| ¿El proyecto fue financiado por alguna entidad externa? | NO | X |  |  |  |  |
|  | Sí | Fuente de financiamiento/patrocinador |  |  |  |  |
|  |  | Número de contrato |  |  |  |  |
|  |  | Investigador principal |  |  |  |  |
| ¿El desarrollo del proyecto utilizó algún material patentado (por ejemplo línea celular, anticuerpo, plásmido, otros) por un tercero? | No | X |  |  |  |  |
|  | Sí (Especifique) |  |  |  |  |  |
| Si es posible, identifique aquellas empresas que están o podrían estar interesadas en su invención y aquellas que produzcan o comercialicen tecnologías equivalentes. | Potenciales interesados: productores y asociaciones de trucha, empresas acuícolas, centros de cultivo, proveedores de tecnología para acuicultura y entidades de monitoreo ambiental. Tecnologías equivalentes o relacionadas: fabricantes de sondas multiparámetro y sensores de calidad de agua (por ejemplo, YSI/Xylem, Hanna Instruments, DFRobot) y desarrolladores de plataformas IoT acuícolas. La identificación comercial definitiva requiere un estudio de mercado. |  |  |  |  |  |

**6\. Declaraciones**

| Los inventores identificados en el presente documento declaran bajo juramento lo siguiente: Que, la información declarada en el presente “Formulario de declaración de la invención” es veraz, pertinente, fiable y verificable. Que, la invención no menoscaba derechos de propiedad intelectual de terceros[^9]. Que, declaran saber y conocer el texto íntegro del Reglamento de Propiedad Intelectual de la UPCH. De igual forma, los inventores declaran que se comprometen a que toda negociación con terceros sobre la transferencia tecnológica de la invención deberá realizarse bajo pleno conocimiento y en coordinación con la Oficina de Transferencia Tecnológica (OTT) de la Universidad Peruana Cayetano Heredia (UPCH). Asimismo, declaran saber y conocer que la cesión de titularidad o el licenciamiento de la invención a terceros debe realizarse conforme al Reglamento de Propiedad Intelectual de la UPCH, y debe ser aprobada por el Comité de Innovación y, de corresponder, por el Consejo Universitario de la UPCH. Los inventores manifiestan que, conforme al Reglamento de Propiedad Intelectual de la UPCH, voluntariamente ceden sus derechos patrimoniales de la invención a la UPCH. De igual forma, declaran que en el presente “Formulario de declaración de la invención” no ha mediado dolo, error, coacción ni ningún vicio que pudiera invalidarlo. En caso de que se haya hecho pública la invención, los inventores declaran conocer que cuentan con doce (12) meses a partir de la divulgación más antigua, para proteger los resultados de su investigación ante la autoridad competente; en caso contrario, hay riesgo de perder la posibilidad de patentar la invención, ya que perderá la novedad, el cual es el primer requisito para que sea concedida la patente. En caso la invención sea objeto de protección bajo la modalidad de patente de invención o modelo de utilidad, el(los) inventor(es) se comprometen a brindar toda la información solicitada por la Autoridad Competente[^10] durante el trámite. Finalmente, los inventores declaran que se comprometen a impulsar el crecimiento del “nivel de madurez tecnológica” (TRL, por sus siglas en inglés). Asimismo, informar oportunamente a la OPI sobre todas las actividades relacionadas con el TRL. |
| :---- |

**7\. Información complementaria**

Indicar alguna otra información que consideren relevante

8. **Firma de los inventores (solo inventores UPCH)**

| N° | Apellidos, nombres | Regalías\* | Firma | Fecha |
| ----- | ----- | :---: | ----- | ----- |
| 1 | Kenneth Karita John | 28% | ![][image1] | 19/11/2026 |
| 2 | Pauccara Huancara Eber | 18% | ![][image2] | 19/11/2026 |
| 3 | Quispitongo Leon Verenisse Mary | 18% | ![][image3] | 19/11/26 |
| 4 | Ccatamayo Vasquez Willy Simeon | 18% | ![][image4] | 19/11/26 |
| 5 | Cabrera Cermeno Ruben Andre | 18% | ![][image5] | 19/11/26 |

\*Detalle del porcentaje acordado entre los inventores UPCH para la distribución de las regalías en caso de que se explote la invención. (La distribución debe sumar 100%).

| Para ser llenado por la OPI |  |
| ----- | :---: |
| Fecha de recepción |  |
| Recibido por |  |
| Firma |  |

[^1]: Se entiende por invención cualquier nueva solución técnica (ya sea de producto o procedimiento) a un problema. El **software** en los Estados Unidos se le considera como invento, por ello es susceptible a protegerse mediante patentes; en cambio en el Perú (y el resto de la Comunidad Andina: Bolivia, Colombia y Ecuador) el software se considera como obra y está sujeto al derecho de autor.

[^2]: Una invención o innovación es la creación de una nueva idea técnica y de los medios físicos para llevarla a cabo. Para que sea patentable, una invención debe ser nueva, ser útil y ser diferente de lo que podría esperar cualquier experto en esa área tecnológica. [https://www.wipo.int/patentscope/es/db/glossary.html#i](https://www.wipo.int/patentscope/es/db/glossary.html#i)

[^3]: SIDISI. Sistema Descentralizado de Información y Seguimiento a la Investigación.

[^4]: La tecnología ya conocida es lo que se denomina el *estado del arte* o *de la técnica*.

[^5]: Prototipo. Ejemplar original o primer molde en que se fabrica una figura u otra cosa (Real Academia Española, 2014, [http://lema.rae.es/drae/?val=prototipo](http://lema.rae.es/drae/?val=prototipo)).

[^6]: Algunos criterios son: la capacidad tecnológica de ese país para copiar el invento, el tamaño de la población, el nivel de ingresos de los pobladores, el respeto a la propiedad intelectual del país. En caso de que el invento esté relacionado con fármacos que tratan enfermedades, son de ayuda los datos epidemiológicos.

[^7]: En caso de que la respuesta sea “**No**”, la OTT le puede ayudar a hacer dicho estudio.

[^8]: El porcentaje de titularidad de todos los solicitantes debe sumar 100%.

[^9]: Se define como terceros en el presente documento a cualquier otra persona natural o jurídica, incluyendo organismos del Estado.

[^10]: Es una organización u oficina responsable de resolver las solicitudes de patentes en sus distintas instancias, aplicando la normativa que rige la Propiedad Intelectual en su territorio.

[image1]: <PEGAR_AQUÍ_LA_IMAGEN_O_RUTA_DE_LA_FIRMA_DE_KENNETH>
[image2]: <PEGAR_AQUÍ_LA_IMAGEN_O_RUTA_DE_LA_FIRMA_DE_EBER>
[image3]: <PEGAR_AQUÍ_LA_IMAGEN_O_RUTA_DE_LA_FIRMA_DE_VERENISSE>
[image4]: <PEGAR_AQUÍ_LA_IMAGEN_O_RUTA_DE_LA_FIRMA_DE_WILLY>
[image5]: <PEGAR_AQUÍ_LA_IMAGEN_O_RUTA_DE_LA_FIRMA_DE_RUBEN>
