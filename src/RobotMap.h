#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	// Climber subsystem

	// Drivetrain subsystem
	static std::shared_ptr<AnalogGyro> gyro;
	static std::shared_ptr<Encoder> driveEncoder;
	static std::shared_ptr<SpeedController> frontLeftDrive;
	static std::shared_ptr<SpeedController> backLeftDrive;
	static std::shared_ptr<SpeedController> frontRightDrive;
	static std::shared_ptr<SpeedController> backRightDrive;
	static std::shared_ptr<RobotDrive> robotDrive;

	// Shooter subsystem

	// Ultrasonic subsystem
	static std::shared_ptr<Ultrasonic> ultra;

	static void init();
	static void reset();
};

#endif  // ROBOTMAP_H
