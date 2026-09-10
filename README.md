# EQUIPO N° IV - Proyecto Integrador 2026-2  
<div align="center">

<!-- Banner animado (capsule-render funciona nativo en GitHub, sin GIFs pesados) -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0077B6,100:00B4D8&height=200&section=header&text=FISHMON%20365&fontSize=55&fontColor=ffffff&animation=fadeIn&fontAlignY=35&desc=Monitoreo%20IoT%20de%20calidad%20de%20agua%20para%20truchicultura&descAlignY=55&descSize=18" width="100%"/>

<!-- Texto tipo "máquina de escribir" (animado, se genera al vuelo) -->
<a href="#-qué-va-a-consistir-el-proyecto">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=20&pause=1000&color=0077B6&center=true&vCenter=true&width=650&lines=Dispositivo+multiparam%C3%A9trico+portatil+y+aut%C3%B3nomo;Monitoreo+de+Ox%C3%ADgeno+Disuelto+en+tiempo+real;Alertas+tempranas+v%C3%ADa+IoT+%2B+Dashboard;Validado+en+campo+en+Santa+Eulalia%2C+Lima" alt="Typing SVG" />
</a>

<br/><br/>

![Grupo](https://img.shields.io/badge/Grupo-IV-red?style=for-the-badge)
![Universidad](https://img.shields.io/badge/Universidad-UPCH-0077B6?style=for-the-badge)
![Curso](https://img.shields.io/badge/Curso-Proyecto_Integrador-00B4D8?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-En_Desarrollo-orange?style=for-the-badge)

</div>


### Carrera de Ingeniería Industrial / Informática   
**Universidad Peruana Cayetano Heredia**

<img src="/Imagenes/Integrantes/banner.png" width="1000"/>


---

## 👫 ¿Quiénes somos?

Somos participantes del curso Proyecto Integrador 2026-2, integrados por estudiantes de Ingeniería Industrial e Informática de la Universidad Peruana Cayetano Heredia. Nuestra misión es utilizar la metodología de diseño para desarrollar soluciones creativas y técnicamente fundamentadas que aporten valor social, tecnológico y ambiental.

---

## ⚙️  Justificación Técnica y Fundamento Biológico

Para validar técnicamente el desarrollo de FISHMON 365, nos basamos en la normativa e investigación oficial del Fondo Nacional de Desarrollo Pesquero (FONDEPES - PRODUCE, Perú) [1]:

### 1. Especie Cultivada y Taxonomía

- **Especie de crianza:** Trucha Arco Iris [1].
- **Nombre científico oficial:** *Oncorhynchus mykiss* (denominada anteriormente *Salmo gairdneri irideus*) [1].
- **Ambiente de cultivo:** Agua dulce continental (recursos hídricos lóticos como ríos, arroyos y manantiales, y lénticos como lagunas) [1].

### 2. Sistemas de Acuicultura en el Perú y Diagnóstico de Mortalidad

| Criterio Técnico | Sistema Convencional (Estanquería) | Sistema No Convencional (Jaulas Flotantes) |
|------------------|------------------------------------|---------------------------------------------|
| **Infraestructura principal** | Estanques de concreto, mampostería de piedra y tierra [1]. | Jaulas flotantes en lagos y lagunas [1]. |
| **Distribución Regional** | Mayor prevalencia en la Región Junín [1]. | Predominante en la Región Puno (concentra el 98% de esta modalidad) [1]. |
| **Aporte a la Producción Nacional (2012)** | Junín: 3,412.53 TM/Año (13.78%) [1]. | Puno: 18,471.02 TM/Año (74.59%) [1]. |
| **Variabilidad del Medio** | Altamente vulnerable a fluctuaciones de caudal, temperatura y arrastre de sólidos por lluvias [1]. | Vulnerable a eventos de anoxia global en la columna de agua y ecorregiones lénticas [1]. |

### 3. Causa Principal de Mortalidad: Asfixia e Hipoxia por Deficiencia de Oxígeno Disuelto (O₂)

La mayor tasa de mortandad o pérdida de rendimiento biológico-económico en los cultivos de trucha se debe a la pérdida del equilibrio entre el Hospedador, el Patógeno y el Ambiente ($H + P + A = E$) [1].

Específicamente, el factor crítico es la asfixia e hipoxia por baja concentración de oxígeno disuelto ($O_2$). De acuerdo con FONDEPES [1]:

> *"Como la crianza se realiza a grandes densidades es recomendable que la cantidad de oxígeno no sea menor a 5.5 mg/l (60% de saturación de oxígeno) en los momentos de máximo consumo en el cultivo, ya que de lo contrario los peces van a presentar signos de asfixia"* [1, p. 12].
>
> *"Pueden presentarse peces con hipoxia, aunque haya suficiente oxígeno en el medio de cultivo por la presencia de nitritos"* [1, p. 62].

---

## ⚙️ ¿En qué va a consistir el proyecto?

**FISHMON 365** es un **dispositivo multiparámetro portátil y autónomo** diseñado para el **monitoreo en tiempo real y a multinivel** de la calidad del agua dulce en sistemas de cultivo de trucha (*Oncorhynchus mykiss*) [1]. 

El sistema está compuesto por una **sección flotante con electrónica blindada** y una **sonda sumergible vertical multinivel**, equipada con sensores calibrados para realizar lecturas continuas a tres profundidades distintas dentro de la columna de agua. Toda la información capturada es procesada y transmitida de forma inalámbrica mediante tecnología **IoT** directamente a una **aplicación móvil para smartphone**, enviando alertas tempranas en tiempo real ante variaciones fuera de los rangos seguros [1].

Para garantizar la continuidad operativa en zonas rurales o ante posibles cortes de energía eléctrica, el equipo integra un **sistema de alimentación autónomo con batería de respaldo**, asegurando mediciones ininterrumpidas las 24 horas del día.

---

### Perfil de Medición Multinivel en la Columna de Agua

Dado que parámetros críticos como el oxígeno disuelto y la temperatura varían verticalmente según la dinámica del estanque, la descomposición de materia orgánica y el nivel de alimentación [1], **FISHMON 365** monitorea tres estratos clave:

| Profundidad / Estrato | Justificación Técnica Biológica | Impacto en la Trucha Arco Iris |
| :--- | :--- | :--- |
| **Superficie** | Zona de mayor intercambio gaseoso atmosférico e incidencia de radiación solar [1]. | Evalúa la temperatura máxima y la saturación inicial de oxígeno [1]. |
| **Nivel Medio (Media Agua)** | Zona de natación activa y desplazamiento del cardumen de truchas en crecimiento [1]. | Garantiza que la masa de agua habitada mantenga tenores de $O_2 \ge 5.5\text{ mg/L}$ [1]. |
| **Nivel de Fondo (Suelo acuícola)** | Zona de acumulación de alimento no consumido, heces, materia orgánica y alimentación del pez [1]. | Detecta zonas anóxicas ($O_2 < 3.0\text{ mg/L}$), acumulación de nitritos y variaciones de pH por descomposición [1]. |

---


## 🌿 Contexto de Aplicación y Validación de Campo: Santa Eulalia

Para validar el prototipo en condiciones reales de campo de la sierra de Lima, el dispositivo se probará en las piscigranjas de agua dulce del distrito de Santa Eulalia (Provincia de Huarochirí, Lima):

- **Ubicación de prueba:** Valle del río Santa Eulalia (Afluente del río Rímac).
- **Altitud de evaluación:** Entre 1,036 m.s.n.m. y 1,400 m.s.n.m. (zona de cuenca media).
- **Características hídricas:** Aguas continentales dulceacuícolas lóticas (ríos y arroyos de deshielo/manantial) [1].
- **Impacto ambiental local:** Permite monitorear la variación de temperatura y oxígeno disuelto en temporadas de estiaje vs. avenidas (lluvias), previniendo el estrés branquial y mortandades masivas [1].

---

## 🌿 ¿Qué problemáticas soluciona?

| Problema Actual en la Truchicultura | Solución Técnica que Aporta FISHMON 365 | Sustento Oficial (FONDEPES) |
|--------------------------------------|------------------------------------------|-----------------------------|
| Altas mortandades por asfixia silenciosa ($O_2 < 5.5\text{ mg/L}$) | Monitoreo continuo de Oxígeno Disuelto con alertas sonoras/visuales inmediatas. | *"A menores niveles de $O_2$ (0 - 3.0 mg/l), la trucha muere; entre 3.1 - 4.5 mg/l sufre grave estrés"* [1, p. 12]. |
| Elevados costos de equipos comerciales de laboratorio | Diseño portátil de bajo costo con componentes e integración local | Permite acceso a tecnología a productores de subsistencia y menor escala ($99.44\%$ del mercado) [1, p. 9]. |
| Mediciones manuales extemporáneas que no previenen crisis | Lectura inmediata en campo con diagnóstico automático vía IoT | Permite ajustar inmediatamente la tasa de recambio de agua por hora (R/A/H) [1, p. 11]. |
| Falta de conectividad en zonas altoandinas/rurales | Funcionamiento en modo offline con almacenamiento SD y sincronización posterior IoT | Asegura el registro histórico sin depender de cobertura celular continua. |
| Falta de estandarización técnica del criador | Configuración de umbrales bajo la NTP y manuales de PRODUCE/FONDEPES | Ajustado a los rangos óptimos del agua para *Oncorhynchus mykiss* [1, p. 12-13]. |

---

## 🌿 Alineación con Objetivos de Desarrollo Sostenible (ODS)

Nos comprometemos con la agenda global incorporando las metas oficiales ajustadas según la fuente de la Organización de las Naciones Unidas (ONU):

### 🌿 ODS 9: Industria, Innovación e Infraestructura

**Meta 9.5:** *Aumentar la investigación científica y mejorar la capacidad tecnológica de los sectores industriales de todos los países, en particular los países en desarrollo, entre otras cosas fomentando la innovación e incrementando considerablemente de aquí a 2030 el número de personas que trabajan en investigación y desarrollo por millón de habitantes y los gastos en investigación y desarrollo de los sectores público y privado.*

### 🌿 ODS 12: Producción y Consumo Responsables

**Meta 12.a:** *Ayudar a los países en desarrollo a fortalecer su capacidad científica y tecnológica para avanzar hacia modalidades de consumo y producción más sostenibles.*

### 🌿 ODS 14: Vida Submarina y Recursos Hídricos

**Meta 14.7:** *De aquí a 2030, aumentar los beneficios económicos que los pequeños Estados insulares en desarrollo y los países menos adelantados obtienen del uso sostenible de los recursos marinos, en particular mediante la gestión sostenible de la pesca, la acuicultura y el turismo.*

**Meta 14.a:** *Aumentar los conocimientos científicos, desarrollar la capacidad de investigación y transferir tecnología marina, teniendo en cuenta los Criterios y Directrices para la Transferencia de Tecnología Marina de la Comisión Oceanográfica Intergubernamental, a fin de mejorar la salud de los océanos y potenciar la contribución de la biodiversidad marina al desarrollo de los países en desarrollo, en particular los pequeños Estados insulares en desarrollo y los países menos adelantados.*

---

## 🌿 Matriz de Parámetros Técnicos de Medición (Agua Dulce)

Basado estrictamente en las especificaciones del Manual de Cultivo de Trucha - FONDEPES [1]:

| Parámetro Fisicoquímico | Rango Crítico / Letal | Rango Óptimo de Cultivo | Impacto Biológico en la Trucha Arco Iris |
|--------------------------|------------------------|--------------------------|-------------------------------------------|
| **Oxígeno Disuelto ($O_2$)** | $< 3.0\text{ mg/L}$ (Muerte)<br>$3.1 - 4.5\text{ mg/L}$ (Estrés grave) [1] | **$6.0 - 8.5\text{ mg/L}$** (Mínimo $5.5\text{ mg/L}$) [1] | La deficiencia causa asfixia, reducción del consumo de alimento y suspensión del crecimiento [1]. |
| **Temperatura ($T^\circ\text{C}$)** | $< 3^\circ\text{C}$ o $> 20^\circ\text{C}$ (Muerte / Riesgo severo) [1] | **$11 - 16^\circ\text{C}$** (Engorde óptimo: $15 - 16^\circ\text{C}$)<br>(Incubación: $8 - 10^\circ\text{C}$) [1] | Condiciona el metabolismo, apetito, velocidad de crecimiento y solubilidad del oxígeno disuelto [1]. |
| **Potencial de Hidrógeno (pH)** | $< 6.0$ o $> 9.0$ (Incompatible con la vida) [1] | **$7.0 - 8.0$** (Ligeramente alcalino) [1] | Niveles $< 6.5$ producen hemorragias branquiales y mortandades masivas [1]. |
| **Turbidez / Sólidos** | Elevados sólidos en suspensión [1] | Agua cristalina / Filtrada [1] | Los sólidos en suspensión dañan las branquias y sofocan a los alevinos [1]. |
| **Dióxido de Carbono ($CO_2$)** | $> 2.0\text{ ppm}$ [1] | $< 2.0\text{ ppm}$ [1] | Concentraciones altas merman el $O_2$ disuelto y alteran el pH sanguíneo del pez [1]. |

---

## 📷 Fotografía del equipo

<img src="/Imagenes/Integrantes/5.jpeg" width="1200"/>

---

## 👫 AYUDA A ESTAS PERSONAS A REGRESAR A SUS CASAS

| Foto | Nombre | Rol | Intereses |
|------|--------| --- | --------- |
| <img src="/Imagenes/Integrantes/JO.png" width="90"/> | **Karita John Kenneth** | **1/1/2026** | **Diseño de prototipos, hardware** |
| <img src="/Imagenes/Integrantes/RU.png" width="90"/> | **Cabrera Cermeno Ruben Andre** | **14/6/2024** | **Tecnología e implementación de programas** |
| <img src="/Imagenes/Integrantes/WI.png" width="90"/> | **Ccatamayo Vasquez Willy Simeon** | **28/1/2025** | **Programación, simulación** |
| <img src="/Imagenes/Integrantes/EB.png" width="90"/> | **Pauccara Huancara Eber** | **11/6/2023** | **Producción de documentos científicos y técnicos** |
| <img src="/Imagenes/Integrantes/VE.png" width="90"/> | **Quispitongo Leon Verenisse Mary**|  **28/7/2** | **Gestión ambiental, desarrollo comunitario** |

---
##  Fotografía esperada del producto
<img src="/Imagenes/Integrantes/100.png" width="600"/>

---

##  Referencias Bibliográficas

1. **Fondo Nacional de Desarrollo Pesquero (FONDEPES).** (2013). *Manual de Cultivo de Trucha en Ambientes Convencionales*. Ministerio de la Producción (PRODUCE), Dirección General de Capacitación y Desarrollo Técnico en Acuicultura. Lima, Perú. 87 pp.
2. **Organización de las Naciones Unidas (ONU).** (2015). *Transformar nuestro mundo: la Agenda 2030 para el Desarrollo Sostenible*. Resolución aprobada por la Asamblea General el 25 de septiembre de 2015 (A/RES/70/1).

---

<p align="center">
  <strong>🐟 FISHMON 365 — Monitoreo inteligente para una acuicultura sostenible</strong>
</p>
<p align="center">
  <sub>© 2026 - Universidad Peruana Cayetano Heredia</sub>
</p>
