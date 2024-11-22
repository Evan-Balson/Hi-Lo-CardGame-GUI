
# include "processing.h"
#include <msclr/marshal_cppstd.h>

namespace CodeChallengeCardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	string active_DealersCard="";
	string active_Guess="";
	int score = 0;
	ScoreManager HScore;
	




	/// <summary>
	/// Summary for CardGameApp
	/// </summary>
	public ref class CardGameApp : public System::Windows::Forms::Form
	{
	public:
		CardGameApp(void)
		{
			InitializeComponent();

			
			HScore.readHighScores("highscores.txt");

			vector<string>names = HScore.getScoreNames();

			if (names.empty()) {

				HScore.writeDemoDataToFile("highscores.txt");
				HScore.readHighScores("highscores.txt");

			}
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CardGameApp()
		{
			if (game) {
				delete game;
				game = nullptr;
			}

			if (components)
			{
				delete components;
			}
		}
	private: Game* game = nullptr; // point to the game object
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ DisplayScore;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ DealersDraw;
	private: System::Windows::Forms::PictureBox^ YourGuess;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ Status;
	private: System::Windows::Forms::Panel^ StartPage;

	private: System::Windows::Forms::Button^ start;
	private: System::Windows::Forms::Panel^ EndPage;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ YouWinPage;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ nextRound;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ tryAgain;
	private: System::Windows::Forms::Button^ PlayAgain;
	private: System::Windows::Forms::Button^ ViewScores;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ HideScores;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ Player4;

	private: System::Windows::Forms::Label^ Player3;

	private: System::Windows::Forms::Label^ Player2;


	private: System::Windows::Forms::Label^ Player1;
	private: System::Windows::Forms::Label^ Player4Score;
	private: System::Windows::Forms::Label^ Player3Score;



	private: System::Windows::Forms::Label^ Player2Score;



	private: System::Windows::Forms::Label^ Player1Score;
	private: System::Windows::Forms::Label^ Player7;


	private: System::Windows::Forms::Label^ Player6;

	private: System::Windows::Forms::Label^ Player5;
	private: System::Windows::Forms::Label^ Player7Score;
	private: System::Windows::Forms::Label^ Player6Score;
	private: System::Windows::Forms::Label^ Player5Score;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ nameInput;

	private: System::Windows::Forms::Button^ nameSubmit;
	private: System::Windows::Forms::Label^ withJoker;

















	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardGameApp::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DisplayScore = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->nextRound = (gcnew System::Windows::Forms::Button());
			this->DealersDraw = (gcnew System::Windows::Forms::PictureBox());
			this->YourGuess = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->StartPage = (gcnew System::Windows::Forms::Panel());
			this->withJoker = (gcnew System::Windows::Forms::Label());
			this->ViewScores = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Player7 = (gcnew System::Windows::Forms::Label());
			this->Player6 = (gcnew System::Windows::Forms::Label());
			this->Player5 = (gcnew System::Windows::Forms::Label());
			this->Player4 = (gcnew System::Windows::Forms::Label());
			this->Player3 = (gcnew System::Windows::Forms::Label());
			this->Player2 = (gcnew System::Windows::Forms::Label());
			this->Player1 = (gcnew System::Windows::Forms::Label());
			this->HideScores = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->Player7Score = (gcnew System::Windows::Forms::Label());
			this->Player6Score = (gcnew System::Windows::Forms::Label());
			this->Player5Score = (gcnew System::Windows::Forms::Label());
			this->Player4Score = (gcnew System::Windows::Forms::Label());
			this->Player3Score = (gcnew System::Windows::Forms::Label());
			this->Player2Score = (gcnew System::Windows::Forms::Label());
			this->Player1Score = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->EndPage = (gcnew System::Windows::Forms::Panel());
			this->tryAgain = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->YouWinPage = (gcnew System::Windows::Forms::Panel());
			this->PlayAgain = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nameInput = (gcnew System::Windows::Forms::TextBox());
			this->nameSubmit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DealersDraw))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YourGuess))->BeginInit();
			this->StartPage->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->EndPage->SuspendLayout();
			this->YouWinPage->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(51, 150);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(263, 80);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Higher";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CardGameApp::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(313, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Place Your Bet:";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(51, 236);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(263, 80);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Lower";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CardGameApp::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(56, 384);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(270, 54);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Your Score:";
			// 
			// DisplayScore
			// 
			this->DisplayScore->AutoSize = true;
			this->DisplayScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayScore->Location = System::Drawing::Point(49, 462);
			this->DisplayScore->Name = L"DisplayScore";
			this->DisplayScore->Size = System::Drawing::Size(277, 91);
			this->DisplayScore->TabIndex = 4;
			this->DisplayScore->Text = L"523pts";
			this->DisplayScore->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::PaleGreen;
			this->panel1->Controls->Add(this->DisplayScore);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(766, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(353, 670);
			this->panel1->TabIndex = 7;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleGreen;
			this->panel2->Controls->Add(this->nextRound);
			this->panel2->Location = System::Drawing::Point(766, 138);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(353, 237);
			this->panel2->TabIndex = 8;
			this->panel2->Visible = false;
			// 
			// nextRound
			// 
			this->nextRound->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nextRound->Location = System::Drawing::Point(51, 81);
			this->nextRound->Name = L"nextRound";
			this->nextRound->Size = System::Drawing::Size(263, 80);
			this->nextRound->TabIndex = 0;
			this->nextRound->Text = L"Next Round";
			this->nextRound->UseVisualStyleBackColor = true;
			this->nextRound->Click += gcnew System::EventHandler(this, &CardGameApp::nextRound_Click);
			// 
			// DealersDraw
			// 
			this->DealersDraw->BackColor = System::Drawing::Color::Transparent;
			this->DealersDraw->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DealersDraw.Image")));
			this->DealersDraw->Location = System::Drawing::Point(31, 127);
			this->DealersDraw->Name = L"DealersDraw";
			this->DealersDraw->Size = System::Drawing::Size(342, 473);
			this->DealersDraw->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->DealersDraw->TabIndex = 5;
			this->DealersDraw->TabStop = false;
			// 
			// YourGuess
			// 
			this->YourGuess->BackColor = System::Drawing::Color::Transparent;
			this->YourGuess->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"YourGuess.Image")));
			this->YourGuess->Location = System::Drawing::Point(386, 127);
			this->YourGuess->Name = L"YourGuess";
			this->YourGuess->Size = System::Drawing::Size(342, 473);
			this->YourGuess->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->YourGuess->TabIndex = 6;
			this->YourGuess->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightGreen;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(141, 603);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 22);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Dealer\'s Hand";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::LightGreen;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(504, 603);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 22);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Your Hand";
			// 
			// Status
			// 
			this->Status->AutoSize = true;
			this->Status->BackColor = System::Drawing::Color::Gold;
			this->Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Status->Location = System::Drawing::Point(205, 43);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(376, 54);
			this->Status->TabIndex = 5;
			this->Status->Text = L"You WIN! +10pts";
			this->Status->Visible = false;
			// 
			// StartPage
			// 
			this->StartPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartPage.BackgroundImage")));
			this->StartPage->Controls->Add(this->withJoker);
			this->StartPage->Controls->Add(this->ViewScores);
			this->StartPage->Controls->Add(this->panel3);
			this->StartPage->Controls->Add(this->start);
			this->StartPage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->StartPage->Location = System::Drawing::Point(0, 0);
			this->StartPage->Name = L"StartPage";
			this->StartPage->Size = System::Drawing::Size(1114, 663);
			this->StartPage->TabIndex = 9;
			// 
			// withJoker
			// 
			this->withJoker->AutoSize = true;
			this->withJoker->BackColor = System::Drawing::Color::Transparent;
			this->withJoker->Cursor = System::Windows::Forms::Cursors::Hand;
			this->withJoker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->withJoker->ForeColor = System::Drawing::Color::Gold;
			this->withJoker->Location = System::Drawing::Point(439, 404);
			this->withJoker->Name = L"withJoker";
			this->withJoker->Size = System::Drawing::Size(324, 29);
			this->withJoker->TabIndex = 3;
			this->withJoker->Text = L"Click here to play with Jokers";
			this->withJoker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->withJoker->Click += gcnew System::EventHandler(this, &CardGameApp::withJoker_Click);
			// 
			// ViewScores
			// 
			this->ViewScores->BackColor = System::Drawing::Color::Gold;
			this->ViewScores->FlatAppearance->BorderSize = 0;
			this->ViewScores->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ViewScores->Location = System::Drawing::Point(881, 43);
			this->ViewScores->Name = L"ViewScores";
			this->ViewScores->Size = System::Drawing::Size(205, 54);
			this->ViewScores->TabIndex = 2;
			this->ViewScores->Text = L"See Top Scores";
			this->ViewScores->UseVisualStyleBackColor = false;
			this->ViewScores->Click += gcnew System::EventHandler(this, &CardGameApp::ViewScores_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::PaleGreen;
			this->panel3->Controls->Add(this->Player7);
			this->panel3->Controls->Add(this->Player6);
			this->panel3->Controls->Add(this->Player5);
			this->panel3->Controls->Add(this->Player4);
			this->panel3->Controls->Add(this->Player3);
			this->panel3->Controls->Add(this->Player2);
			this->panel3->Controls->Add(this->Player1);
			this->panel3->Controls->Add(this->HideScores);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Location = System::Drawing::Point(881, 104);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(205, 411);
			this->panel3->TabIndex = 1;
			this->panel3->Visible = false;
			// 
			// Player7
			// 
			this->Player7->AutoSize = true;
			this->Player7->Location = System::Drawing::Point(18, 268);
			this->Player7->Name = L"Player7";
			this->Player7->Size = System::Drawing::Size(69, 16);
			this->Player7->TabIndex = 11;
			this->Player7->Text = L"7. Player 7";
			// 
			// Player6
			// 
			this->Player6->AutoSize = true;
			this->Player6->Location = System::Drawing::Point(18, 228);
			this->Player6->Name = L"Player6";
			this->Player6->Size = System::Drawing::Size(69, 16);
			this->Player6->TabIndex = 10;
			this->Player6->Text = L"6. Player 6";
			// 
			// Player5
			// 
			this->Player5->AutoSize = true;
			this->Player5->Location = System::Drawing::Point(18, 186);
			this->Player5->Name = L"Player5";
			this->Player5->Size = System::Drawing::Size(69, 16);
			this->Player5->TabIndex = 9;
			this->Player5->Text = L"5. Player 5";
			// 
			// Player4
			// 
			this->Player4->AutoSize = true;
			this->Player4->Location = System::Drawing::Point(18, 144);
			this->Player4->Name = L"Player4";
			this->Player4->Size = System::Drawing::Size(69, 16);
			this->Player4->TabIndex = 8;
			this->Player4->Text = L"4. Player 4";
			// 
			// Player3
			// 
			this->Player3->AutoSize = true;
			this->Player3->Location = System::Drawing::Point(18, 100);
			this->Player3->Name = L"Player3";
			this->Player3->Size = System::Drawing::Size(69, 16);
			this->Player3->TabIndex = 7;
			this->Player3->Text = L"3. Player 3";
			// 
			// Player2
			// 
			this->Player2->AutoSize = true;
			this->Player2->Location = System::Drawing::Point(18, 58);
			this->Player2->Name = L"Player2";
			this->Player2->Size = System::Drawing::Size(69, 16);
			this->Player2->TabIndex = 6;
			this->Player2->Text = L"2. Player 2";
			// 
			// Player1
			// 
			this->Player1->AutoSize = true;
			this->Player1->Location = System::Drawing::Point(18, 16);
			this->Player1->Name = L"Player1";
			this->Player1->Size = System::Drawing::Size(69, 16);
			this->Player1->TabIndex = 5;
			this->Player1->Text = L"1. Player 1";
			// 
			// HideScores
			// 
			this->HideScores->BackColor = System::Drawing::Color::Gold;
			this->HideScores->FlatAppearance->BorderSize = 0;
			this->HideScores->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HideScores->Location = System::Drawing::Point(0, 356);
			this->HideScores->Name = L"HideScores";
			this->HideScores->Size = System::Drawing::Size(205, 54);
			this->HideScores->TabIndex = 3;
			this->HideScores->Text = L"Hide Scores";
			this->HideScores->UseVisualStyleBackColor = false;
			this->HideScores->Visible = false;
			this->HideScores->Click += gcnew System::EventHandler(this, &CardGameApp::HideScores_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::LightCyan;
			this->panel4->Controls->Add(this->Player7Score);
			this->panel4->Controls->Add(this->Player6Score);
			this->panel4->Controls->Add(this->Player5Score);
			this->panel4->Controls->Add(this->Player4Score);
			this->panel4->Controls->Add(this->Player3Score);
			this->panel4->Controls->Add(this->Player2Score);
			this->panel4->Controls->Add(this->Player1Score);
			this->panel4->Location = System::Drawing::Point(146, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(65, 411);
			this->panel4->TabIndex = 4;
			// 
			// Player7Score
			// 
			this->Player7Score->AutoSize = true;
			this->Player7Score->Location = System::Drawing::Point(13, 267);
			this->Player7Score->Name = L"Player7Score";
			this->Player7Score->Size = System::Drawing::Size(14, 16);
			this->Player7Score->TabIndex = 12;
			this->Player7Score->Text = L"0";
			this->Player7Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player6Score
			// 
			this->Player6Score->AutoSize = true;
			this->Player6Score->Location = System::Drawing::Point(13, 227);
			this->Player6Score->Name = L"Player6Score";
			this->Player6Score->Size = System::Drawing::Size(14, 16);
			this->Player6Score->TabIndex = 11;
			this->Player6Score->Text = L"0";
			this->Player6Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player5Score
			// 
			this->Player5Score->AutoSize = true;
			this->Player5Score->Location = System::Drawing::Point(13, 186);
			this->Player5Score->Name = L"Player5Score";
			this->Player5Score->Size = System::Drawing::Size(14, 16);
			this->Player5Score->TabIndex = 10;
			this->Player5Score->Text = L"0";
			this->Player5Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player4Score
			// 
			this->Player4Score->AutoSize = true;
			this->Player4Score->Location = System::Drawing::Point(13, 144);
			this->Player4Score->Name = L"Player4Score";
			this->Player4Score->Size = System::Drawing::Size(14, 16);
			this->Player4Score->TabIndex = 9;
			this->Player4Score->Text = L"0";
			this->Player4Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player3Score
			// 
			this->Player3Score->AutoSize = true;
			this->Player3Score->Location = System::Drawing::Point(13, 99);
			this->Player3Score->Name = L"Player3Score";
			this->Player3Score->Size = System::Drawing::Size(14, 16);
			this->Player3Score->TabIndex = 8;
			this->Player3Score->Text = L"0";
			this->Player3Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player2Score
			// 
			this->Player2Score->AutoSize = true;
			this->Player2Score->Location = System::Drawing::Point(13, 58);
			this->Player2Score->Name = L"Player2Score";
			this->Player2Score->Size = System::Drawing::Size(14, 16);
			this->Player2Score->TabIndex = 7;
			this->Player2Score->Text = L"0";
			this->Player2Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Player1Score
			// 
			this->Player1Score->AutoSize = true;
			this->Player1Score->Location = System::Drawing::Point(13, 16);
			this->Player1Score->Name = L"Player1Score";
			this->Player1Score->Size = System::Drawing::Size(14, 16);
			this->Player1Score->TabIndex = 6;
			this->Player1Score->Text = L"0";
			this->Player1Score->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// start
			// 
			this->start->BackColor = System::Drawing::Color::Gold;
			this->start->FlatAppearance->BorderSize = 0;
			this->start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(431, 280);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(274, 95);
			this->start->TabIndex = 0;
			this->start->Text = L"START";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &CardGameApp::start_Click);
			// 
			// EndPage
			// 
			this->EndPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EndPage.BackgroundImage")));
			this->EndPage->Controls->Add(this->tryAgain);
			this->EndPage->Controls->Add(this->label10);
			this->EndPage->Controls->Add(this->label6);
			this->EndPage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->EndPage->Location = System::Drawing::Point(0, 0);
			this->EndPage->Name = L"EndPage";
			this->EndPage->Size = System::Drawing::Size(1114, 663);
			this->EndPage->TabIndex = 10;
			this->EndPage->Visible = false;
			// 
			// tryAgain
			// 
			this->tryAgain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tryAgain->Location = System::Drawing::Point(410, 461);
			this->tryAgain->Name = L"tryAgain";
			this->tryAgain->Size = System::Drawing::Size(278, 62);
			this->tryAgain->TabIndex = 2;
			this->tryAgain->Text = L"Try Again";
			this->tryAgain->UseVisualStyleBackColor = true;
			this->tryAgain->Click += gcnew System::EventHandler(this, &CardGameApp::tryAgain_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Gold;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(271, 302);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(709, 135);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Game Over!";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Gold;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(242, 219);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(767, 69);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Wrong Choice, Game Over!";
			// 
			// YouWinPage
			// 
			this->YouWinPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"YouWinPage.BackgroundImage")));
			this->YouWinPage->Controls->Add(this->PlayAgain);
			this->YouWinPage->Controls->Add(this->label9);
			this->YouWinPage->Controls->Add(this->label8);
			this->YouWinPage->Controls->Add(this->label7);
			this->YouWinPage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->YouWinPage->Location = System::Drawing::Point(0, 0);
			this->YouWinPage->Name = L"YouWinPage";
			this->YouWinPage->Size = System::Drawing::Size(1114, 663);
			this->YouWinPage->TabIndex = 11;
			this->YouWinPage->Visible = false;
			// 
			// PlayAgain
			// 
			this->PlayAgain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayAgain->Location = System::Drawing::Point(422, 470);
			this->PlayAgain->Name = L"PlayAgain";
			this->PlayAgain->Size = System::Drawing::Size(278, 62);
			this->PlayAgain->TabIndex = 3;
			this->PlayAgain->Text = L"Try Again";
			this->PlayAgain->UseVisualStyleBackColor = true;
			this->PlayAgain->Click += gcnew System::EventHandler(this, &CardGameApp::PlayAgain_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Gold;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(433, 398);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(321, 42);
			this->label9->TabIndex = 2;
			this->label9->Text = L"The deck is empty";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Gold;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(392, 171);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(419, 69);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Congratulation";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Gold;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(346, 253);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(510, 135);
			this->label7->TabIndex = 0;
			this->label7->Text = L"You Win";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->nameInput);
			this->panel5->Controls->Add(this->nameSubmit);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1114, 663);
			this->panel5->TabIndex = 13;
			this->panel5->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Gold;
			this->label11->Location = System::Drawing::Point(387, 264);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(441, 29);
			this->label11->TabIndex = 6;
			this->label11->Text = L"Enter your name to join the leatherboard";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::Color::Gold;
			this->label3->Location = System::Drawing::Point(317, 165);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(613, 91);
			this->label3->TabIndex = 5;
			this->label3->Text = L"New HighScore!";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nameInput
			// 
			this->nameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameInput->Location = System::Drawing::Point(363, 343);
			this->nameInput->Name = L"nameInput";
			this->nameInput->Size = System::Drawing::Size(391, 34);
			this->nameInput->TabIndex = 4;
			// 
			// nameSubmit
			// 
			this->nameSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameSubmit->Location = System::Drawing::Point(418, 389);
			this->nameSubmit->Name = L"nameSubmit";
			this->nameSubmit->Size = System::Drawing::Size(278, 62);
			this->nameSubmit->TabIndex = 3;
			this->nameSubmit->Text = L"Submit";
			this->nameSubmit->UseVisualStyleBackColor = true;
			this->nameSubmit->Click += gcnew System::EventHandler(this, &CardGameApp::nameSubmit_Click);
			// 
			// CardGameApp
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1114, 663);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->YouWinPage);
			this->Controls->Add(this->EndPage);
			this->Controls->Add(this->StartPage);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->YourGuess);
			this->Controls->Add(this->DealersDraw);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"CardGameApp";
			this->Text = L"CardGameApp";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DealersDraw))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YourGuess))->EndInit();
			this->StartPage->ResumeLayout(false);
			this->StartPage->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->EndPage->ResumeLayout(false);
			this->EndPage->PerformLayout();
			this->YouWinPage->ResumeLayout(false);
			this->YouWinPage->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) {

	
	game = new Game(false);

	active_DealersCard = game->getDealersCard();


	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());
	try {
		std::string fullPath = nativeDirectory + "/Cards/" + active_DealersCard + ".png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		DealersDraw->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}
	StartPage->Visible = false;
	ViewScores->Visible = true;
	panel3->Visible = false;
	HideScores->Visible = false;
	ViewScores->Enabled = true;

}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


	active_Guess = game ->showNextCard();

	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());
	try {
		std::string fullPath = nativeDirectory + "/Cards/" + active_Guess + ".png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		YourGuess->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}

	bool result = game->processChoice('h');

	if(result){
		
		Status->Text = "Great job, you guessed right!";
		Status->Visible = true;
		panel2->Visible = true;
		score += 10;
		System::String^ Score = score.ToString();
		std::string convertScore = msclr::interop::marshal_as<std::string>(Score);

		convertScore += " pts";
		DisplayScore->Text = gcnew System::String(convertScore.c_str());
		DisplayScore->Visible = true;
	}
	else {
		bool topScore = HScore.checkIfHighScore(score);

		if (topScore) {

			EndPage->Visible = false;
			// ask to add to leather Board if player has topscore:
			panel5->Visible = true;
		}
		
		EndPage->Visible = true;

		delete game;  // Frees memory
		game = nullptr;  // Avoids dangling pointers
		
	}

}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	active_Guess = game->showNextCard();

	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());
	try {
		std::string fullPath = nativeDirectory + "/Cards/" + active_Guess + ".png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		YourGuess->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}

	bool result = game->processChoice('l');

	if (result) {
		Status->Text = "Great job, you guessed right!";
		Status->Visible = true;
		panel2->Visible = true;
		score += 10;
		System::String^ Score = score.ToString();
		std::string convertScore = msclr::interop::marshal_as<std::string>(Score);

		convertScore += " pts";
		DisplayScore->Text = gcnew System::String(convertScore.c_str());
		DisplayScore->Visible = true;
	}
	else {

		bool topScore = HScore.checkIfHighScore(score);

		if (topScore) {

			EndPage->Visible = false;
			// ask to add to leather Board if player has topscore:
			panel5->Visible = true;
		}

		// add to leather Board if player has topscore:

		EndPage->Visible = true;
		
		delete game;  // Frees memory
		game = nullptr;  // Avoids dangling pointers
	}
}


