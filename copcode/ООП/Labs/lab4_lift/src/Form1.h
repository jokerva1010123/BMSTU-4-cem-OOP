#pragma once
#include "lift_system.h"

namespace src {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnF0;
	private: System::Windows::Forms::Button^  btnF1;
	private: System::Windows::Forms::Button^  btnF2;
	private: System::Windows::Forms::Button^  btnF3;
	private: System::Windows::Forms::Label^  lblElevator;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblDoor;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  lblClock;
	private: System::Windows::Forms::Label^  lblIndicator;
	private: System::Windows::Forms::Label^  label4;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnF0 = (gcnew System::Windows::Forms::Button());
			this->btnF1 = (gcnew System::Windows::Forms::Button());
			this->btnF2 = (gcnew System::Windows::Forms::Button());
			this->btnF3 = (gcnew System::Windows::Forms::Button());
			this->lblElevator = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblDoor = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblClock = (gcnew System::Windows::Forms::Label());
			this->lblIndicator = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Block";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 91);
			this->label1->Margin = System::Windows::Forms::Padding(3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Lift:";
			// 
			// btnF0
			// 
			this->btnF0->Location = System::Drawing::Point(216, 143);
			this->btnF0->Name = L"btnF0";
			this->btnF0->Size = System::Drawing::Size(56, 23);
			this->btnF0->TabIndex = 0;
			this->btnF0->Text = L"0";
			this->btnF0->UseVisualStyleBackColor = true;
			this->btnF0->Click += gcnew System::EventHandler(this, &Form1::btnF0_Click);
			// 
			// btnF1
			// 
			this->btnF1->Location = System::Drawing::Point(216, 114);
			this->btnF1->Name = L"btnF1";
			this->btnF1->Size = System::Drawing::Size(56, 23);
			this->btnF1->TabIndex = 1;
			this->btnF1->Text = L"1";
			this->btnF1->UseVisualStyleBackColor = true;
			this->btnF1->Click += gcnew System::EventHandler(this, &Form1::btnF1_Click);
			// 
			// btnF2
			// 
			this->btnF2->Location = System::Drawing::Point(216, 85);
			this->btnF2->Name = L"btnF2";
			this->btnF2->Size = System::Drawing::Size(56, 23);
			this->btnF2->TabIndex = 2;
			this->btnF2->Text = L"2";
			this->btnF2->UseVisualStyleBackColor = true;
			this->btnF2->Click += gcnew System::EventHandler(this, &Form1::btnF2_Click);
			// 
			// btnF3
			// 
			this->btnF3->Location = System::Drawing::Point(216, 56);
			this->btnF3->Name = L"btnF3";
			this->btnF3->Size = System::Drawing::Size(56, 23);
			this->btnF3->TabIndex = 2;
			this->btnF3->Text = L"3";
			this->btnF3->UseVisualStyleBackColor = true;
			this->btnF3->Click += gcnew System::EventHandler(this, &Form1::btnF3_Click);
			// 
			// lblElevator
			// 
			this->lblElevator->AutoSize = true;
			this->lblElevator->Location = System::Drawing::Point(109, 91);
			this->lblElevator->Margin = System::Windows::Forms::Padding(3);
			this->lblElevator->Name = L"lblElevator";
			this->lblElevator->Size = System::Drawing::Size(35, 13);
			this->lblElevator->TabIndex = 3;
			this->lblElevator->Text = L"label2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 110);
			this->label2->Margin = System::Windows::Forms::Padding(3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Doors:";
			// 
			// lblDoor
			// 
			this->lblDoor->AutoSize = true;
			this->lblDoor->Location = System::Drawing::Point(109, 110);
			this->lblDoor->Margin = System::Windows::Forms::Padding(3);
			this->lblDoor->Name = L"lblDoor";
			this->lblDoor->Size = System::Drawing::Size(35, 13);
			this->lblDoor->TabIndex = 3;
			this->lblDoor->Text = L"label2";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// lblClock
			// 
			this->lblClock->AutoSize = true;
			this->lblClock->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblClock->Location = System::Drawing::Point(9, 240);
			this->lblClock->Name = L"lblClock";
			this->lblClock->Size = System::Drawing::Size(49, 14);
			this->lblClock->TabIndex = 4;
			this->lblClock->Text = L"label3";
			// 
			// lblIndicator
			// 
			this->lblIndicator->AutoSize = true;
			this->lblIndicator->Location = System::Drawing::Point(109, 72);
			this->lblIndicator->Margin = System::Windows::Forms::Padding(3);
			this->lblIndicator->Name = L"lblIndicator";
			this->lblIndicator->Size = System::Drawing::Size(35, 13);
			this->lblIndicator->TabIndex = 5;
			this->lblIndicator->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(52, 72);
			this->label4->Margin = System::Windows::Forms::Padding(3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Indicator:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->lblIndicator);
			this->Controls->Add(this->lblClock);
			this->Controls->Add(this->lblDoor);
			this->Controls->Add(this->lblElevator);
			this->Controls->Add(this->btnF3);
			this->Controls->Add(this->btnF2);
			this->Controls->Add(this->btnF1);
			this->Controls->Add(this->btnF0);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			cLiftSystem^ lift;

	private:
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnF0_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnF1_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnF2_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnF3_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
};
}

