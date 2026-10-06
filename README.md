# Proyecto Personal - Dispositivo de alerta para personas con discapacidad visual

Dispositivo electrónico programado en Arduino que detecta obstáculos cercanos mediante un sensor ultrasónico y alerta al usuario con pitidos sonoros de frecuencia variable, permitiendo mayor autonomía al desplazarse.

## Cómo funciona

El sensor ultrasónico HC-SR04 mide constantemente la distancia hacia el objeto más cercano, en un rango de 10 a 100 cm. Mientras más cerca está el obstáculo, mayor es la frecuencia de los pitidos emitidos por el altavoz, alertando al usuario con suficiente anticipación para reaccionar.

## Conexiones

|       Componente       |      Pin en Arduino    |
|------------------------|------------------------|
| HC-SR04 — Trigger      | Pin 2                  |
| HC-SR04 — Echo         | Pin 3                  |
| Altavoz / buzzer       | Pin 13                 |
| Salida analógica (PWM) | Pin 9                  |
| Pantalla LCD I2C       | SDA / SCL (vía Wire.h) |

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más detalles.

