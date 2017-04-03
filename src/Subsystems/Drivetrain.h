#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class Drivetrain : public Subsystem {
private:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<SpeedController> frontLeftDrive;
	std::shared_ptr<SpeedController> backLeftDrive;
	std::shared_ptr<SpeedController> frontRightDrive;
	std::shared_ptr<SpeedController> backRightDrive;

public:
	Drivetrain();
	void InitDefaultCommand();
	float GetDistanceTravelled();
	double GetHeading();
	void ArcadeDrive(double speed, double turn);
	void TankDrive(double left, double right);
	void Stop();
	void Log();
	void Reset();
};

#endif  // Drivetrain_H
