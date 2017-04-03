#include "Robot.h"

using namespace std;
using namespace cs;

shared_ptr<Climber> Robot::climber;
shared_ptr<Drivetrain> Robot::drivetrain;
shared_ptr<Shooter> Robot::shooter;
shared_ptr<UltrasonicSub> Robot::ultrasonic;
shared_ptr<Vision> Robot::vision;

unique_ptr<OI> Robot::oi;

UsbCamera cam0;
UsbCamera cam1;
CvSink cam0Sink;
CvSink cam1Sink;
VideoSink server;

void Robot::VisionThread() {
	cam0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	cam0.SetResolution(160, 120);

	cam1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	cam1.SetResolution(160, 120);

	server = CameraServer::GetInstance()->GetServer();

	// cscore disconnects any cameras not in use so dummy
	// cvSinks are created to keep the camera connected
	cam0Sink.SetSource(cam0);
	cam0Sink.SetEnabled(true);

	cam1Sink.SetSource(cam1);
	cam1Sink.SetEnabled(true);
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

	// Set the camera feed to cam0 on startup
	ToggleCamera();
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

	// Determine which camera feed to display
	if (Robot::vision->isCam0Enabled) {
		server.SetSource(cam0);
	} else {
		server.SetSource(cam1);
	}
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
