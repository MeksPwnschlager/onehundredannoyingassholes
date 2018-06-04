#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

int pin = 4;
int pitch = 0;
volatile boolean f_wdt=1;

void setup_watchdog(int ii) {   
  byte bb;  
  int ww; 
  if (ii > 9 )
    ii=9;
  bb=ii & 7; 
  if (ii > 7) 
    bb|= (1<<5); 
  bb|= (1<<WDCE);
  ww=bb;
  MCUSR &= ~(1<<WDRF); 
  // start timed sequence  
  WDTCR |= (1<<WDCE) | (1<<WDE);  // set new watchdog timeout value
  WDTCR = bb;
  WDTCR |= _BV(WDIE);
}

void setup() {
  randomSeed(analogRead(0));
  pinMode(pin, OUTPUT);
  ADCSRA &= ~(1<<ADEN); //Disable ADC, saves ~230uA
  setup_watchdog(9); //Setup watchdog to go off after 8sec
   for(uint8_t i = 0; i < 1 + random(4); ++i) {
    uint16_t pitch = 30 + random(200);
    long len = 50000 + random(100000);
    for(long j = 0; j < len; j+=pitch) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pitch);
    digitalWrite(pin, LOW);
    delayMicroseconds(pitch);
    }
  }
}

void sleep8sec() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
  sleep_enable();
  sleep_mode(); //Go to sleep! Wake up 8sec later
}

void loop() {
  long ftmin = 100;
  
  //sleep ftmin * 8 seconds
  for(long i = 0; i < ftmin; ++i) {
    sleep8sec();
  }

  long interval = 1 + random(ftmin); 
  //sleep interval * 8 seconds
  for(long i = 0; i < interval; ++i) {
    sleep8sec();
  }
  
  for(uint8_t i = 0; i < 1 + random(4); ++i) {
    uint16_t pitch = 30 + random(200);
    long len = 50000 + random(100000);
    for(long j = 0; j < len; j+=pitch) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pitch);
    digitalWrite(pin, LOW);
    delayMicroseconds(pitch);
    }
  }
}

ISR(WDT_vect) {
  f_wdt=1;  // set global flag
}