#include "ToggleCamera.h"

ToggleCamera::ToggleCamera() {

}

// Called just before this Command runs the first time
void ToggleCamera::Initialize() {
	Robot::vision->isCam0Enabled = true;
	SmartDashboard::PutString("Camera:", "cam0");
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleCamera::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ToggleCamera::End() {
	Robot::vision->isCam0Enabled = false;
	SmartDashboard::PutString("Camera:", "cam1");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleCamera::Interrupted() {
	End();
}
