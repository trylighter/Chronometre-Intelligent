/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */

#include <mraa/aio.h>
#include <mraa/gpio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#define time_trig_high 20.0  //20us
#define time_trig_low 100.0 // 100ms
#define time_sampling_out 100.0  //100us
#define ratio 22/0.06  // conversion eb cm

using namespace std;

int main(){
	mraa_gpio_context m_gpio_trig, m_gpio_out;
	mraa_init();
    
    
	m_gpio_trig = mraa_gpio_init(9);
	mraa_gpio_dir(m_gpio_trig, MRAA_GPIO_OUT);
    
    m_gpio_out = mraa_gpio_init(8);
    mraa_gpio_dir(m_gpio_out, MRAA_GPIO_IN);
    
    
	 float resultat;
    mraa_gpio_write(m_gpio_trig,0);
    usleep(50000); //Pour valider le zéro
    while(1)
    {
       
        mraa_gpio_write(m_gpio_trig,1);
        usleep(time_trig_high);
        
        
        mraa_gpio_write(m_gpio_trig,0);
        
        
       
        int counter=0;
        for (int i=0;  i<time_trig_low;i++)
        {
            if (mraa_gpio_read(m_gpio_out)>0)
            {
                counter++;
            }
            
            usleep(time_sampling_out);
        }
        
            system("clear");
        resultat=(float)(counter/time_trig_low)*ratio;
             cout<<resultat<<endl;
       
    }
   

	return(0);
}
