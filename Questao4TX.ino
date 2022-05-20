/*EDUARDO CARDOSO*/
/*QUESTÃO 4 TX ELECTROLUX*/
const uint8_t bufferSize = 5;

uint8_t buffer[bufferSize];
int analog[3];

void setup(){
  while(!Serial);
  Serial.begin(9600);
  
  buffer[0] = 0x2E;/*DEFINE ENDEREÇO DO ESCRAVO*/
}

void loop(){

  for(uint8_t i=0; i<3 ; i++){
    analog[i]=analogRead(i);
  }
  for(uint8_t i=1; i<4 ; i++){
    buffer[i]=analog[i-1];
  }
  buffer[4] = checksum();

  Serial.write(buffer, bufferSize);
  
  delay(100);
}

/*REALIZAMOS UMA SOMA DE TODOS OS BYTES, EXCETO AQUELE QUE CORRESPONDE AO ORIGINAL
VALOR DA SOMA DE VERIFICAÇÃO. DEPOIS DE SOMAR, PRECISAMOS FAZER UM AND DO RESULTADO PARA UM VALOR DE BYTE*/
uint8_t checksum(){
  uint8_t result = 0;
  uint16_t sum = 0;
  
  for(uint8_t i = 0; i < (bufferSize - 1); i++){
    sum += buffer[i];
  }
  result = sum & 0xFF;

  return result;
}
