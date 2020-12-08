#define T_NC 0
#define T_DO 262
#define T_RE 294
#define T_MI 330
#define T_FA 349
#define T_SO 392
#define T_RA 440
#define T_SI 494
#define T_DO2 523
#define T_RE2 587
#define T_MI2 659
#define T_FA2 699

#define SPEAKER 13 //set output speaker to 13
#define LED_ST 12 //set status led to 12
#define SW_1 2
#define SW_2 3
#define SW_3 4
#define SW_4 5

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

void setup()
{
  Serial.begin(115200);

  pinMode(LED_ST,OUTPUT);
  pinMode(SW_1,INPUT);
  pinMode(SW_2,INPUT); 
  pinMode(SW_3,INPUT);
  pinMode(SW_4,INPUT);
}
void loop() {
  digitalWrite(LED_ST,HIGH);
  if (digitalRead(SW_1) == HIGH)
  { 
    digitalWrite(LED_ST,LOW);
    sound1();
  }
  if (digitalRead(SW_2) == HIGH)
  {
    digitalWrite(LED_ST,LOW);
    sound2();
  }
  if (digitalRead(SW_3) == HIGH)
  {
    digitalWrite(LED_ST,LOW);
    sound3();
  }
  if (digitalRead(SW_4) == HIGH)
  {
    digitalWrite(LED_ST,LOW);
    sound4();
  }
  sndSerial();
}

int buf = 0;
void sndSerial()
{
  if(Serial.available() >0)
  {
    buf = Serial.read();

    tone_d(buf*4,300);
  }
}

void tone_d(unsigned int frequency,unsigned long duration)
{
  //write frequency and duration to serial
  Serial.print(frequency);
  Serial.print(" ");
  Serial.print(duration);
  Serial.print("\r\n");

  //out to speaker
  tone(SPEAKER,frequency,duration);
  delay(duration);
}



void sound1()
{
  const int sdata[][2] =
  {
    {T_DO,300},
    {T_RE,300},
    {T_MI,300},
    {T_FA,300},
    {T_SO,300},
    {T_RA,300},
    {T_SI,300},
    {T_DO2,300},
    {T_RE2,300},
    {T_MI2,300},
    {T_FA2,300}
  };

  for(int i=0;i<ARRAY_LENGTH(sdata);i++)
  {
    tone_d(sdata[i][0],sdata[i][1]);
  }
}

void sound2()
{
  const int sdata[][2] =
  {
  };
  

  for(int i=0;i<ARRAY_LENGTH(sdata);i++)
  {
    tone_d(sdata[i][0],sdata[i][1]);
  }
}
void sound3()
{
  const int sdata[][2] =
  {
  };

  for(int i=0;i<ARRAY_LENGTH(sdata);i++)
  {
    tone_d(sdata[i][0],sdata[i][1]);
  }
}

void sound4()
{
  const int sdata [][2] =
  {
  };
  for(int i=0;i<ARRAY_LENGTH(sdata);i++)
  {
    tone_d(sdata[i][0],sdata[i][1]);
  }
}
