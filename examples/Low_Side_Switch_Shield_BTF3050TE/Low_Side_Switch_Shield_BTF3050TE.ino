/*
 * This example lets you test the Infineon BTF3050TE Low-Side Switch Shield for Arduino.
 * 
 * The DIP-Switch turns the corresponding BTF3050TE on or off. 
 * The push buttons S_1, S_2 and S_3 increase or decrease the duty cycle of the associated BTF3050TE depending on 
 * LED_0. If LED_0 emits light, the duty cycle will be increased once S_1, S_2 or S_3 is pressed. If LED_0 does not 
 * emit light, the duty cycle will be decreased. Once S_0 is pushed, LED_0 toggles. 
 * If a fault feedback is present, LED_1, LED_2 or LED_3 will shine to show a fault feedback on the corresponding 
 * BTF3050TE. S_4 resets all fault feedbacks at once. 
 * 
 * NOTE: For use with Arduino Uno, S_I cannot be used anymore.
 */


// Pin definition

#define LED_0 4
#define LED_1 A4
#define LED_2 2
#define LED_3 10
#define ONOFF_1 A1
#define ONOFF_2 A2
#define ONOFF_3 A3
#define PWM_1 6
#define PWM_2 11
#define PWM_3 9
#define S_0 8
#define S_1 5
#define S_2 3
#define S_3 7
#define S_4 A0
#define SRP_1 13
#define SRP_2 12 
#define SRP_3 A5

/*  Initialization of global variables
    Change these parameters to modify frequency and initial duty cycle*/
int input;
int duty_cycle[3] = { 204, 204, 204}; // Variables, containing the desired initial duty cycle value of each PWM in (1/2.55)%
int freq_divisor[3] = { 1, 1, 1 };        // Frequeny of PWMs in 62500Hz/freq[0], 31250Hz/freq[1], 31250Hz/freq[2]
                                        // Available values for freq_divisor[0] and freq_divisor[2] are 1,8,64,256,1024
                                        // Available values for freq_divisor[1] are 1,8,32,64,128,256,1024
int res = 10;    // Debounce cycles


bool debounce(int pin) { // debounces digitally the tactile push button
  if(digitalRead(pin)) { // INPUT: pin to debounce
    for(int32_t i; i<160000;i++) {}
    if(digitalRead(pin)) {
      while(digitalRead(pin)) {}
      return true;
    }
  }
  return false;
}

void increaseDutyCycle(int number) { // increases the duty cycle by on discrete step equal to 2.55%
  duty_cycle[number]+=res;           // INPUT: Number of PWM
  
  if(duty_cycle[number] > 255)
    duty_cycle[number] = 255;

}

void decreaseDutyCycle(int number) { // decreases the duty cycle by on discrete step equal to 2.55%
  duty_cycle[number]-=res;           // INPUT: Number of PWM
  
  if(duty_cycle[number] < 0)
    duty_cycle[number] = 0;

}

void setPwmFrequency (int pin, int divisor) { // sets PWM frequency
  byte divisor_byte;                          // INPUT: Number of PWM, divisor
                                              // refer to l.25-28 or arduino homepage for further information about the divisor

  if(pin == 5 || pin == 6 || pin == 9 || pin == 10){
    switch(divisor){
      case 1:
        divisor_byte = 0x01;
        break;
      case 8:
        divisor_byte = 0x02;
        break;
      case 64:
        divisor_byte = 0x03;
        break;
      case 256:
        divisor_byte = 0x04;
        break;
      case 1024:
        divisor_byte = 0x05;
        break;
      default:
        return;
    }
    if(pin == 5 || pin == 6){
      TCCR0B = TCCR0B & 0b11111000 | divisor_byte;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | divisor_byte;
    }
  } else if(pin == 3 || pin == 11){
    switch(divisor){
      case 1:
        divisor_byte = 0x01;
        break;
      case 8:
        divisor_byte = 0x02;
        break;
      case 32:
        divisor_byte = 0x03;
        break;
      case 64:
        divisor_byte = 0x04;
        break;
      case 128:
        divisor_byte = 0x05;
        break;
      case 256:
        divisor_byte = 0x06;
        break;
      case 1024:
        divisor_byte = 0x7;
        break;
      default:
        return;
    }
    TCCR2B = TCCR2B & 0b11111000 | divisor_byte;
  }
}

void setup() {
  // Pin assignment and setting PWM frequency

  
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(ONOFF_1, INPUT);
  pinMode(ONOFF_2, INPUT);
  pinMode(ONOFF_3, INPUT);
  pinMode(S_0, INPUT);
  pinMode(S_1, INPUT);
  pinMode(S_2, INPUT);
  pinMode(S_3, INPUT);
  pinMode(S_4, INPUT);
  pinMode(SRP_1, INPUT);
  pinMode(SRP_2, INPUT);
  pinMode(SRP_3, INPUT);
  
  setPwmFrequency(PWM_1, freq_divisor[0] );
  setPwmFrequency(PWM_2, freq_divisor[1] );
  setPwmFrequency(PWM_3, freq_divisor[2] );

}



void loop() {
  
  if(debounce(S_0)) // Toggles LED0; LED0 indicates whether the duty cycle of one of the PWMs will increase or decrease, when pressing S1, S2 or S3
    digitalWrite( LED_0, !digitalRead(LED_0));


  digitalWrite(LED_1, digitalRead(SRP_1)); // LED1, LED2 and LED3 will emit light once a fault feedback is present on one corresponsing Low Side Switch
  digitalWrite(LED_2, digitalRead(SRP_2));
  digitalWrite(LED_3, digitalRead(SRP_3));
  
  if(debounce(S_1)){            // S1, S2 and S3 will change the duty cycle of the corresponding Low Side Switch
    if(digitalRead(LED_0)) {
      increaseDutyCycle(0);
    } else {
      decreaseDutyCycle(0);
    }
  }
    
  if(debounce(S_2))
    if(digitalRead(LED_0)) {
      increaseDutyCycle(1);
    } else {
      decreaseDutyCycle(1);
    }  

  if(debounce(S_3))
    if(digitalRead(LED_0)) {
      increaseDutyCycle(2);
    } else {
      decreaseDutyCycle(2);
    }  
    
  if(debounce(S_4)) {       // S4 resets the Fault Feedback; SRP1, SRP2 and SRP3 will be pulled to ground and thus reset the Faul Feedback, afterwards the pins will be set to input again.
    pinMode(SRP_1, OUTPUT); // For further information regarded the Fault Feedback, please refer to the datasheet of the BTF3050TE
    pinMode(SRP_2, OUTPUT);
    pinMode(SRP_3, OUTPUT);
    digitalWrite(SRP_1, LOW);
    digitalWrite(SRP_2, LOW);
    digitalWrite(SRP_3, LOW);
    for(int32_t i; i<160000;i++) {}
    pinMode(SRP_1, INPUT);
    pinMode(SRP_2, INPUT);
    pinMode(SRP_3, INPUT);
  }


  if(digitalRead(ONOFF_1)) {  // The corresponding Low Side Switch will turn on/off depening on the DIP-Switch channels.
    analogWrite(PWM_1, duty_cycle[0]);    
  } else {
    analogWrite(PWM_1, 0);
  }
  
  if(digitalRead(ONOFF_2)) {
    analogWrite(PWM_2, duty_cycle[1]);    
  } else {
    analogWrite(PWM_2, 0);
  }
  
  
  if(digitalRead(ONOFF_3)) {
    analogWrite(PWM_3, duty_cycle[2]);    
  } else {
    analogWrite(PWM_3, 0);
  }
  
 


}
