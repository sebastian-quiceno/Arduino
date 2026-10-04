// Tiempo que cada valor permanece visible en los LEDs, en milisegundos.
const int delayTime = 1000;

// Pines conectados a los LEDs. bit1 representa el bit menos significativo.
const int bit1 = 2;
const int bit2 = 3;
const int bit3 = 4;
const int bit4 = 5;

// Numero de bits
const int num_bits = 4;

// Valor que se mostrará en la siguiente iteración.
int contador = 0;
const int maximo = 15;

// Bits del número actual, desde el menos significativo hasta el más significativo.
bool binario[4];

// Prototipos para declarar las funciones antes de utilizarlas.
void encenderLeds();
void convertirDecimalBinario(int numero);

void setup() {
  // Configura los pines de los LEDs como salidas digitales.
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
}

void loop() {
  // Convierte el valor actual y lo muestra como un número binario.
  convertirDecimalBinario(contador);
  encenderLeds();

  // Espera antes de pasar al siguiente valor.
  delay(delayTime);

  contador++;
  if (contador > maximo) {
    // Reinicia la cuenta para volver a mostrar la secuencia desde cero.
    contador = 0;
  }
}

// Enciende o apaga cada LED según el valor de su bit correspondiente.
void encenderLeds() {
  digitalWrite(bit1, binario[0] ? HIGH : LOW);
  digitalWrite(bit2, binario[1] ? HIGH : LOW);
  digitalWrite(bit3, binario[2] ? HIGH : LOW);
  digitalWrite(bit4, binario[3] ? HIGH : LOW);
}

// Convierte un número decimal a binario y guarda sus cuatro bits en binario[].
// El residuo de dividir entre 2 siempre corresponde al bit menos significativo
// disponible en cada paso.
void convertirDecimalBinario(int numero) {
  int i = 0;

  // Limpia los cuatro bits para que los ceros también se reflejen correctamente.
  for (i = 0; i < num_bits; i++) {
    binario[i] = false;
  }

  // Solo se procesan cuatro bits porque la secuencia va de 0 a 15.
  i = 0;
  while (numero > 0 && i < num_bits) {
    binario[i] = (numero % 2) == 1;
    numero = numero / 2;
    i++;
  }
}