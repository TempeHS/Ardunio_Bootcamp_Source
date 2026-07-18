/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will direct-wire a simple DC motor, observe how polarity sets the
  spin direction, and explain why real designs use a motor controller (an H-bridge
  or a continuous servo) instead of direct wiring.

  Hardware:
    One simple DC motor, battery pack, jumper wires or clips.
    This activity needs NO CODE: the circuit is the lesson.

  Safety:
    Only connect the battery pack after your teacher has checked your wiring.
    Never wire the motor directly to an Arduino pin.

  My Observations (completed example):
    Direction with first wiring:
      Clockwise (viewed from the shaft end), marked with tape.
    Direction after swapping the wires:
      Anticlockwise: same motor, same battery, only the polarity changed.
      Direction is set purely by which way current flows through the motor.
    Why real designs need a motor controller:
      With direct wiring the program cannot control anything: direction is baked
      into the wiring, there is no speed control, and no braking. An Arduino pin
      cannot drive the motor anyway (about 40 mA available vs hundreds needed).
      An H-bridge is the electronic version of the wire-swap: four switches
      route the current either way on command, plus PWM speed on the enable pin
      and an active brake. A continuous servo packages the motor, gearbox and
      driver in one case and takes the familiar Servo library signal where
      0 = full reverse, 90 = stop, 180 = full forward.
*/

void setup() {
  // Intentionally empty: this activity is wiring + observation only.
}

void loop() {
  // Intentionally empty.
}
