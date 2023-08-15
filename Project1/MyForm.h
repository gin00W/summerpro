#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			timer->Start();
			
			SetStyle(ControlStyles::AllPaintingInWmPaint | ControlStyles::DoubleBuffer | ControlStyles::UserPaint, true);
			UpdateStyles();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Timer^ timer;
		   int milliseconds = 0;
		   int seconds = 0;
		   int minutes = 0;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// listView1
			// 

			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(200, 100);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 10;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::TimerTick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(815, 402);
			this->Controls->Add(this->listView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->MaximizeBox = false;
			this->Text = L"Stopwatch";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Void TimerTick(System::Object^ sender, System::EventArgs^ e)
		{
			milliseconds += 10;
			if (milliseconds >= 1000)
			{
				milliseconds = 0;
				seconds++;

				if (seconds >= 60)
				{
					seconds = 0;
					minutes++;
				}
			}

			// 시간을 형식에 맞춰서 표시합니다.
			String^ time = String::Format("{0:D2}:{1:D2}", minutes, seconds);

			// ListView에 시간을 추가합니다.
			listView1->Items->Clear();
			listView1->Items->Add(time);
		}

#pragma endregion

	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
