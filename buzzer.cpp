#include <Arduino.h>
#include <stdint.h>
#include "buzzer.h"

void play(uint8_t pin, uint16_t frequencia, uint8_t resolucao) {
  ledcAttach(pin, frequencia, resolucao);

  // Toca buzzer com 100% do volume
  ledcWrite(pin, 256);

  delay(300);

  // Desliga o buzzer
  ledcWrite(pin, 0);
}
