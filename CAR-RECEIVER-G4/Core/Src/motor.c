#include "motor.h"

/* =========================================================
   MOTOR CONNECTIONS (REFERENCE)

   Motor A: PB6  / PB7
   Motor B: PB8  / PB9
   Motor C: PB10 / PB11  (STEERING MOTOR)

   Motor A + B = DRIVE (always move together)
   Motor C     = STEERING (front wheels)

   PWM TIMERS
   TIM3 CH2 -> Drive speed (Motor A + B)
   TIM2 CH1 -> Steering speed (Motor C)

   GPIO PORT
   All motors connected to GPIOB
   ========================================================= */


/* ===== EXTERNAL TIMERS ===== */
extern TIM_HandleTypeDef htim3;   // Drive PWM
extern TIM_HandleTypeDef htim2;   // Steering PWM


/* ===== GPIO DEFINITIONS ===== */
#define MOTOR_PORT GPIOB

#define MA_IN1 GPIO_PIN_6
#define MA_IN2 GPIO_PIN_7

#define MB_IN1 GPIO_PIN_8
#define MB_IN2 GPIO_PIN_9

#define MC_IN1 GPIO_PIN_10
#define MC_IN2 GPIO_PIN_11


/* ===== INTERNAL PWM HELPERS ===== */

static void Drive_SetPWM(uint16_t speed)
{
    uint32_t arr  = __HAL_TIM_GET_AUTORELOAD(&htim3);
    uint32_t duty = (speed * arr) / PWM_MAX;

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, duty);
}

static void Steering_SetPWM(uint16_t speed)
{
    uint32_t arr  = __HAL_TIM_GET_AUTORELOAD(&htim2);
    uint32_t duty = (speed * arr) / PWM_MAX;

    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
}


/* ===== INITIALIZATION ===== */

void motor_init(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // Drive PWM
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); // Steering PWM

    motor_stop();
}


/* ===== DRIVE (MOTOR A + B) ===== */

void motor_forward(uint16_t speed)
{
    if(speed > PWM_MAX)
        speed = PWM_MAX;

    HAL_GPIO_WritePin(MOTOR_PORT, MA_IN1 | MB_IN1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_PORT, MA_IN2 | MB_IN2, GPIO_PIN_RESET);

    Drive_SetPWM(speed);
}

void motor_backward(uint16_t speed)
{
    if(speed > PWM_MAX)
        speed = PWM_MAX;

    HAL_GPIO_WritePin(MOTOR_PORT, MA_IN1 | MB_IN1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_PORT, MA_IN2 | MB_IN2, GPIO_PIN_SET);

    Drive_SetPWM(speed);
}

void motor_stop(void)
{
    HAL_GPIO_WritePin(MOTOR_PORT,
                      MA_IN1 | MA_IN2 |
                      MB_IN1 | MB_IN2,
                      GPIO_PIN_RESET);

    Drive_SetPWM(0);
}


/* ===== STEERING (MOTOR C) ===== */

void motor_left(uint16_t speed)
{
    if(speed > PWM_MAX)
        speed = PWM_MAX;

    HAL_GPIO_WritePin(MOTOR_PORT, MC_IN1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_PORT, MC_IN2, GPIO_PIN_RESET);

    Steering_SetPWM(speed);
}

void motor_right(uint16_t speed)
{
    if(speed > PWM_MAX)
        speed = PWM_MAX;

    HAL_GPIO_WritePin(MOTOR_PORT, MC_IN1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_PORT, MC_IN2, GPIO_PIN_SET);

    Steering_SetPWM(speed);
}

void motor_steer_stop(void)
{
    HAL_GPIO_WritePin(MOTOR_PORT, MC_IN1 | MC_IN2, GPIO_PIN_RESET);
    Steering_SetPWM(0);
}
