#ifndef ToggleCamera_H
#define ToggleCamera_H

#include "../RobotMap.h"
#include "../Robot.h"
#include <WPILib.h>

class ToggleCamera : public Command {
public:
	ToggleCamera();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleCamera_H
