int M_adelante = 12, M_atras = 11, M_chipa = 10, BM_adelante = 9, BM_atras = 8, B_inicio = 7, Chipa_155 = 6, Chipa_55 = 5, S_adelante = 4, S_atras = 3,paro=2 ;
int entrada = 13,  cont = 0;
boolean a=0, b=0 ;
int sensor = 0;
void setup() {
  pinMode(M_adelante, OUTPUT); //Motor para encajar y desencajar la chipa movimiento delantero
  pinMode(M_atras, OUTPUT);  //Motor para encajar y desencajar la chipa movimiento trasero
  pinMode(M_chipa, OUTPUT);  //Motor para arranque de desenchipar
  pinMode(BM_adelante, INPUT); //Boton para mover hacia adelante chipa para encajar
  pinMode(BM_atras, INPUT);  //Boton para mover hacia atras chipa para  desencajar
  pinMode(B_inicio, INPUT);  //Boton inicio para desenchipar cable
  pinMode(S_adelante, INPUT); //Sensor adelante
  pinMode(S_atras, INPUT);   //sensor atras
  pinMode(Chipa_155, INPUT);//paro detiene la maquina
  pinMode(Chipa_55, INPUT);//paro chipa
  Serial.begin(9600);
}

void loop() {
  digitalWrite(M_adelante, LOW);
  digitalWrite(M_atras, LOW);
  digitalWrite(M_chipa, LOW);

  if (digitalRead(BM_adelante) == HIGH && digitalRead(BM_atras) == HIGH)
  {
    digitalWrite(M_adelante, LOW);
    digitalWrite(M_atras, LOW);
    digitalWrite(M_chipa, LOW);

  }
  else
  {
    if (digitalRead(BM_atras) == HIGH && digitalRead(S_atras) == LOW)
    {
      digitalWrite(M_adelante, LOW);
      digitalWrite(M_atras, HIGH);
      digitalWrite(M_chipa, LOW);
      //delay (500);
    }
  }
  if (digitalRead(S_atras) == HIGH)
  {
    digitalWrite(M_atras, LOW);
  }
  if (digitalRead(BM_adelante) == HIGH && digitalRead(S_adelante) == LOW)
  {
    digitalWrite(M_adelante, HIGH);
    digitalWrite(M_atras, LOW);
  }
  if (digitalRead(S_adelante) == HIGH)
  {
    digitalWrite(M_adelante, LOW);
  }
        
   if (digitalRead(Chipa_155) == HIGH)
  {
    a =1 ;
    b =0;
  }
  if (digitalRead(Chipa_55) == HIGH)
  {
    b =1;
    a =0;
  }
  while (digitalRead(B_inicio) == HIGH && digitalRead(S_adelante) == HIGH)
  {
    if (a =1) {
      while (cont <= 150) {
        sensor = digitalRead(entrada);
        digitalWrite(M_chipa, HIGH);
        if (sensor == HIGH) {
          cont++;
          while (sensor == HIGH) {
            sensor = digitalRead(entrada);
          }
          Serial.println(cont);
        }
      }
   }
  else if (b =1) {
      while (cont <= 55) {
        sensor = digitalRead(entrada);
        digitalWrite(M_chipa, HIGH);
        if (sensor == HIGH) {
          cont++;
          while (sensor == HIGH) {
            sensor = digitalRead(entrada);
          }
         Serial.println(cont);
        }
      }
     }
  }
      if(digitalRead(paro) == HIGH)
{
    goto a;
    goto b;

}
}
