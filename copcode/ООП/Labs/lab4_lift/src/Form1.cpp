//
//
//
#include "stdafx.h"

#include "Form1.h"
#include "lift_system.h"

using namespace src;


System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	lift = gcnew cLiftSystem();
	lift->elevator->LinkTo(lblElevator);
	lift->door->LinkTo(lblDoor);
	lift->F0->LinkTo(btnF0);
	lift->F1->LinkTo(btnF1);
	lift->F2->LinkTo(btnF2);
	lift->F3->LinkTo(btnF3);
	lift->indicator->LinkTo(lblIndicator);
}
System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	lift->door->Block();
}
System::Void Form1::btnF0_Click(System::Object^  sender, System::EventArgs^  e)
{
	lift->F0->InvokePress();
}
System::Void Form1::btnF1_Click(System::Object^  sender, System::EventArgs^  e)
{
	lift->F1->InvokePress();
}
System::Void Form1::btnF2_Click(System::Object^  sender, System::EventArgs^  e)
{
	lift->F2->InvokePress();
}
System::Void Form1::btnF3_Click(System::Object^  sender, System::EventArgs^  e)
{
	lift->F3->InvokePress();
}
System::Void Form1::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	static int ticker=0;
	if (ticker == 0)
		lblClock->Text = "[|]";
	if (ticker == 1)
		lblClock->Text = "[/]";
	if (ticker == 2)
		lblClock->Text = "[–]";
	if (ticker == 3)
		lblClock->Text = "[\\]";

	lift->Think();

	ticker++;
	if (ticker == 4)
		ticker = 0;
}