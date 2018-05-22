/*
 Auteurs : Nicolas Caselles et Théo fregefond
 Progrmme embarqué pour shield arduino avec edison
 Output : LED à D2
 
 Fonctionnement : La LED s'allume et s'eteint
 */

#include "peripheriques.hpp"



int main(){
    
    Led Led1(2);
    while(1)
    {
        
        Led1.allumer_led();
        sleep(1);
        Led1.eteindre_led();
        sleep(1);
  
    }
	return(0);
}
