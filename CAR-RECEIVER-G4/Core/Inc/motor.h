#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"

#define PWM_MAX 4095

void motor_init(void);

void motor_forward(uint16_t speed);
void motor_backward(uint16_t speed);
void motor_stop(void);

void motor_left(uint16_t speed);
void motor_right(uint16_t speed);
void motor_steer_stop(void);

#endif
