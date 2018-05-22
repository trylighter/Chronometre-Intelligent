#include "peripheriques.hpp"

Peripherique::Peripherique()
{
  mraa_init();
}
Digital::Digital(int input_port)
{
  m_gpio = mraa_gpio_init(input_port);
}
  
Digital::virtual void* read()
{
  return &mraa_gpio_read(m_gpio);
}
Digital::virtual int write(void * arg)
{
  int donnee = *arg;
  mraa_gpio_write(m_gpio_Led, donnee);
}
Digital::~Digital(){
        mraa_gpio_close(m_gpio);
}
Led::Led(input_port):Digital(input_port){
  mraa_gpio_dir(m_gpio_Led, MRAA_GPIO_OUT);
}
Led::allumer_led(){
  int i = 1;
  Digital::write((void *) &i);
}
Led::eteindre_led(){
  int i = 0;
  Digital::write((void *) &i);
}

