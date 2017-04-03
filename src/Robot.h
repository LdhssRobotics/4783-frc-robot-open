/*
 * Robot.h
 *
 *  Created on: Apr 2, 2017
 *      Author: kirae
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

// General includes
#include <WPILib.h>
#include <Commands/Command.h>
#include <LiveWindow/LiveWindow.h>
#include "RobotMap.h"

// Vision includes
#include <thread>
#include <CameraServer.h>

// Subsystem includes
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/UltrasonicSub.h"
#include "Subsystems/Vision.h"
#include "OI.h"

// Autonomous mode includes
#include "Commands/AutonomousModes/LeftAutoMode.h"
#include "Commands/AutonomousModes/CentreAutoMode.h"
#include "Commands/AutonomousModes/RightAutoMode.h"

#include "Commands/ToggleCamera.h"

using namespace std;
using namespace frc;

class Robot : public IterativeRobot {
public:
	// Pointers for selecting autonomous mode
	unique_ptr<Command> autonomousCommand;
	SendableChooser<Command*> chooser;

	// Subsystem pointers
	static unique_ptr<OI> oi;
	static shared_ptr<Climber> climber;
	static shared_ptr<Drivetrain> drivetrain;
	static shared_ptr<Shooter> shooter;
	static shared_ptr<UltrasonicSub> ultrasonic;
	static shared_ptr<Vision> vision;

	LiveWindow *lw = LiveWindow::GetInstance();

	static void VisionThread();
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};



#endif /* SRC_ROBOT_H_ */
