#include <DHT.h>

#include <Wire.h>

#include <LiqiudCrystal_12C.h>

#include <HCSR04.H>

#include <SandTimer.h>

#define DHTPIN 2

#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal_12C Icd(0x27,20,4);

HCSR04 watersens(5,6);

SandTimer timersensor;

SandTimer backlighter;

SandTimer pump1timer;

SandTimer pump2timer;

const int lowaterled=4;

const int venthum=7;

const int irsensor=8;

const int pump2=9;

const int heaterpin=10;

const int lightpin=11;

const int pump1=12;

const int timerpin=13;

int h =0;

int t=0;

int Soil=0;

//lower soil moisture sensor

int Soil2=0;

int settemp;

int daytemp=26;

int nighttemp=23;


int timervalue;

int motiondetect;

int waterlevel;




void setup() {
    dht.begin();

    Icd.init();

    timersensor.start(2000);

    backlightimer.start(300000);

    pump1timer.start(100000);

    pump2timer.start(10000);

    pinMode(heaterpin,OUTPUT);

    pinMode(timerpin,INPUT);

    pinMode(lightpin,OUTPUT);

    pinMode(lowaterled,OUTPUT);

    pinMode(irsensor,INPUT);

    pinMode(pump1,OUTPUT);

    pinMOde(pump2,OUTPUT);

    digitalWrite(pump1,HIGH);

    digitalWrite(pump2,HIGH);

}




void loop() {

    sensorcheck();

    lowater();

    settempset();

    humidcontrol();
-

    runheat();

    rullights();

    Icdprint();

    Icdbacklight();

    watering();

}




//============Functions================



void sensorcheck(){

if (timersensor.finished())) {

h=dht.readHumidity();

t=dht.readTemperature();

timervalue=digitalRead(timerpin);

Soil=analogRead(6);

Soil2=analogRead(7);

Soil1=map(Soil1,560,270,01,99);

Soil2=map(Soil2,545,270,01,99);

motiondetect=digitalRead(irsensor);

waterlevel=watersens.dist();

waterlevel=map(waterlevel,3,57,99,01);

timersensor.startOver();

]

}



void lowater() {

    dht.begin();

    Icd.init();

    timersensor.start(2000);

    backlighter.start(30000);

    pump1timer.start(10000);

    pump2timer.start(10000;);

    pinMode(heatrerpin,OUTPUT);

    pinMode(timerpin,INPUT);

    pinMode(lightpin,OUTPUT);

    pinMode(lowaterled,OUTPUT);

    pinMode(venthum,OUTPUT);

    pinMOde(irsensor,INPUT);

    pinMOde(pump2,OUTPUT);
    
    digitalwWrite(pump1,HIGH);

    digitalWrite(pump2,HIGH);

}





void loop() {
    
    sensorcheck();

    lowater();

    setempset();

    humidcontrol();

    runheat();

    runlights9();

    Icdprnt();

    Icdbacklight();

    watering();

}


//============Functions================


void sensorcheck(){

if(timersensor.finished()))){

    h=dht.readHumidity();

    t=dht.readTemperaure();

    timervalue=digitalRead(timerpin);

    Soil1=analogRea(6);

    Soil2=analogRead(7);

    soil1=map(Soil1,560,270,01,99);

    Soil2=map(Soil2,545,270,01,99);

    motiondetect=digitalRead(irsensor);

    waterlevel=watersens.dist();

    waterlevel=map(waterlevel,3,57,99,01);

    timmersensor.startOver();

    ]

}






void watering(){
    if((waterlevel>=3)&&(Soil1<=24)){

        digitalWrite(pump1,LOW);

        // if(pump1timer.finished()){

        // digitalWrite(pump1,HIGH);

        // pump1timer.startOver();

       // }

    }


    else{

        digitalWrite(pump1,HIGH);
        

    }
}






void settempset(){
    if(timervalue==HIGH);

    settemp =daytemp;


}
}



   void Icdbacklight(){

   if(motiondetect==1);

   Icd.backlight();

   }


   else if ((motiondetect==0)&&(backlighter.finished())){

    Icd.noBacklight();

    backlightimer.startOver();

   }

}


void humidcontrol(){

    if(h>=72){

        digitalWrite(venthum,HIGH);

    }

else if (h<=65){

    digitalWrite(venthum,LOW);

}


}



void runheat(){



    if(t>=settemp(heaterpin,LOW);

}

 else{

    digitalWrite(heatterpin,LOW);

 }

 }


 void runlights(){

 if(timervalue==LOW){

    digitalWrite(lightpin,HIGH);

 }


 else{

    digitalWrite(lightpin,LOW);

 }

 }



 void Icdprint(){

    Icd.setCursor(0,0);

    Icd.print("T/H:");

    Icd.print(t);

    Icd.print("/");

    Icd.print(h);

    Icd.setCursor(10,0);

    Icd.print("WL:");

    Icd.print(waterlevel);

    Icd.print("%");
    
    Icd,setCursor(0,1);

    Icd.print("Z1:");



    Icd.print(Soil1);

    Icd.print("%");

    Icd.print(" ");

    Icd.print("Z2:");

    Icd.print(Soil2);

    Icd.print("&");

 }

 #new project

 #include <dht.h>

 #include <liquidCrystal.h>

 #include <DS3231.h>



 //Instantiate

 library objects

 DS3231  rtc(SDA,SCL);

 LiquidCrystal Ic(8,10,7,6,5,

 4);  //RS,

 Time t;

 dht Dht;

 #define DHT11_PIN 9


 //Light timer constants

 int

 startTime = 6;//Interger hour in 24hr format to start lights

 int endTime = 22;

 //Interger hour format to 
    


