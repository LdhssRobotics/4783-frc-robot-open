#include "UltrasonicSub.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/GetUltrasonicDistance.h"

UltrasonicSub::UltrasonicSub() : Subsystem("UltrasonicSub") {
	ultra = RobotMap::ultra;
}

void UltrasonicSub::InitDefaultCommand() {
	SetDefaultCommand(new GetUltrasonicDistance());
}

float UltrasonicSub::GetDistanceInches() {
	return ultra->GetRangeInches();
}

float UltrasonicSub::GetDistanceFeet() {
	return GetDistanceInches() / feetConstant;
}

void UltrasonicSub::LogDistance() {
	SmartDashboard::PutNumber("Distance-inches:", GetDistanceInches());
	SmartDashboard::PutNumber("Distance-feet:", GetDistanceFeet());
}

void UltrasonicSub::Reset() {
	SmartDashboard::PutNumber("Distance-inches:", 0.0);
	SmartDashboard::PutNumber("Distance-feet:", 0.0);
}
