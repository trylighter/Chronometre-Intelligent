/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */

#ifndef LED_HPP
#define LED_HPP


#include <mraa/aio.h>
#include <mraa/gpio.h>


class Led{
    private :
    mraa_gpio_context m_gpio_Led;
    int m_inputPort;
    
    public :
    Led(int input_port);
    
    void writeValue(int value);
    
    int readValue();
    
    
    void allumerLed();
    
    void eteindreLed();
    
    ~Led();
	
};





#endif
