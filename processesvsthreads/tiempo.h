#ifndef __TIEMPO_H__
#define __TIEMPO_H__

#include <time.h>

#define tiempo clock_t
#define start clock
#define stop clock
#define transcurrido(a,b) (double)(b - a)/CLOCKS_PER_SEC

#endif