private: System::Void nextRound_Click(System::Object^ sender, System::EventArgs^ e) {


	bool checkDeck = game->isDeckEmpty();

	if (checkDeck) {
		bool topScore = HScore.checkIfHighScore(score);

		if (topScore) {
			// ask to add to leather Board if player has topscore:
			panel5->Visible = true;

		}

		YouWinPage->Visible = true;
	}
	else{

		std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());
		try {
			std::string fullPath = nativeDirectory + "/Cards/" + active_Guess + ".png";

			// Convert std::string to System::String^
			System::String^ managedPath = gcnew System::String(fullPath.c_str());

			// Assign the image to the PictureBox
			DealersDraw->Image = System::Drawing::Image::FromFile(managedPath);
		}
		catch (System::IO::FileNotFoundException^ ex) {
			MessageBox::Show("Image file not found: " + ex->Message);
		}

		try {
			std::string fullPath = nativeDirectory + "/Cards/cardBack.png";

			// Convert std::string to System::String^
			System::String^ managedPath = gcnew System::String(fullPath.c_str());

			// Assign the image to the PictureBox
			YourGuess->Image = System::Drawing::Image::FromFile(managedPath);
		}
		catch (System::IO::FileNotFoundException^ ex) {
			MessageBox::Show("Image file not found: " + ex->Message);
		}

		Status->Text = "";
		Status->Visible = false;

		panel2->Visible = false;

		active_Guess = game->advanceToNextCard();

		
		

	}
}
private: System::Void tryAgain_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	StartPage->Visible = true;
	EndPage->Visible = false;
	score = 0;
	System::String^ Score = score.ToString();
	std::string convertScore = msclr::interop::marshal_as<std::string>(Score);

	convertScore += " pts";
	DisplayScore->Text = gcnew System::String(convertScore.c_str());
	DisplayScore->Visible = true;


	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());

	try {
		std::string fullPath = nativeDirectory + "/Cards/cardBack.png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		YourGuess->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}


	Status->Text = "";
	Status->Visible = false;

	panel2->Visible = false;


}
private: System::Void PlayAgain_Click(System::Object^ sender, System::EventArgs^ e) {

	StartPage->Visible = true;
	EndPage->Visible = false;
	score = 0;
	System::String^ Score = score.ToString();
	std::string convertScore = msclr::interop::marshal_as<std::string>(Score);

	convertScore += " pts";
	DisplayScore->Text = gcnew System::String(convertScore.c_str());
	DisplayScore->Visible = true;

	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());

	try {
		std::string fullPath = nativeDirectory + "/Cards/cardBack.png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		YourGuess->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}

	bool topScore = HScore.checkIfHighScore(score);

	if (topScore) {
		// ask to add to leather Board if player has topscore:
		panel5->Visible = true;

	}

	delete game;  // Frees memory
	game = nullptr;  // Avoids dangling pointers

	Status->Text = "";
	Status->Visible = false;

	panel2->Visible = false;
	YouWinPage->Visible = false;

}
private: System::Void ViewScores_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<string> playerNames = HScore.getScoreNames();
	vector<int>playerScores = HScore.getScores();
	if(playerNames.empty()){
	// populate with filler
	}
	if (playerScores.empty()) {
		//populate with filler
	}

	if (playerNames.size() >= 7 && playerScores.size() >= 7) {
		Player1->Text = "1. " + gcnew System::String(playerNames[0].c_str());
		Player2->Text = "2. " + gcnew System::String(playerNames[1].c_str());
		Player3->Text = "3. " + gcnew System::String(playerNames[2].c_str());
		Player4->Text = "4. " + gcnew System::String(playerNames[3].c_str());
		Player5->Text = "5. " + gcnew System::String(playerNames[4].c_str());
		Player6->Text = "6. " + gcnew System::String(playerNames[5].c_str());
		Player7->Text = "7. " + gcnew System::String(playerNames[6].c_str());

		Player1Score->Text = playerScores[0].ToString();
		Player2Score->Text = playerScores[1].ToString();
		Player3Score->Text = playerScores[2].ToString();
		Player4Score->Text = playerScores[3].ToString();
		Player5Score->Text = playerScores[4].ToString();
		Player6Score->Text = playerScores[5].ToString();
		Player7Score->Text = playerScores[6].ToString();
	}
	else {
		MessageBox::Show("High score data is incomplete or unavailable.");
	}

	panel3->Visible = true;
	HideScores->Visible = true;
	ViewScores->Enabled = false;

}
private: System::Void HideScores_Click(System::Object^ sender, System::EventArgs^ e) {

	panel3->Visible = false;
	HideScores->Visible = false;
	ViewScores->Enabled = true;

}
private: System::Void nameSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if the text field is not blank
	if (!String::IsNullOrWhiteSpace(nameInput->Text)) {
		// Convert the managed string from the input field to a standard C++ string
		std::string name = msclr::interop::marshal_as<std::string>(nameInput->Text);

		// Update the high scores with the new name and current score
		HScore.updateTopScores(name, score);
		HScore.writeHighScores("highscores.txt");

		// Provide feedback to the user
		MessageBox::Show("Score submitted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		panel5->Visible = false;
		panel3->Visible = false;
		HideScores->Visible = false;
		ViewScores->Enabled = true;
	}
	else {
		// If the text field is blank, alert the user
		MessageBox::Show("Name cannot be empty. Please enter a valid name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void withJoker_Click(System::Object^ sender, System::EventArgs^ e) {

	game = new Game(true);

	active_DealersCard = game->getDealersCard();


	std::string nativeDirectory = msclr::interop::marshal_as<std::string>(System::IO::Directory::GetCurrentDirectory());
	try {
		std::string fullPath = nativeDirectory + "/Cards/" + active_DealersCard + ".png";

		// Convert std::string to System::String^
		System::String^ managedPath = gcnew System::String(fullPath.c_str());

		// Assign the image to the PictureBox
		DealersDraw->Image = System::Drawing::Image::FromFile(managedPath);
	}
	catch (System::IO::FileNotFoundException^ ex) {
		MessageBox::Show("Image file not found: " + ex->Message);
	}
	StartPage->Visible = false;
	ViewScores->Visible = true;


}

};
}
