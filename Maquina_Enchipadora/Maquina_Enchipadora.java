import muvium.compatibility.arduino.Arduino; 
class Maquina_Enchipadora extends Arduino{//Automatically Added VBB Framework Code - do not remove
int M_adelante=12,M_atras=11,M_chipa=10,BM_adelante=9,BM_atras=8,B_inicio=7,cableUTP=6,cableRG6=5,S_adelante=4,S_atras=3;


public void setup() {
 pinMode(M_adelante,OUTPUT);//Motor para encajar y desencajar la chipa movimiento delantero 
 pinMode(M_atras,OUTPUT);   //Motor para encajar y desencajar la chipa movimiento trasero
 pinMode(M_chipa,OUTPUT);   //Motor para arranque de desenchipar
 pinMode(BM_adelante,INPUT);//Boton para mover hacia adelante chipa para encajar 
 pinMode(BM_atras,INPUT);   //Boton para mover hacia atras chipa para  desencajar
 pinMode(B_inicio,INPUT);   //Boton inicio para desenchipar cable 
 pinMode(S_adelante,INPUT); //Sensor adelante 
 pinMode(S_atras,INPUT);    //sensor atras 
}

public void loop() {
if(S_atras==true)
{
  digitalWrite(M_atras,LOW);
 }
 else if (BM_atras==true)
{
  digitalWrite(M_atras,true);
  digitalWrite(M_adelante,LOW);
}
if(S_adelante==true)
{
  digitalWrite(M_adelante,LOW);
  }
 else if (BM_adelante==true)
{
  digitalWrite(M_adelante,true);
  digitalWrite(M_atras,LOW);
}
if(S_adelante==true&&B_inicio==true)
{
  digitalWrite(M_chipa,true);
}
}

}
