#include "peripheriques.hpp"

Peripherique::Peripherique()
{
  mraa_init();
}
Digital::Digital(int input_port):Peripherique()
{
  m_gpio = mraa_gpio_init(input_port);
}
  
void* Digital::read()
{
    int *resultat = new int;
    *resultat=mraa_gpio_read(m_gpio);
  return resultat;
}
int Digital::write(void * arg)
{
    
  int * donnee = (int*)arg;
  return mraa_gpio_write(m_gpio, *donnee);
    
}
Digital::~Digital(){
        mraa_gpio_close(m_gpio);
}
Led::Led(int input_port):Digital(input_port){
  mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
}
void Led::allumer_led(){
  int i = 1;
  Digital::write((void *) &i);
}
void Led::eteindre_led(){
  int i = 0;
  Digital::write((void *) &i);
}

