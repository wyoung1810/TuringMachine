
#ifndef TM_Motor_Movement_h
#define TM_Motor_Movement_h

#include "Arduino.h"
#include <Adafruit_MotorShield.h>
#include <Servo.h>

class TM_Motor_Movement
{
  public:
    TM_Motor_Movement(
    uint8_t film_dc_pin,
    uint8_t stepper_pin,
    uint8_t solenoid_pin,
    uint8_t eraser_pin,
    uint8_t stepper_total_steps,
    uint8_t stepper_move_steps,
    uint8_t stepper_speed,
    uint8_t dc_film_speed,
    uint8_t draw_actuation_servo_pin,
    uint8_t draw_control_servo_pin,
    uint8_t marker_up_pos,
    uint8_t marker_down_pos,
    uint8_t head_min_pos,
    uint8_t head_max_pos);
    void begin();
    void moveFilmForward();
    void moveFilmBackward();
    void markerDown();
    void markerUp();
    void eraserDown();
    void eraserUp();
    void erase();
    void headPositiveVerticalLine();
    void headNegativeVerticalLine();
    void drawForwardHorizontalLine();
    void drawBackwardHorizontalLine();
    void drawArrow();
    void drawZero();
    void drawOne();
    void drawX();
    void drawY();
    void drawBlank();
    void drawHash();
  private:
    Adafruit_MotorShield AFMS;
    Adafruit_StepperMotor *fineFilmControl;
    Adafruit_DCMotor *coarseFilmControl;
    Servo drawingActuation;
    Servo drawingControl;
    Adafruit_DCMotor *eraserActuation;
    Adafruit_DCMotor *eraserControl;
    //The pin on MotorShield connected to the DC motors used for coarse movement of the film.
    // Will be M1, M2, M3, or M4
    uint8_t film_dcM_pin;
    uint8_t stepperM_pin;
    uint8_t solenoidM_pin;
    uint8_t eraserM_pin;
    uint8_t stepperM_total_steps;
    uint8_t stepperM_move_steps;
    uint8_t stepperM_speed;
    uint8_t dcM_film_speed;
    uint8_t draw_actuation_servoM_pin;
    uint8_t draw_control_servoM_pin;
    uint8_t marker_up_posi;
    uint8_t marker_down_posi;
    uint8_t head_min;
    uint8_t head_max;
};

#endif