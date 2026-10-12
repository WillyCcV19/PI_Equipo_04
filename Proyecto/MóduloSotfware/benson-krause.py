import math

def benson_krause(t, p, c):      # Ecuaciones de Benson-Krausen
  do_0 = math.exp(                # Concentración en agua dulce
      -139.34411
      +1.575701*(10**5)/t
      -6.642308*(10**7)/(t**2)
      +1.243800*(10**10)/(t**3)
      -8.621949*(10**11)/(t**4))

  u = math.exp(                   # Coeficiente relacionado al oxígeno
      11.8591
      -3840.7/t
      -216961/(t**2))

  o = (9.75*(10**-4)              # Un coeficiente relacionado al oxígeno
      -1.426*(10**-5)/t
      +6.436*(10**-8)/(t**2))

  fp = ((p-u)*(1-(o*p))) / ((1-u)*(1-o))                # Compensación por presión

  s = 5.572e-4*(c) + 2.02e-9*(c**2)                     # conductividad a salinidad (partes por mil)

  fs = math.exp(-s*(0.017674 - 10.754/t + 2140.7/t**2)) # Compensación por salinidad

  return (do_0 * fp * fs)

# Comprobar tabla de oxígeno disuelto
p = 1                # Presión de un atmósfera
c = 0                # Conductancia específica (microsiemens / cm)
for t in range(46):  # Variar temperatura en kelvin
  print(t, round(benson_krause(273.15 + t, p, c), 2))
