#include <stdio.h>
#include "pico/stdlib.h"

int main() {
  stdio_init_all();

  for(char i=8; i<18; i++){
    gpio_init(i);
    gpio_set_dir(i, true);
  }

  gpio_set_dir(15, false);
  gpio_set_dir(16, false);
  gpio_set_dir(17, false);

  int contador = 0;
  int segmentos = 0x7e;

  while (true) {
    
    for(char i=0; i<7; i++) {
      bool salida = segmentos & (1<<(6-i));
      char pin = 8+i;
      gpio_put(pin, salida);
    }

    bool reset = gpio_get(15);
    bool menos = gpio_get(16);
    bool mas = gpio_get(17);

    if(mas==true){
      contador++;
      if(contador > 9) {
        contador = 9;
      }
    }
    else if(menos==true){
      contador--;
      if(contador < 0) {
        contador = 0;
      }
    }
    else if(reset==true){
      contador=0;
    }

    if(contador==0){
      segmentos=0x7e;
    }
    else if(contador==1){
      segmentos=0x30;
    }
    else if(contador==2){
      segmentos=0x6d;
    }
    else if(contador==3){
      segmentos=0x79;
    }
    else if(contador==4){
      segmentos=0x33;
    }
    else if(contador==5){
      segmentos=0x5b;
    }
    else if(contador==6){
      segmentos=0x5f;
    }
    else if(contador==7){
      segmentos=0x70;
    }
    else if(contador==8){
      segmentos=0x7f;
    }
    else if(contador==9){
      segmentos=0x7b;
    }
    sleep_ms(500);
  }
}