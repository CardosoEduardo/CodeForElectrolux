/*EDUARDO CARDOSO*/
/*QUESTÃO 4 RX ELECTROLUX*/
const uint8_t address = 0x2E;
const uint8_t bufferSize = 5;

uint8_t buffer[bufferSize];
uint8_t readCounter;
uint8_t isAddress;

/*FLAG QUE REINICIA O CONTADOR QUANDO ENCONTRAMOS O BYTE DE ENDEREÇO PELA PRIMEIRA VEZ*/
uint8_t flagFirst; 

void doAnithingWithIT(uint8_t output,uint8_t value){
  switch (output) 
  {
    case 1:
    if(value==1){
      digitalWrite(9, HIGH);
    }else{
      digitalWrite(9, LOW);
    }
      break;
    case 2:
    if(value==1){
      digitalWrite(10, HIGH);
    }else{
      digitalWrite(10, LOW);
    }
      break;
    case 3:
    if(value==1){
      digitalWrite(11, HIGH);
    }else{
      digitalWrite(11, LOW);
    }
      break;
    default:
      break;
  } 
  
}
void setup(){
  while(!Serial);
  Serial.begin(9600);
  
  readCounter = 0;
  isAddress = 0;
  flagFirst = 0;
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){

  if(Serial.available() > 0){
    uint8_t firstData = Serial.read();
    
    /*VERIFICA SE O ENDEREÇO FOI ENCONTRADO*/
    if(firstData == address){
      if(!flagFirst){
        isAddress = 1;
        readCounter = 0;
        flagFirst = 1;
      }
    }
    
    /*ARMAZENAR BYTE RECEBIDO, AUMENTAR READCOUNTER*/
    buffer[readCounter] = firstData;
    readCounter++;
    
    /*ESTOURO ANTERIOR, TEMOS QUE REINICIAR READCOUNTER*/
    if(readCounter >= bufferSize){
      readCounter = 0;
      
      /*SE O ENDEREÇO FOI ENCONTRADO*/
      if(isAddress){
        /*PEGA O VALOR DO CHECKSUM DO ÚLTIMO VALOR DO BUFFER, DE ACORDO COM O PROTOCOLO DEFINIDO*/
        uint8_t checksumValue = buffer[4];
        
        
        if(verifyChecksum(checksumValue)){
          /*CHAMA CADA FUNÇÃO DEPENDENDO DO VALOR DE COMANDO*/
          if(buffer[1]<127){doAnithingWithIT(1,0);            
          }else if(buffer[1]>127){doAnithingWithIT(1,1);}

          if(buffer[2]<127){doAnithingWithIT(2,0);            
          }else if(buffer[2]>127){doAnithingWithIT(2,1);}

          if(buffer[3]<127){doAnithingWithIT(3,0);            
          }else if(buffer[3]>127){doAnithingWithIT(3,1);}
          
        }
        isAddress = 0;
        flagFirst = 0;
      }
    }
  }
}

uint8_t verifyChecksum(uint8_t originalResult){
  uint8_t result = 0;
  uint16_t sum = 0;
  
  for(uint8_t i = 0; i < (bufferSize - 1); i++){
    sum += buffer[i];
  }
  result = sum & 0xFF;
  
  if(originalResult == result){
     return 1;
  }else{
     return 0;
  }
}
