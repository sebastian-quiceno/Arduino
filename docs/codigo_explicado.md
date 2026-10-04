# Explicación del código de Arduino

Este proyecto utiliza cuatro `LEDs` para representar números decimales en formato
binario (cuatro bits). El programa muestra los valores del `0` al `15`, espera un segundo
entre cada valor y cuando llega al 15 vuelve a comenzar.

- Ver [Codigo_comentado](codigoComentado.ino)  

- Ver [Codigo_sin_comentar](codigo.ino)  


> [!NOTE]
> Con cuatro bits es posible representar 16 valores diferentes:
> desde `0000` (0) hasta `1111` (15).

## 1. Variables y constantes

```c
const int delayTime = 1000;

const int bit1 = 2;
const int bit2 = 3;
const int bit3 = 4;
const int bit4 = 5;

const int num_bits = 4;

int contador = 0;
const int maximo = 15;

bool binario[4];
```

- `delayTime` indica cuánto tiempo permanece visible cada número. Su valor es `1000` milisegundos, es decir, un segundo.

- `bit1`, `bit2`, `bit3` y `bit4` representan los pines digitales donde están conectados los LEDs.

- `num_bits` representa el numero de bits que tiene el proyecto

- `contador` almacena el número que se está mostrando actualmente.

- `maximo` establece el último número de la secuencia. El valor máximo es `15` porque cuatro bits permiten representar hasta `1111`.

- El arreglo `binario` almacena los cuatro bits del número actual. La posición `0` contiene el bit menos significativo.

## 2. Inicializacion de funciones

```c
void encenderLeds();
void convertirDecimalBinario(int numero);
```

- Estas líneas anuncian las funciones antes de que sean utilizadas. De esta forma, el compilador conoce sus nombres y parámetros desde el principio.

## 3. Configuración inicial: `setup()`

```c
void setup() {
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
}
```

- `setup()` se ejecuta una sola vez cuando Arduino se enciende o se reinicia.
- `pinMode(..., OUTPUT)` configura cada pin como salida para que pueda controlar el estado de un LED.

## 4. Funcionamiento principal: `loop()`

```c
void loop() {
  convertirDecimalBinario(contador);
  encenderLeds();

  delay(delayTime);

  contador++;
  if (contador > maximo) {
    contador = 0;
  }
}
```

`loop()` se repite continuamente mientras Arduino permanezca encendido.

El orden de ejecución es el siguiente:

1. Se convierte `contador` de decimal a binario.
2. Se encienden o apagan los LEDs según los bits obtenidos.
3. El programa espera un segundo.
4. Se incrementa el contador.
5. Si el contador supera `15`, vuelve a `0`.

## 5. Control de los LEDs

```cpp
void encenderLeds() {
  digitalWrite(bit1, binario[0] ? HIGH : LOW);
  digitalWrite(bit2, binario[1] ? HIGH : LOW);
  digitalWrite(bit3, binario[2] ? HIGH : LOW);
  digitalWrite(bit4, binario[3] ? HIGH : LOW);
}
```

- `digitalWrite()` establece el estado de un pin digital. `HIGH` enciende el LED y `LOW` lo apaga.

- La expresión `condicion ? valorSiVerdadero : valorSiFalso` es un operador

- ternario. En este caso, si el bit es `true`, se escribe `HIGH`; de lo

- contrario, se escribe `LOW`.

La relación entre los LEDs y los bits es:

| LED | Pin | Posición | Valor binario |
|---|---:|---:|---:|
| `bit1` | 2 | 0 | 1 |
| `bit2` | 3 | 1 | 2 |
| `bit3` | 4 | 2 | 4 |
| `bit4` | 5 | 3 | 8 |

- El primer LED representa el valor `1`, el segundo `2`, el tercero `4` y el

- cuarto `8`. Cada posición representa una potencia de dos.

## 6. Conversión de decimal a binario

```c
void convertirDecimalBinario(int numero) {
  int i = 0;

  for (i = 0; i < 4; i++) {
    binario[i] = false;
  }

  i = 0;
  while (numero > 0 && i < 4) {
    binario[i] = (numero % 2) == 1;
    numero = numero / 2;
    i++;
  }
}
```

La función utiliza divisiones sucesivas entre `2`:

1. `numero % 2` obtiene el residuo de la división entre `2`.
2. El residuo siempre es `0` o `1`.
3. Ese resultado se guarda en el bit actual.
4. `numero / 2` obtiene el siguiente cociente.
5. El proceso continúa hasta que el número llega a `0`.

- Primero se limpian las cuatro posiciones del arreglo. Esto es importante porque los bits que valen `0` también deben apagar sus LEDs.

- La condición `i < 4` evita escribir fuera del arreglo `binario`, que solo tiene cuatro posiciones.

### Ejemplo con el número 9

El número decimal `9` se representa como `1001`:

```text
9 % 2 = 1  -> binario[0] = true
4 % 2 = 0  -> binario[1] = false
2 % 2 = 0  -> binario[2] = false
1 % 2 = 1  -> binario[3] = true
```

Por tanto:

```text
binario[0] = 1
binario[1] = 0
binario[2] = 0
binario[3] = 1
```

- Como el arreglo se guarda desde el bit menos significativo, sus posiciones contienen `1, 0, 0, 1`, mientras que normalmente escribimos el número como `1001` desde el bit más significativo.

## 7. Ejemplos de la secuencia

| Decimal | Binario | LEDs encendidos |
|---:|:---:|:---|
| 0 | `0000` | Ninguno |
| 1 | `0001` | `bit1` |
| 2 | `0010` | `bit2` |
| 3 | `0011` | `bit1`, `bit2` |
| 8 | `1000` | `bit4` |
| 9 | `1001` | `bit4`, `bit1` |
| 15 | `1111` | Los cuatro LEDs |

- La tabla muestra los bits en el orden habitual, de izquierda a derecha: **del bit más significativo al menos significativo**.

## 8. Buenas practicas aplicadas

El código incluye varias decisiones que ayudan a mantenerlo claro y seguro:

- Las configuraciones que no cambian se declararon con `const`.
- La conversión utiliza el parámetro `numero` recibido por la función.
- El arreglo se limpia antes de cada conversión.
- Se limita el procesamiento a cuatro bits.
- Los nombres de las funciones indican claramente qué tarea realiza cada una.
- El archivo usa la extensión `.ino`, adecuada para un sketch de Arduino.

> [!IMPORTANT]
> Se pueden agregar mas LEDs para tener como `maximo` a un valor mayor que `15`, pero será necesario agregar más LEDs y ampliar el arreglo `binario` para representar los bits adicionales.
