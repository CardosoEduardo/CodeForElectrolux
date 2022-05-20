/*EDUARDO CARDOSO*//*DECLARAÇÃO DE ENUMS*/
enum btnStates {
  OFF,
  ON, 
  PROTECTED
};
/*********************/

/*DECLARAÇÃO DE VARIAVEIS GLOBAIS*/
uint8_t estado = OFF;
uint8_t btn = 0;
uint8_t startCont=0;
uint16_t cont=0;
/*********************************/

/*INTERRUPÇÃO A CADA 10mS*/
ISR(TIMER2_OVF_vect)
{
    TCNT2=100;// Reinicializa o registrador do Timer2
    stateMachine();
    if(startCont==1){
      cont++;
    }
}
/*************************/

void stateMachine(){
  switch (estado) 
  {
    case OFF:
      if(btn==1){
        estado=ON;
      }
      break;
    case ON:
      if(btn==0){
        estado=PROTECTED;
      }
      break;
    case PROTECTED:
      startCont=1;
      if(cont>=1000){
        cont=0;
        startCont=0;
        estado=OFF;
      }
      break;
    default:
      break;
  } 
}

void setup()
{
     pinMode(10,INPUT);

     TCCR2A = 0x00;   /*MODO NORMAL*/
     TCCR2B = 0x07;   /*PRESCALER 1:1024*/
     TCNT2  = 100;    /*10ms OVERFLOW*/
     TIMSK2 = 0x01;   /*HABILITA INTERRUPÇÃO DO TIMER 2*/
 
}

void loop()
{
  btn = digitalRead(10);/*LEITURA DO PINO DIGITAL 10, QUANDO PRECIONAVO ENVIA 5V PARA O PINO*/
} 
