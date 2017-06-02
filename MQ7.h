#pragma once

class MQ7 {
public:
  const int heater_high_pwm = 255;
  const int heater_low_pwm = 20;
  const int time_high = 60;
  const int time_low = 90;


  MQ7(const int heater_pin, const int adc_pin);
  void heater_high(void);
  void heater_low(void);
  void heater_off(void);
  int read_adc(void);
  float getCorrectionFactor(float t, float h);
  float getResistance(void);
private:
  int _heater;
  int _adc;
};
