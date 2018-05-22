
#ifndef PERIPHERIQUES_HPP
#define PERIPHERIQUES_HPP

#include <mraa/gpio.h>
#include <mraa/i2c.h>
#include <mraa/aio.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;
class Peripherique
{
public:
  Peripherique();
  virtual void* read()=0;
  virtual int write(void *arg)=0;
};




class Digital : public Peripherique
{
public :
  Digital(int input_port);
  ~Digital();
   virtual void* read();
   virtual int write(void *arg);
protected:
  mraa_gpio_context m_gpio;
};




class Led : public Digital{
public:
  Led(int input_port);
  void allumer_led();
  void eteindre_led();
private:
};




class Analogique
{
public:
  Analogique(int input_port);
  ~Analogique();
protected:
  mraa_aio_context  m_analogique;
};
#endif
