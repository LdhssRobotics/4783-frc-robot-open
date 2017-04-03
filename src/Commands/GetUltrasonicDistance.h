#ifndef GetUltrasonicDistance_H
#define GetUltrasonicDistance_H

#include "../RobotMap.h"
#include "../Robot.h"
#include <WPILib.h>

class GetUltrasonicDistance : public Command {
public:
	GetUltrasonicDistance();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetUltrasonicDistance_H
