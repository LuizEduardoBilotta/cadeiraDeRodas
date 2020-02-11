/*
  @PROJECT: CADEIRA DE RODAS MOTORIZADA
  @DATE: 24/09/2019
  @AUTHOR: LUIZ EDUARDO BILOTTA
  @EMAIL: LUIZEDUARDOBILOTTA@GMAIL.COM
*/

//DEFINIÇÃO DAS PINAGENS UTILIZADAS
#define joystick_vertical A0
#define joystick_horizontal A1

#define motor_esquerdo_RPWM 11
#define motor_esquerdo_LPWM 10

#define motor_direito_RPWM 9
#define motor_direito_LPWM 3

void setup() {

  //ATRIBUINDO FUNÇÃO DO PINO (ENTRADA OU SAÍDA)
  pinMode (joystick_vertical, INPUT);
  pinMode (joystick_horizontal, INPUT);

  pinMode (motor_esquerdo_RPWM, OUTPUT);
  pinMode (motor_esquerdo_LPWM, OUTPUT);

  pinMode (motor_direito_RPWM, OUTPUT);
  pinMode (motor_direito_LPWM, OUTPUT);

  //INICIALIZAÇÃO DO MONITORAMENTO PELO SERIAL MONITOR
  Serial.begin(9600);

}

void loop() {

  //LEITURA DE POSIÇÃO DO JOYSTICK NO EIXO VERTICAL
  int posicao_JV = analogRead(joystick_vertical);

  //LEITURA DE POSIÇÃO DO JOYSTICK NO EIXO HORIZONTAL
  int posicao_JH = analogRead(joystick_horizontal);


  //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO
  if ((posicao_JV < 510) || (posicao_JV > 530) || (posicao_JH < 479) || (posicao_JH > 490)) {


    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA FRENTE ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV > 530) && (posicao_JH > 477) && (posicao_JH < 490 )) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if (posicao_JV == 1023) {
        analogWrite(motor_esquerdo_RPWM, 255);
        analogWrite(motor_direito_RPWM, 255);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_RPWM, 255);
        analogWrite(motor_direito_RPWM, 255);

        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA TRÁS ATRUIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV < 510) && (posicao_JH > 477) && (posicao_JH < 490)) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if (posicao_JV == 0) {
        analogWrite(motor_esquerdo_LPWM, 255);
        analogWrite(motor_direito_LPWM, 255);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_LPWM, 127);
        analogWrite(motor_direito_LPWM, 127);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA ESQUERDA ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JH < 479) && (posicao_JV > 515) && (posicao_JV < 523 )) {

       //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if (posicao_JH == 0) {
        analogWrite(motor_esquerdo_RPWM, 127);
        analogWrite(motor_direito_RPWM, 255);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_RPWM, 63);
        analogWrite(motor_direito_RPWM, 127);
        
        Serial.print("motor esquerdo: 63");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA DIREITA ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JH > 490) && (posicao_JV > 510) && (posicao_JV < 530 )) {
      
      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if (posicao_JH == 1023) {
        analogWrite(motor_esquerdo_RPWM, 255);
        analogWrite(motor_direito_RPWM, 127);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_RPWM, 255);
        analogWrite(motor_direito_RPWM, 127);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA FRENTE E PARA ESQUERDA AO MESMO TEMPO ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV > 530) && (posicao_JH < 479)) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if ((posicao_JV == 1023) && (posicao_JH == 0)) {
        analogWrite(motor_esquerdo_RPWM, 127);
        analogWrite(motor_direito_RPWM, 255);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_RPWM, 63);
        analogWrite(motor_direito_RPWM, 127);
        
        Serial.print("motor esquerdo: 63");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA FRENTE E PARA DIREITA AO MESMO TEMPO ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV > 530) && (posicao_JH > 490)) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if ((posicao_JV == 1023) && (posicao_JH == 1023)) {
        analogWrite(motor_esquerdo_RPWM, 255);
        analogWrite(motor_direito_RPWM, 127);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_RPWM, 127);
        analogWrite(motor_direito_RPWM, 63);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 63");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA TRÁS E PARA ESQUERDA AO MESMO TEMPO ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV < 510) && (posicao_JH < 479)) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if ((posicao_JV == 0) && (posicao_JH == 0)) {
        analogWrite(motor_esquerdo_LPWM, 127);
        analogWrite(motor_direito_LPWM, 255);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 255");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_LPWM, 63);
        analogWrite(motor_direito_LPWM, 127);
        
        Serial.print("motor esquerdo: 63");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
    }

    //VERIFICA SE O JOYSTICK ESTÁ SENDO ACIONADO PARA TRÁS E PARA DIREITA AO MESMO TEMPO ATRIBUINDO TENSÃO AOS MOTORES
    if ((posicao_JV < 510) && (posicao_JH > 492)) {

      //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÁXIMA
      if ((posicao_JV == 0) && (posicao_JH == 1023)) {
        analogWrite(motor_esquerdo_LPWM, 255);
        analogWrite(motor_direito_LPWM, 127);
        
        Serial.print("motor esquerdo: 255");
        Serial.print("     ");
        Serial.println("motor direito: 127");
      }
      else { //VERIFICA SE O JOYSTICK ESTÁ NA VELOCIDADE MÉDIA
        analogWrite(motor_esquerdo_LPWM, 127);
        analogWrite(motor_direito_LPWM, 63);
        
        Serial.print("motor esquerdo: 127");
        Serial.print("     ");
        Serial.println("motor direito: 63");
      }
    }

  }
  else{
    analogWrite(motor_esquerdo_RPWM, 0);
    analogWrite(motor_esquerdo_LPWM, 0);
    analogWrite(motor_direito_RPWM, 0);
    analogWrite(motor_direito_LPWM, 0);
  }
}
