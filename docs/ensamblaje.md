# Guía de materiales y montaje físico del circuito de LEDs

## Descripción breve

Para la elaboracion de este circuito se va a hacer en `Workwi`, puede revisar el ensamblaje en [aqui](https://wokwi.com/projects/476822154201427969)

Los LEDs están conectados a través de sus resistencias y comparten la referencia de tierra
del Arduino Nano.

> [!IMPORTANT]
> Esta guía se basa exclusivamente en los componentes y conexiones declarados en el archivo `.json` de Wokwi. No se detallan instrucciones paso a paso de ensamblaje, el diagrama de `Wokwi` debe utilizarse como referencia visual.

## Lista de materiales

| Cantidad | Material | Características |
|---:|---|---|
| 1 | Arduino Nano | Modelo `wokwi-arduino-nano` |
| 1 | Protoboard | Modelo `wokwi-breadboard` |
| 4 | LED | Color cian |
| 4 | Resistencia | `1000 Ω` (`1 kΩ`) |
| 9 | Cable jumper | Cantidad mínima deducida de las conexiones explícitas entre puntos de la protoboard |

### Cables de conexión

- Cuatro conexiones entre los nodos de las resistencias y las filas asociadas
  a los pines digitales del Arduino Nano.
- Cuatro conexiones que llevan los cátodos de los LEDs hacia la referencia
  común de tierra.
- Una conexión entre `GND` del Arduino Nano y la línea de tierra de la
  protoboard.

> [!NOTE]
> La cantidad de nueve cables es una estimación mínima para reproducir esas conexiones explícitas.

## Consideraciones importantes

### Polaridad de los LEDs

Cada LED tiene un ánodo (`A`) y un cátodo (`C`). La polaridad debe respetarse
en el montaje físico:

- `A`: terminal positivo del LED.
- `C`: terminal negativo del LED.

### Resistencias

El circuito utiliza cuatro resistencias de `1000 Ω`, una asociada a cada LED.

> [!WARNING]
> No sustituyas este valor sin recalcular previamente la corriente del LED.

Las resistencias limitan la corriente y ayudan a proteger tanto los LEDs como las salidas del Arduino Nano.

### Pines utilizados

Las conexiones del JSON utilizan los pines digitales `D2` a `D12` del Arduino
Nano, además de varias conexiones de referencia y alimentación del dispositivo.
Las conexiones asociadas directamente a la red de LEDs se encuentran en estas
filas de la protoboard:

| Elemento | Referencia en el JSON |
|---|---|
| Resistencia `r1` | `bb1:23t.e` a `bb1:29t.e` |
| Resistencia `r2` | `bb1:27t.d` a `bb1:33t.d` |
| Resistencia `r3` | `bb1:31t.e` a `bb1:37t.e` |
| Resistencia `r4` | `bb1:35t.d` a `bb1:41t.d` |
| LEDs | `led1`, `led2`, `led3` y `led4` |
| Tierra común | `nano:GND.1` y conexiones `tn` de la protoboard |

> El JSON muestra conexiones del Arduino a varios pines de la protoboard,
> incluidos `D2` a `D12`, `GND`, `RESET`, `D0`, `D1`, `3.3V`, `AREF`, `A0` a
> `A7`, `5V` y `VIN`. No todos ellos forman parte de la red de LEDs ni es
> posible deducir una función adicional para cada uno solo a partir del JSON.

### Alimentación

El JSON no especifica una fuente de alimentación, un cable USB ni una batería.
Para utilizar el circuito físico será necesario alimentar el Arduino Nano con
una fuente compatible, pero el método concreto de alimentación no puede
determinarse a partir del diseño.

> No conectes simultáneamente fuentes de alimentación incompatibles ni apliques
> tensión a un pin cuya función no hayas verificado en el modelo exacto de tu
> Arduino Nano.

### Comprobaciones y seguridad

- Comprueba que cada LED tenga una resistencia de `1 kΩ` asociada.
- Verifica la polaridad de todos los LEDs antes de conectar la alimentación.
- Confirma que la línea común de tierra esté conectada al pin `GND` del Nano.
- Revisa que ningún cable conecte accidentalmente `5V` directamente con `GND`.
- Comprueba la continuidad y la posición de los jumpers antes de energizar.
- Ten en cuenta que las filas y líneas de alimentación de una protoboard
  pueden estar separadas internamente según su modelo físico.
- Si el montaje físico difiere de la distribución de Wokwi, verifica nuevamente
  cada referencia de fila y cada conexión.

## Referencia para el ensamblaje

Consulta el siguiente enlace para visualizar cómo está ensamblado el circuito
en Wokwi: [aqui](https://wokwi.com/projects/476822154201427969)

> [!WARNING]
> El enlace de Wokwi debe utilizarse como referencia visual del montaje. Este
> documento resume los materiales y las precauciones, pero no sustituye la
> comprobación del circuito físico.
