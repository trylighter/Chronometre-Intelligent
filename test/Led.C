/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */


#include "Led.hpp"


    
Led::Led(int input_port){
        m_inputPort = input_port;
        m_gpio_Led = mraa_gpio_init(input_port);
        mraa_gpio_dir(m_gpio_Led, MRAA_GPIO_OUT);
    }

        
void Led::writeValue(int value){
        mraa_gpio_write(m_gpio_Led, value);
    }

int Led::readValue(){
    return mraa_gpio_read(m_gpio_Led);
}
    
void Led::allumerLed(){
        mraa_gpio_write(m_gpio_Led, 1);
    }
    
void Led::eteindreLed(){
        mraa_gpio_write(m_gpio_Led,0);
    }
    
Led::~Led(){
        mraa_gpio_close(m_gpio_Led);
    }

