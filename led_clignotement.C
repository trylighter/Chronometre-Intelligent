/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */

#include <mraa/aio.h>
#include <mraa/gpio.h>
#include <iostream>

int main(){
	mraa_gpio_context m_gpio;
	mraa_init();
	m_gpio = mraa_gpio_init(2);
	mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
	mraa_gpio_write(m_gpio, 1);
	cout<<mraa_gpio_read(m_gpio)<<endl;;
	sleep(2);
	mraa_gpio_write(m_gpio, 0);
	sleep(2);
	mraa_gpio_write(m_gpio, 1);
	mraa_gpio_close(m_gpio);
	return(0);
}
