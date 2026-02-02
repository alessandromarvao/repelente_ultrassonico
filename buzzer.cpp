#include <Arduino.h>
#include "esp_sleep.h"
#include <stdint.h>
#include "buzzer.h"

/**
* Toca o buzzer
*/
void play_buzzer(uint8_t pin, uint8_t frequencia) {

  // Configura o buzzer para tocar a 25 kHz
  ledcAttach(pin, frequencia, PWM_RES);

  // Toca buzzer com 50% do volume
  ledcWrite(pin, 128);

  vTaskDelay(pdMS_TO_TICKS(300));

  // Desliga o buzzer
  ledcWrite(pin, 0);

  // Pausa de 100 ms
  vTaskDelay(pdMS_TO_TICKS(100));
}
