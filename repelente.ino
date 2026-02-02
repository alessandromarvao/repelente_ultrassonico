#include "params.h"
#include "buzzer.h"

void buzzerTask(void *pvParameters) {
  // Toca o buzzer na frequência de 25 kHz
  play_buzzer(BUZZER_PIN, FREQ_25);

  // Toca o buzzer na frequência de 30 kHz
  play_buzzer(BUZZER_PIN, FREQ_30);

  // Toca o buzzer na frequência de 35 kHz
  play_buzzer(BUZZER_PIN, FREQ_35);

  // Toca o buzzer na frequência de 40 kHz
  play_buzzer(BUZZER_PIN, FREQ_40);

  // Tempo estimado para dormir (deep sleep)
  esp_sleep_enable_timer_wakeup(5 * 1000000ULL);

  // Entra em deep sleep (não retorna)
  esp_deep_sleep_start();

  // Nunca chega aqui, mas por boas práticas
  vTaskDelete(NULL);
}

void setup() {
  xTaskCreatePinnedToCore(
    buzzerTask,          // Função da task
    "Buzzer Task",       // Nome
    2048,                // Stack size
    NULL,                // Parâmetro
    1,                   // Prioridade
    &buzzerTaskHandle,   // Handle
    1                    // Core 1
  );
}

void loop() {
  // Não usado
}
