#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"

Shooter::Shooter() : Subsystem("Shooter") {

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Reset() {
	// This is called when the robot is disabled
	// Reset any relevant sensors here
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
