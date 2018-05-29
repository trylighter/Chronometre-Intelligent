
#ifndef PERIPHERIQUE_HPP
#define PERIPHERIQUE_HPP

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
  virtual void read()=0;
  virtual int write()=0;
};
class Digital : public Peripherique
{
public :
  Digital(int input_port);
  ~Digital();
  virtual int read();
  virtual int write(void *arg);
private:
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
  virtual float read();
  virtual int read();
  Analogique(int input_port);
  ~Analogique();
private:
  mraa_aio_context  m_analogique;
};
class I2C{
  I2C(int input_port);
  ~I2C();
  virtual void* read(void * data,int length);
  virtual int write(void *arg, int length);
};
	     
