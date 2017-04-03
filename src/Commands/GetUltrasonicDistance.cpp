#include "GetUltrasonicDistance.h"

GetUltrasonicDistance::GetUltrasonicDistance() {
	Requires(Robot::ultrasonic.get());
}

// Called repeatedly when this Command is scheduled to run
void GetUltrasonicDistance::Execute() {
	// Print distance in feet and inches to SmartDashboard
	Robot::ultrasonic->LogDistance();
}

// Make this return true when this Command no longer needs to run execute()
bool GetUltrasonicDistance::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetUltrasonicDistance::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetUltrasonicDistance::Interrupted() {

}
