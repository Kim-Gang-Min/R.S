#include "poker_header.h"

void setColor(int back, int text)
{
	HANDLE hcon;

	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, (back << 4) | text);
}

void init()
{
	system("mode con cols=176 lines=45 | title �ػ罺 Ȧ�� ");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	system("color F5");
	//setColor(WHITE, GREEN); // ����ȭ�� ���鶧 ���..
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void introGame()
{
	setColor(WHITE, BLACK);
	gotoxy(45, 5); cout << "       ������     ������     ��      ��         ��         ������";
	gotoxy(45, 6); cout << "           ��         ��               ��  ��         ��  ��       ��        ";
	gotoxy(45, 7); cout << "           ��         ������         ��         ������       ����  ";
	gotoxy(45, 8); cout << "           ��         ��               ��  ��       ��      ��             ��";
	gotoxy(45, 9); cout << "           ��         ������     ��      ��     ��      ��     ������";
	gotoxy(45, 10); cout << "																			 ";
	gotoxy(45, 12); cout << " ��      ��     ������     ��             �����       ������     ��      ��";
	gotoxy(45, 13); cout << " ��      ��     ��      ��     ��             ��     ��      ��             ���  ���";
	gotoxy(45, 14); cout << " ������     ��      ��     ��             ��      ��     ������     ��  ��  ��";
	gotoxy(45, 15); cout << " ��      ��     ��      ��     ��             ��     ��      ��             ��      ��";
	gotoxy(45, 16); cout << " ��      ��     ������     ������     �����       ������     ��      ��";
	gotoxy(82, 25); cout << "[���ӽ���]";
	gotoxy(82, 26); cout << "[���ӱ�Ģ]";
	gotoxy(82, 27); cout << "[��������]";
}

int keyControl()
{
	char c;
	while (1) {
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();

				if (c == UP)
					return UP;
				else if (c == DOWN)
					return DOWN;
				else if (c == RIGHT)
					return RIGHT;
				else if (c == LEFT)
					return LEFT;
			}
			else if (c == CHOICE)
				return CHOICE;
		}
	}
}

int menuChoice()
{
	int x = 82;
	int y = 25;
	gotoxy(x - 2, y); cout << "> [���ӽ���]";
	gotoxy(x, y + 1); cout << "[���ӱ�Ģ]";
	gotoxy(x, y + 2); cout << "[��������]";
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 25) {
				gotoxy(x - 2, y); cout << " ";
				gotoxy(x - 2, --y); cout << ">";
			}
			break;
		}

		case DOWN:
		{
			if (y < 27)
			{
				gotoxy(x - 2, y); cout << " ";
				gotoxy(x - 2, ++y); cout << ">";
			}
			break;
		}

		case CHOICE:
		{
			return y - 25;
		}

		}
	}

}

void gameImage()
{
	int x = 65;
	int y = 40;
	system("color 02");
	system("cls");
	setColor(GREEN, GREEN);
	for (int i = 1; i < 35; i++)
	{
		gotoxy(30, i);
		cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
	}
	setColor(WHITE, WHITE);
	for (int i = 0; i < 35; i++)
	{
		gotoxy(29, i); cout << "��";
		gotoxy(145, i); cout << "��";
	}
	gotoxy(29, 0);	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
	gotoxy(29, 35); cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";

	player(10, 3);  cout << "����";
	player(10, 18); cout << "����";
	player(150, 3); cout << "����";
	player(150, 18); cout << "����";
	gotoxy(85, 36); cout << "������";

	gotoxy(x, y);  cout << "��";
	gotoxy(x + 10, y); cout << "����";
	gotoxy(x + 20, y); cout << "����";
	gotoxy(x + 30, y); cout << "����";
	gotoxy(x + 40, y); cout << "����";

	/*while (1)
	{
		if (keyControl() == CHOICE)
		{
			system("color F5");
			break;
		}
	}*/
}

