#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/DriveWithJoystick.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	gyro = RobotMap::gyro;
	driveEncoder = RobotMap::driveEncoder;
	robotDrive = RobotMap::robotDrive;
	frontLeftDrive = RobotMap::frontLeftDrive;
	backLeftDrive = RobotMap::backLeftDrive;
	frontRightDrive = RobotMap::frontRightDrive;
	backRightDrive = RobotMap::backRightDrive;
}

void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new DriveWithJoystick());
}

float Drivetrain::GetDistanceTravelled() {
	return driveEncoder->GetDistance();
}

double Drivetrain::GetHeading()
{
	return gyro->GetAngle();
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	robotDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::TankDrive(double left, double right) {
	robotDrive->TankDrive(left, right);
}

void Drivetrain::Stop(){
	ArcadeDrive(0, 0);
}

void Drivetrain::Log()
{
	SmartDashboard::PutNumber("Heading-degrees", GetHeading());
}

void Drivetrain::Reset() {
	// Reset sensors when disabled
	gyro->Reset();
	driveEncoder->Reset();
	Stop();
}
