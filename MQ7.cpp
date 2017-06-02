#include <Arduino.h>

#include <math.h>

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

float MQ7::getCorrectionFactor(float t, float h) {
  // Constants interpolatet from MQ7 datasheet,
  // humidity factors only good > 10°C
  // TODO: better fitting curve for lower humidity
  const float _a = 0.83169946;
  const float _b = 0.04596768;
  const float _c = -0.95765344;

  const float _d = 0.14;

  return _a+pow(M_E,_c+_b*(-t))-(h-0.33)*_d/0.52;

  // ax.plot(df.x, _a+np.exp(_c+_b*-df.x)-(rh-.33)*0.14/.52
}

float MQ7::getResistance() {
  const float _rload = 1.0;
  return ((2000.0/(float)read_adc()) - 1.)*_rload;
}
