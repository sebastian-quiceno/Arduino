const int delayTime = 1000;

const int bit1 = 2;
const int bit2 = 3;
const int bit3 = 4;
const int bit4 = 5;

const int num_bits = 4;

int contador = 0;
const int maximo = 15;

bool binario[4];

void encenderLeds();
void convertirDecimalBinario(int numero);

void setup() {
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
}

void loop() {
  convertirDecimalBinario(contador);
  encenderLeds();

  delay(delayTime);

  contador++;
  if (contador > maximo) {
    contador = 0;
  }
}

void encenderLeds() {
  digitalWrite(bit1, binario[0] ? HIGH : LOW);
  digitalWrite(bit2, binario[1] ? HIGH : LOW);
  digitalWrite(bit3, binario[2] ? HIGH : LOW);
  digitalWrite(bit4, binario[3] ? HIGH : LOW);
}

void convertirDecimalBinario(int numero) {
  int i = 0;

  for (i = 0; i < num_bits; i++) {
    binario[i] = false;
  }

  i = 0;
  while (numero > 0 && i < num_bits) {
    binario[i] = (numero % 2) == 1;
    numero = numero / 2;
    i++;
  }
}