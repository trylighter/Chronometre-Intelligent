/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Input : Capteur de temperature à l'input A0
 Output : Ecran LCD
 
 Fonctionnement :
 */

#include <mraa/i2c.h>
#include <mraa/aio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

#define ratio 5/100




using namespace std;





int main(){

  mraa_aio_context m_a_tele;
  float valeur;
 

    m_a_tele = mraa_aio_init(0);
    while(1)
    {
    
    valeur = (683-mraa_aio_read(m_a_tele))*ratio;
           system("clear");
    cout<<valeur<<endl;
    }
    
    
    


 
    return 0;
}

