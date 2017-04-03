#include "OI.h"
#include "WPILib.h"

OI::OI() {
	driveStick.reset(new Joystick(0));
	shootStick.reset(new Joystick(1));

	// Drive stick buttons
	aButtonD = new JoystickButton(driveStick.get(), 1);
	bButtonD = new JoystickButton(driveStick.get(), 2);
	xButtonD = new JoystickButton(driveStick.get(), 3);
	yButtonD = new JoystickButton(driveStick.get(), 4);
	leftBumperButtonD = new JoystickButton(driveStick.get(), 5);
	rightBumperButtonD = new JoystickButton(driveStick.get(), 6);
	selectButtonD = new JoystickButton(driveStick.get(), 7);
	startButtonD = new JoystickButton(driveStick.get(), 8);
	leftStickButtonD = new JoystickButton(driveStick.get(), 9);

	// Shoot stick buttons
	aButtonS = new JoystickButton(shootStick.get(), 1);
	bButtonS = new JoystickButton(shootStick.get(), 2);
	xButtonS = new JoystickButton(shootStick.get(), 3);
	yButtonS = new JoystickButton(shootStick.get(), 4);
	leftBumperButtonS = new JoystickButton(shootStick.get(), 5);
	rightBumperButtonS = new JoystickButton(shootStick.get(), 6);
	selectButtonS = new JoystickButton(shootStick.get(), 7);
	startButtonS = new JoystickButton(shootStick.get(), 8);
	leftStickButtonS = new JoystickButton(shootStick.get(), 9);

	// Assign commands to buttons

	// Drive stick controls
		// Left bumper button reduces base speed while held
		// Right bumper button reduces turn speed while held
		// Y-axis of left joystick controls base speed
		// X-axis of right joystick controls turn speed

	// Shoot stick controls
}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<Joystick> OI::getShootStick() {
	return shootStick;
}
