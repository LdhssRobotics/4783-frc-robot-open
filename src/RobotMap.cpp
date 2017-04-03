#include "RobotMap.h"
#include "Robot.h"
#include "LiveWindow/LiveWindow.h"

// PORT MAPPINGS
	// PWM Ports
		// Climber subsystem

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 0
#define BACK_LEFT_DRIVE_PORT 1
#define FRONT_RIGHT_DRIVE_PORT 2
#define BACK_RIGHT_DRIVE_PORT 3

		// Shooter subsystem

	// Digital Ports
		// Climber subsystem

		// Drivetrain subsystem
#define DRIVE_ENCODER_A_PORT 2
#define DRIVE_ENCODER_B_PORT 3

		// Shooter subsystem

		// Ultrasonic subsystem
#define ULTRASONIC_TRIGGER_PORT 0
#define ULTRASONIC_ECHO_PORT 1

	//Analog Ports
#define GYRO_PORT 0

// POINTERS
	// Climber subsystem

	// Drivetrain subsystem
std::shared_ptr<AnalogGyro> RobotMap::gyro;
std::shared_ptr<Encoder> RobotMap::driveEncoder;
std::shared_ptr<SpeedController> RobotMap::frontLeftDrive;
std::shared_ptr<SpeedController> RobotMap::backLeftDrive;
std::shared_ptr<SpeedController> RobotMap::frontRightDrive;
std::shared_ptr<SpeedController> RobotMap::backRightDrive;
std::shared_ptr<RobotDrive> RobotMap::robotDrive;

	// Shooter subsystem

	// Ultrasonic subsystem
std::shared_ptr<Ultrasonic> RobotMap::ultra;

void RobotMap::init() {
	LiveWindow *lw = LiveWindow::GetInstance();

	// Climber subsystem

	// Drivetrain subsystem
	driveEncoder.reset(new Encoder(DRIVE_ENCODER_A_PORT, DRIVE_ENCODER_B_PORT, false, Encoder::EncodingType::k4X));
	driveEncoder->SetMaxPeriod(0.1);
	driveEncoder->SetMinRate(1);
	driveEncoder->SetSamplesToAverage(15);
	driveEncoder->SetReverseDirection(true);
	driveEncoder->SetDistancePerPulse((6*3.14159265358979323)/360.0);
	lw->AddSensor("Drive", "Encoder", driveEncoder);

	frontLeftDrive.reset(new Victor(FRONT_LEFT_DRIVE_PORT));
	frontLeftDrive->SetInverted(false);

	backLeftDrive.reset(new Victor(BACK_LEFT_DRIVE_PORT));
	backLeftDrive->SetInverted(false);

	frontRightDrive.reset(new Victor(FRONT_RIGHT_DRIVE_PORT));
	frontRightDrive->SetInverted(true);

	backRightDrive.reset(new Victor(BACK_RIGHT_DRIVE_PORT));
	backRightDrive->SetInverted(true);

	robotDrive.reset(new RobotDrive(frontLeftDrive, backLeftDrive, frontRightDrive, backRightDrive));
	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetExpiration(0.1);
	robotDrive->SetSensitivity(0.65);
	robotDrive->SetMaxOutput(1.0);

	gyro.reset(new AnalogGyro(GYRO_PORT));
	gyro->SetSensitivity(0.00666);
	gyro->Calibrate();
	lw->AddSensor("Drive", "Gyro", gyro);

	// Shooter subsystem

	// Ultrasonic subsystem
	ultra.reset(new Ultrasonic(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_ECHO_PORT));
	ultra->SetAutomaticMode(true);
	lw->AddSensor("Drive", "Ultrasonic", ultra);
}

void RobotMap::reset() {
	Robot::climber->Reset();
	Robot::drivetrain->Reset();
	Robot::shooter->Reset();
	Robot::ultrasonic->Reset();
}