void gameRule()
{
	system("cls");
	gotoxy(15, 10); cout << "�ػ罺 Ȧ�� ���� ���" << endl;
	gotoxy(15, 10); cout << "1. �÷��̾���� ���κ� ���� 2���� ī�带 �޽��ϴ�." << endl;
	gotoxy(15, 11); cout << "2. ��� �÷��̾���� �����ϴ� Ŀ�´�Ƽ ī�� 5���� �־����ϴ�." << endl;
	gotoxy(15, 12); cout << "3. Ŀ�´�Ƽ ī�� 5��� ���κ� ���� 2���� ī���� ������ ���� ���� �÷��̾ �¸��մϴ�." << endl;
	gotoxy(15, 13); cout << "ī�� ���տ� ���� �ڼ��� ������ �Ʒ� Ȩ�������� �����Ͻñ� �ٶ��ϴ�." << endl;
	gotoxy(15, 14); cout << "https://crash-landing.github.io" << endl;
	while (1)
	{
		if (keyControl() == CHOICE)
		{
			break;
		}
	}
}

void player(int x, int y)
{
	int coin = 50;
	setColor(BLACK, WHITE);
	gotoxy(x, y - 2); cout << "  ���� Ĩ: " << coin << endl;
	gotoxy(x, y);     cout << "���������\n";
	gotoxy(x, y + 1); cout << "���������\n";
	gotoxy(x, y + 2); cout << "���������\n";
	gotoxy(x, y + 3); cout << "���������\n";
	gotoxy(x, y + 4); cout << "���������\n";
	gotoxy(x, y + 5); cout << "���������\n\n";
	gotoxy(x, y + 6); cout << "���������\n\n";
	gotoxy(x, y + 8); cout << "  ������: ";
}

int bettingMenuChoice()
{
	setColor(BLACK, WHITE);
	int x = 65;
	int y = 40;
	gotoxy(x - 2, y);  cout << "> ��";
	gotoxy(x + 10, y); cout << "����";
	gotoxy(x + 20, y); cout << "����";
	gotoxy(x + 30, y); cout << "����";
	gotoxy(x + 40, y); cout << "����";
	while (1) {
		int n = keyControl();
		switch (n) {
		case RIGHT:
		{
			if (x < 105)
			{
				gotoxy(x - 2, y); cout << " ";
				x = x + 10;
				gotoxy(x - 2, y); cout << ">";
			}
			break;
		}

		case LEFT:
		{
			if (x > 65)
			{
				gotoxy(x - 2, y); cout << " ";
				x = x - 10;
				gotoxy(x - 2, y); cout << ">";
			}
			break;
		}

		case CHOICE:
		{
			gotoxy(x - 2, y); cout << " ";
			return x - 50;
		}
		}
	}

}
void bettingPrint(int x) //���� ���� ��� 
{
	int y = 12;
	switch (x / 10) {
	case 0:  // �� ȭ��
		setColor(GREEN, GREEN);
		for (int i = y; i < y + 5; i++)
		{
			gotoxy(45, i);
			cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
		}
		break;

	case 1: // ��
		gotoxy(45, y);   cout << "                ������         ��         ��           ��           ��           ";
		gotoxy(45, y + 1); cout << "                ��               ��  ��       ��           ��           ��           ";
		gotoxy(45, y + 2); cout << "                ��             ������     ��           ��           ��           ";
		gotoxy(45, y + 3); cout << "                ��             ��      ��     ��           ��                        ";
		gotoxy(45, y + 4); cout << "                ������     ��      ��     �����     �����     ��           ";
		break;

	case 2: // ����
		gotoxy(45, y);   cout << "                       �����         ����       �����     ��                   ";
		gotoxy(45, y + 1); cout << "                       ��     ��          ��         ��           ��                   ";
		gotoxy(45, y + 2); cout << "                       ��      ��         ��         �����     ��                   ";
		gotoxy(45, y + 3); cout << "                       ��     ��          ��         ��                                ";
		gotoxy(45, y + 4); cout << "                       �����         ����       �����     ��                   ";
		break;

	case 3: // ����
		gotoxy(45, y);   cout << " �����        �����      ��      ��     �����       ��           �����     ��   ";
		gotoxy(45, y + 1); cout << " ��     ��      ��      ��     ��      ��     ��     ��      ��           ��           ��   ";
		gotoxy(45, y + 2); cout << " ��      ��     ��      ��     ��      ��     �����       ��           �����     ��   ";
		gotoxy(45, y + 3); cout << " ��     ��      ��      ��     ��      ��     ��     ��      ��           ��                ";
		gotoxy(45, y + 4); cout << " �����        �����       �����      �����       �����     �����     ��   ";
		break;

	case 4: // ����
		gotoxy(45, y);   cout << "                ��      ��         ��         ��           �����     ��             ";
		gotoxy(45, y + 1); cout << "                ��      ��       ��  ��       ��           ��           ��             ";
		gotoxy(45, y + 2); cout << "                ������     ������     ��           �����     ��             ";
		gotoxy(45, y + 3); cout << "                ��      ��     ��      ��     ��           ��                          ";
		gotoxy(45, y + 4); cout << "                ��      ��     ��      ��     �����     ��           ��             ";
		break;

	case 5:  // ����
		gotoxy(45, y);   cout << "         ��         ��           ��                ����       ��      ��     ��      ";
		gotoxy(45, y + 1); cout << "       ��  ��       ��           ��                  ��         ���    ��     ��      ";
		gotoxy(45, y + 2); cout << "     ������     ��           ��                  ��         ��  ��  ��     ��      ";
		gotoxy(45, y + 3); cout << "     ��      ��     ��           ��                  ��         ��    ���             ";
		gotoxy(45, y + 4); cout << "     ��      ��     �����     �����          ����       ��      ��     ��      ";
		break;
	}
}

