
#include "serial/heads.h"

void main(){
    char PORT[6];
    FindPort(PORT);
    SerialConfig(PORT);
}

