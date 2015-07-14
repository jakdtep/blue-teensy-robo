//#define USE_ARDUINO_IDE
#ifndef  USE_ARDUINO_IDE
#include "WProgram.h"
#endif

#define MOTOR_PWM_PIN_LEFT      10
#define MOTOR_PWM_PIN_RIGHT     10
#define MOTOR_MIN_PWM_VAL       100
#define MOTOR_MAX_PWM_VAL       255
#define DEG_TO_PWM              (MOTOR_MAX_PWM_VAL - MOTOR_MIN_PWM_VAL)/90

/*  +90 -> right
    0   -> forward
    -90 -> left
    180 -> backwards
*/


void turnByDegree(int16_t degree)
{
    
}

void setup()
{

}

void loop()
{
    
}

#ifndef USE_ARDUINO_IDE
int main()
{
    // Arduino's main() function just calls setup() and loop()....
	setup();
	while (1) {
		loop();
		yield();
	}
    return 0;
}
#endif