void bettingNumber()
{
	while (1) {
		int x = bettingMenuChoice(); // ���ø޴� ���� �Լ�
		setColor(GREEN, WHITE);
		bettingPrint(x);
		Sleep(1000);
		bettingPrint(0);
	}
}

void victoryPrint()
{
	gotoxy(80, 17); cout << "------------------------";
	gotoxy(80, 18); cout << "|                       |";
	gotoxy(80, 19); cout << "|      �¸�!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // ����ȭ���� ǥ�úκ� �Լ�
}

void defeatPrint()
{
	gotoxy(80, 17); cout << "------------------------";
	gotoxy(80, 18); cout << "|                       |";
	gotoxy(80, 19); cout << "|      �й�!!!!!!!      |";
	gotoxy(80, 20); cout << "|                       |";
	gotoxy(80, 21); cout << "------------------------";
	introGame(); // ����ȭ���� ǥ�úκ� �Լ�
}

void picture(int* num1_rand, int* shape_rand)
{
	setColor(GREEN, WHITE);
	int shape[5] = { 0,1,2,3,4 }; //null, spade, diamond, heart, cluber
	int number[14] = { 0,2,3,4,5,6,7,8,9,10,11,12,13,1 }; //null, 2~10, jack, queen, king, ace
	int x = 100, y = 14;
	int i, j, k, v = 1, hide = 0;		//hide 0 ����, 1 ǥ��
	int get = 4;
	int num1 = 0, num2 = 0;
	for (k = 0; k < 2; k++)
	{
		if (k == 0) // ���� �޸��� ����
		{
			for (i = 0; i < 4; i++) // ī�尡 �����Ǵ� �׷���
			{
				num1 = 0;
				for (j = 0; j < 15; j++)
				{
					Sleep(10);
					gotoxy(x - num1, 14); cout << "����������������";
					gotoxy(x - num1, 15); cout << "��?     ��";
					gotoxy(x - num1, 16); cout << "��      ��";
					gotoxy(x - num1, 17); cout << "��   ?  ��";
					gotoxy(x - num1, 18); cout << "��      ��";
					gotoxy(x - num1, 19); cout << "��     ?��";
					gotoxy(x - num1, 20); cout << "����������������";
					num1 += 1;
				}
				x += 2;
			}
			num1 = 0;
			for (i = 0; i < 15; i++) // ī�尡 ��еǴ� �׷���
			{
				num1 = 1;
				if (i % 2 == 1)
				{
					num1 *= -1;
				}
				for (j = 0; j < 7; j++)
				{
					Sleep(20);
					if (i % 2 == 0)
					{
						gotoxy(80 - num2, 21 - num1); cout << "          ";
					}
					gotoxy(80 - num2, 14 - num1); cout << "����������������";
					gotoxy(80 - num2, 15 - num1); cout << "��?     ��";
					gotoxy(80 - num2, 16 - num1); cout << "��      ��";
					gotoxy(80 - num2, 17 - num1); cout << "��   ?  ��";
					gotoxy(80 - num2, 18 - num1); cout << "��      ��";
					gotoxy(80 - num2, 19 - num1); cout << "��     ?��";
					gotoxy(80 - num2, 20 - num1); cout << "����������������";
					if (i % 2 == 1)
					{
						gotoxy(80 - num2, 13 - num1); cout << "          ";
					}
					if (i % 2 == 0)
						num1 += 1;
					else
						num1 -= 1;
				}
				num2 += 2;
			}
			system("cls");
			gameImage();
		}
		else // �ո��� ����
		{
			setColor(GREEN, WHITE);
			playerCard(35, 3);
			playerCard(125, 3);
			playerCard(35, 18);
			playerCard(125, 18);
			playerCard(80, 25);
			num1 = 0;
			j = 1;
			for (i = 0; i < 10; i++)
			{
				if (i % 2 == 0)
				{
					if (i > get)
					{
						get += 2;
						hide = 1;
						_getch();
					}
					gotoxy(60 + num1, 3); cout << "����������������";
					gotoxy(60 + num1, 4); cout << "��      ��";
					gotoxy(60 + num1, 5); cout << "��      ��";
					gotoxy(60 + num1, 6); cout << "��      ��";
					gotoxy(60 + num1, 7); cout << "��      ��";
					gotoxy(60 + num1, 8); cout << "��      ��";
					gotoxy(60 + num1, 9); cout << "����������������";
					//					if(hide != 1){
					if (shape[shape_rand[j]] == 1) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num1, 4); cout << "��";
						gotoxy(66 + num1, 8); cout << "��";
					}
					else if (shape[shape_rand[j]] == 2) {
						setColor(GREEN, RED);
						gotoxy(62 + num1, 4); cout << "��";
						gotoxy(66 + num1, 8); cout << "��";
					}
					else if (shape[shape_rand[j]] == 3) {
						setColor(GREEN, RED);
						gotoxy(62 + num1, 4); cout << "��";
						gotoxy(66 + num1, 8); cout << "��";
					}
					else if (shape[shape_rand[j]] == 4) {
						setColor(GREEN, BLACK);
						gotoxy(62 + num1, 4); cout << "��";
						gotoxy(66 + num1, 8); cout << "��";
					}
					if (number[num1_rand[j]] == 13) {
						gotoxy(65 + num1, 6); cout << "A";
					}
					else if (number[num1_rand[j]] == 10) {
						gotoxy(65 + num1, 6); cout << "J";
					}
					else if (number[num1_rand[j]] == 11) {
						gotoxy(65 + num1, 6); cout << "Q";
					}
					else if (number[num1_rand[j]] == 12) {
						gotoxy(65 + num1, 6); cout << "K";
					}
					else if (number[num1_rand[j]] == num1_rand[j] + 1) {
						gotoxy(65 + num1, 6); cout << num1_rand[j];
					}
					//					}
					num1 += 12;
					j++;			//�迭�� 1ĭ�� ���� ��Ų��.
				}
			}
		}
	}
}

void playerCard(int x, int y)
{
	gotoxy(x, y);   cout << "��������������������������������";
	gotoxy(x, y + 1); cout << "��      ����      ��";
	gotoxy(x, y + 2); cout << "��      ����      ��";
	gotoxy(x, y + 3); cout << "��      ����      ��";
	gotoxy(x, y + 4); cout << "��      ����      ��";
	gotoxy(x, y + 5); cout << "��      ����      ��";
	gotoxy(x, y + 6); cout << "��������������������������������";
}

void printOrder(int result, int i) //
{
	switch (result)
	{
	case 1:
		cout << "����ī��\n";
		break;
	case 2:
		cout << "�����\n";
		break;
	case 3:
		cout << "�����\n";
		break;
	case 4:
		cout << "Ʈ����\n";
		break;
	case 5:
		cout << "��Ʈ����Ʈ\n";
		break;
	case 6:
		cout << "�÷���\n";
		break;
	case 7:
		cout << "Ǯ�Ͽ콺\n";
		break;
	case 8:
		cout << "��ī��\n";
		break;
	case 9:
		cout << "��Ʈ����Ʈ �÷���\n";
		break;
	}
}