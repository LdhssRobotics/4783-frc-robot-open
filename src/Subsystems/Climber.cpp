#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"

Climber::Climber() : Subsystem("Climber") {

}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Climber::Reset() {
	// This is called when the robot is disabled
	// Reset any relevant sensors here
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
