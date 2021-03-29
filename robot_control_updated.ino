//
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//#include "DHT.h"        
//#define DHTTYPE DHT11
//#define dht_dpin 2
//DHT dht(dht_dpin, DHTTYPE);

#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1
//#define analog A0

// Set these to run example.
#define FIREBASE_HOST "home-automation-7fc48.firebaseio.com" //do not change this
#define FIREBASE_AUTH "KKDcaIEcTWOHGvHHdtlemDkf1Q37alqqpUcwbSt2" //do not change this
#define WIFI_SSID "bensalcie"// change this to your wifi name
#define WIFI_PASSWORD "123456winner"// change this to your wifi password

//defining the pins


void setup() {
 // dht.begin();
  Serial.begin(9600);

  //we will use d0-d3, d8 as the driving pins for two wheel chessis 
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
      pinMode(D3, OUTPUT);
           // pinMode(D8, OUTPUT);
            //Signal when connected
                        //pinMode(D7, OUTPUT);
                        //pinMode(D6, OUTPUT);
  //pinMode(D8, OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
            digitalWrite(D6, HIGH); 
                digitalWrite(D7, LOW);  
                delay(100);
                 digitalWrite(D6, LOW); 
                
 

    delay(400);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
                   //digitalWrite(D6, LOW); 
                digitalWrite(D7, HIGH);

  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Be careful here!!! 
 // Firebase.setString("#########replace with your child name from app###/esp_1", "OFF");
 //Let initial state be OFF when the system is powered on,to prevent surges.
// To do, let the format be as follows, child name from app/esp_1... as it is below 
  
  Firebase.setString("LkuO1bCQBIRSXNZp1YjoMSPvRB32/robot_direction", "s");
  // Initialize  robot to stop
  //replace your child_name from the app here....

  
  

}
void loop() {

 // takeHumTemp();
  // set value

  //commands 

  //f-forward
  //b-backward
  //fr-forward right
  //fl-forward left
  //bl-backward left
  //br=backward right
  //s-stop

  //state stop


  //pin d8 is for siren, buzzer


  String res=Firebase.getString("LkuO1bCQBIRSXNZp1YjoMSPvRB32/robot_direction");
  
  if(res=="s")
  {
    digitalWrite(D0, LOW);  
    digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
      digitalWrite(D3, LOW);
                  //digitalWrite(D8, LOW);     


  
    }else if(res=="f")
  {
        //FORWARD STATES

      digitalWrite(D0, HIGH);  
    digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);   
                 // digitalWrite(D8, LOW);     
      
    }else if(res=="fr")
  {  
    
    digitalWrite(D0, LOW);  
    digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);
      delay(400);
                  digitalWrite(D3, LOW);
                              //digitalWrite(D8, LOW);     


    }else if(res=="fl")
  { 
    digitalWrite(D0, HIGH);  
        delay(400);
  digitalWrite(D0, LOW);  
    digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
      digitalWrite(D3, LOW);   
                 // digitalWrite(D8, LOW);     
 
    }else if(res=="br")
  {
        //BACKWARD STATES

     digitalWrite(D0, LOW);  
    digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);

 delay(400);
   digitalWrite(D2, LOW);

      digitalWrite(D3, LOW); 
                  //digitalWrite(D8, LOW);     
     
    }else  if(res=="bl")
  {
      digitalWrite(D0, LOW);  
    digitalWrite(D1, HIGH);
    delay(400);
        digitalWrite(D1, LOW);

  digitalWrite(D2, LOW);
      digitalWrite(D3, LOW); 
                  //digitalWrite(D8, LOW);     
        
    }else  if(res=="b")
  {
                digitalWrite(D8, HIGH); //siren

      digitalWrite(D0, LOW);  
    digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
      digitalWrite(D3, LOW); 

       //RING
        
   
   
    }

    

}

/*void takeHumTemp()
{
      float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  delay(200);
  
  
  }*/
