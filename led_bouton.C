/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Input : Bouton à l'input D3
 Output : LED à D2
 
 Fonctionnement : La LED s'allume lorsque le bouton est enfoncé
 */

#include <mraa/aio.h>
#include <mraa/gpio.h>
int main(){
  mraa_gpio_context m_gpio_led;
  mraa_gpio_context m_gpio_button; 
  // initialisation
  mraa_init();
  m_gpio_led = mraa_gpio_init(2);
  m_gpio_button = mraa_gpio_init(3);
  mraa_gpio_dir(m_gpio_led, MRAA_GPIO_OUT);
  mraa_gpio_dir(m_gpio_button, MRAA_GPIO_IN);
  int val_bouton;
  // alummage et extinction
  while(1)
    {
      val_bouton = mraa_gpio_read(m_gpio_button);
      if (val_bouton == 1)
	{
	   mraa_gpio_write(m_gpio_led, 1);
	}
      else
	{
	   mraa_gpio_write(m_gpio_led, 0);
	}
      usleep(200); 
      // fin
     
    }
  return(0);
}
