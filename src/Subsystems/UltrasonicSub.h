#ifndef UltrasonicSub_H
#define UltrasonicSub_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class UltrasonicSub : public Subsystem {
private:
	std::shared_ptr<Ultrasonic> ultra;
	const float feetConstant = 0.0833333333;

public:
	UltrasonicSub();
	void InitDefaultCommand();
	float GetDistanceInches();
	float GetDistanceFeet();
	void LogDistance();
	void Reset();
};

#endif  // UltrasonicSub_H
