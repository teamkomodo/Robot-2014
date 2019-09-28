#include "WPILib.h"
class Robot : public IterativeRobot
{
	RobotDrive myRobot;
	Joystick gamepad;
	Joystick gamepad2;
    Compressor compressor;
    Solenoid up;
    Solenoid down;
    Solenoid open;
    Solenoid close;
	bool buttonflag[5];
	bool fastmode;
public:
	Robot() :
		myRobot(2, 1),
		gamepad(1),
		gamepad2(2),
		compressor(1,3),
		up(3),
		down(4),
		open(2),
		close(1)
	{
		myRobot.SetExpiration(0.1);
	}
void RobotInit() {
	fastmode = true;
}
void DisabledInit() {
}
void DisabledPeriodic() {
}
void AutonomousInit() {
}
void AutonomousPeriodic() {
}
void TeleopInit() {
	for(int i=0; i<5; i++) // Reset the button pulse array
		buttonflag[i] = false;
}
void TeleopPeriodic() {
	//myRobot.ArcadeDrive(-gamepad.GetRawAxis(5)*.6, -gamepad.GetRawAxis(4)*.6);
	myRobot.ArcadeDrive(-gamepad.GetRawAxis(5), -gamepad.GetRawAxis(4));
	compressor.Start();
	//BUTTON CONTROL
	if(gamepad.GetRawButton(1) && !buttonflag[1]){//a button
		buttonflag[1] = true;
		up.Set(true);
		down.Set(false);
	}
	if(gamepad.GetRawButton(4) && !buttonflag[2]){//y button
		buttonflag[2] = true;
		up.Set(false);
		down.Set(true);
	}
	if(gamepad.GetRawButton(3) && !buttonflag[3]){//x button
		buttonflag[3] = true;
		open.Set(true);
		close.Set(false);
	}
	if(gamepad.GetRawButton(2) && !buttonflag[4]){//b button
		buttonflag[4] = true;
		open.Set(false);
		close.Set(true);
	}
	if(gamepad2.GetRawButton(1) && !buttonflag[5]){//a button
		fastmode = !fastmode;
	}
	//BUTTON FLAG RESETS
	if(!gamepad.GetRawButton(1) && buttonflag[1]){//a button
		buttonflag[1] = false;
	}
	if(!gamepad.GetRawButton(4) && buttonflag[2]){//y button
		buttonflag[2] = false;
	}
	if(!gamepad.GetRawButton(3) && buttonflag[3]){//x button
		buttonflag[3] = false;
	}
	if(!gamepad.GetRawButton(2) && buttonflag[4]){//b button
		buttonflag[4] = false;
	}
	if(!gamepad2.GetRawButton(1) && buttonflag[5]){//a button
		buttonflag[5] = false;
	}
}
void TestInit() {
}
void TestPeriodic() {
}

};
START_ROBOT_CLASS(Robot);

