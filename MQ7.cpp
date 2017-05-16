#include <Arduino.h>

#include "MQ7.h"

MQ7::MQ7(const int heater_pin, const int adc_pin) {
  _heater = heater_pin;
  _adc = adc_pin;

  pinMode(_heater, OUTPUT);
  digitalWrite(_heater, LOW);
}

void MQ7::heater_high() {
  analogWrite(_heater, heater_high_pwm);
}

void MQ7::heater_low() {
  analogWrite(_heater, heater_low_pwm);
}

void MQ7::heater_off() {
  digitalWrite(_heater, LOW);
}

int MQ7::read_adc() {
  int adc = analogRead(_adc);
  return adc;
}
