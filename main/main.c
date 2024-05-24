#include "candy.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

static const char head[] =
"candy " CANDY_VERSION_STR ", " CANDY_ENV ", " CANDY_GIT_DESCRIBE "\n"\
__DATE__ " " __TIME__ ", " CANDY_COMPILER_ID "-" CANDY_COMPILER_VERSION " on " CANDY_SYSTEM_NAME "-" CANDY_SYSTEM_VERSION "\n"\
"type 'Ctrl+C' to quit\n";

static int stream_reader(char buffer[], const size_t max_len, void *arg) {
  int ch = 0;
  while ((ch = getchar()) < 0)
    vTaskDelay(1);
  buffer[0] = ch;
  return ch > 0 ? 1 : -1;
}

void app_main(void) {
  candy_state_t *state = candy_state_create_default();
  printf(head);
  int ch = '\n';
  while (1) {
    fwrite("> ", 1, 2, stdout);
    if (candy_state_dostream(state, stream_reader, &ch) != 0)
      (void)0;
  }
  candy_state_delete(state);
}
