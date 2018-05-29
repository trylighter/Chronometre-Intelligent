
/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */

#include "Led.hpp"
#include <iostream>


int main(){
    Led Led1(2);
    while(1)
    {
        Led1.allumerLed();
        sleep(2);
        Led1.eteindreLed();
        sleep(2);
    }
	return(0);
}
