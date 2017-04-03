#include "Robot.h"

using namespace std;

shared_ptr<Climber> Robot::climber;
shared_ptr<Drivetrain> Robot::drivetrain;
shared_ptr<Shooter> Robot::shooter;
shared_ptr<UltrasonicSub> Robot::ultrasonic;
std::unique_ptr<OI> Robot::oi;

cs::UsbCamera cam0;
cs::UsbCamera cam1;

void Robot::VisionThread() {
	cam0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	cam0.SetResolution(160, 120);

	cam1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	cam1.SetResolution(160, 120);
}

void Robot::RobotInit() {
	// We need to run our vision program in a separate thread.
	// If not, our robot program will not run
	std::thread visionThread(VisionThread);
	visionThread.detach();

	RobotMap::init();

	climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
	shooter.reset(new Shooter());
	ultrasonic.reset(new UltrasonicSub());

	oi.reset(new OI());

	chooser.AddDefault("Left", new LeftAutoMode());
	chooser.AddObject("Centre", new CentreAutoMode());
	chooser.AddObject("Right", new RightAutoMode());
	SmartDashboard::PutData("Auto Modes:", &chooser);
}

void Robot::DisabledInit() {
	// Runs once when disabled
	// Reset sensors and variables
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(chooser.GetSelected());
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
