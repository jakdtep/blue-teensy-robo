//#define USE_ARDUINO_IDE
#ifndef  USE_ARDUINO_IDE
#include "WProgram.h"
#endif

#define MOTOR_PWM_PIN_LEFT      10
#define MOTOR_PWM_PIN_RIGHT     10
#define MOTOR_MIN_PWM_VAL       100
#define MOTOR_MAX_PWM_VAL       255
#define DEG_TO_PWM              ((float)(MOTOR_MAX_PWM_VAL - MOTOR_MIN_PWM_VAL)/90)

/*  +90 -> right
    0   -> forward
    -90 -> left
    180 -> backwards ??
*/


void turnByDegree(int16_t degree)
{
    int16_t leftPwm = 0, rightPwm = 0;
    int16_t degToPWM = (int16_t)(degree * DEG_TO_PWM);
    if(!degree)
    {
        leftPwm  = MOTOR_MAX_PWM_VAL;
        rightPwm = MOTOR_MAX_PWM_VAL;
    }
    if(degree > 0 && degree <= 90) /*right turn*/
    {
        leftPwm = MOTOR_MAX_PWM_VAL;
        rightPwm = MOTOR_MAX_PWM_VAL - degToPWM;
    }
    if(degree >= -90 && degree < 0) /*left turn*/
    {
        rightPwm = MOTOR_MAX_PWM_VAL;
        leftPwm = MOTOR_MAX_PWM_VAL - degToPWM;
    }
    analogWrite(MOTOR_PWM_PIN_LEFT, leftPwm);
    analogWrite(MOTOR_PWM_PIN_RIGHT, rightPwm);
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
