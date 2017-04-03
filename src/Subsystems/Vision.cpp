#include "Vision.h"
#include "../RobotMap.h"
#include "../Robot.h"

Vision::Vision() : Subsystem("Vision") {
	isCam0Enabled = true;
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Vision::Reset() {
	// This is called when the robot is disabled
	// Reset any relevant sensors here
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
