#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class Vision : public Subsystem {
private:
	bool isCam0Enabled;

public:
	Vision();
	void InitDefaultCommand();
	void Reset();
};

#endif  // Vision_H
