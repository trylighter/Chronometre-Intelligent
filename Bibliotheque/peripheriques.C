#include "peripheriques.hpp"
#include <stdlib.h>

#define time_trig_high 20.0  //20us
#define time_trig_low 100.0 // 100ms
#define time_sampling_out 100.0  //100us
#define ratio 22/0.06  // conversion eb cm
//###################################################
//#####            PERIPHERIQUE                 #####
//###################################################

Peripherique::Peripherique()
{
  mraa_init();
}

//###################################################
//#####               DIGITAL                   #####
//###################################################


Digital::Digital(int input_port):Peripherique()
{
  m_gpio_in = mraa_gpio_init(input_port);
  mraa_gpio_dir(m_gpio_in, MRAA_GPIO_IN);
  m_gpio_out = mraa_gpio_init(input_port+1);
  mraa_gpio_dir(m_gpio_out, MRAA_GPIO_OUT);
}

Digital::~Digital(){
  mraa_gpio_close(m_gpio_out);
  mraa_gpio_close(m_gpio_in);
}
  
int Digital::read_port()
{
  return mraa_gpio_read(m_gpio_in);
}
int Digital::write_port(int arg)
{
  return mraa_gpio_write(m_gpio_out, arg);
    
}

        //######################################
        //#####            LED             #####
        //######################################


Led::Led(int input_port):Digital(input_port){
}
void Led::allumer_led(){
  int i = 1;
  Digital::write_port(i);
}
void Led::eteindre_led(){
  int i = 0;
  Digital::write_port(i);
}
        //######################################
        //#####         ULTRASON           #####
        //######################################
Ultrason::Ultrason(int input_port):Digital(input_port){}
void read(){
    (*this).write_port(0);
    usleep(50000); //Pour valider le zéro
    while(1)
    {
       
        (*this).write_port(1);
        usleep(time_trig_high);
        
        
        (*this).write_port(0);
        
        
       
        counter=0;
        for (int i=0;  i<time_trig_low;i++)
        {
            if ( (*this).read_port(0)>0)
            {
                counter++;
            }
            
            usleep(time_sampling_out);
        }
        
        system("clear");
        resultat=(float)(counter/time_trig_low)*ratio;
        cout<<resultat<<endl;
       
    }
   cout<<"coucou"<<endl;
}

//###################################################
//#####               ANALOGIQUE                #####
//###################################################

int Analogique::read_port()
{
    return mraa_aio_read(m_analogique);
}
float Analogique::read_float_port()
{
    return mraa_aio_read_float(m_analogique);
}
Analogique::Analogique(int input_port):Peripherique()
{
    m_analogique = mraa_aio_init(input_port);
}
Analogique::~Analogique(){
    mraa_aio_close(m_analogique);
}


