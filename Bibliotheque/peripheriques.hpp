
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
  virtual void read();
  virtual void write();
};


class Digital : public Peripherique
{
public :
  Digital(int input_port);
  ~Digital();
   int read_port();
   int write_port(int arg);
protected:
  mraa_gpio_context m_gpio_in,m_gpio_out;
};


class Ultrason : public Digital
{
  Ultrason(int input_port);
  virtual void read();
};


class Led : public Digital{
public:
  Led(int input_port);
  void allumer_led();
  void eteindre_led();
private:
};




class Analogique : public Peripherique
{
public:
  Analogique(int input_port);
  ~Analogique();
  float read_float_port();
  int read_port();
protected:
  mraa_aio_context  m_analogique;
};
#endif
