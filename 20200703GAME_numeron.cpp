#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//増えた変数宣言の数と行数はどちらも変わらない
//好みと分かりやすさの問題
//int main　内を見て分かりやすいのはポインタ側、スマートなのはbool側

//whileの終了条件をbool* eatjudge で持ってきた場合

void EnemyInput(int Enumber[], int size);
void Input(int PlayerInput[]);
void Comparison(int Enumber[], int playerInput[],int eat,int byte,bool* eatjudge);


int main()
{
	int Enumber[3] = {};
	int playerInput[3] = {};
	int byte = 0;
	int eat = 0;
	bool judge = true;
	bool* eatjudge = &judge;
	srand((unsigned)time(NULL));

	EnemyInput(Enumber, 3);

	printf("三桁入力してください\n");

	while (judge)
	{
		Input(playerInput);
		Comparison(Enumber, playerInput, eat, byte,eatjudge);

	}

	printf("結果：");
	for (int i = 0; i < 3; i++)
	{
		printf("%d", Enumber[i]);
	}
	printf("\n");
}

void EnemyInput(int Enumber[], int size)
{
	while (true)
	{
		if (Enumber[0] == Enumber[1] || Enumber[1] == Enumber[2] || Enumber[2] == Enumber[0])
		{
			for (int i = 0; i < size; i++)
			{
				Enumber[i] = (rand() % 9) + 1;
			}
		}
		else
		{
			break;
		}
	}
}


void Input(int PlayerInput[])
{
	for (int j = 0; j < 3; j++)
	{
		scanf_s("%d", &PlayerInput[j]);
	}
}


void Comparison(int Enumber[], int playerInput[], int eat, int byte,bool* eatjudge)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (Enumber[i] == playerInput[j])
			{
				if (i == j)
				{
					eat += 1;
				}
				else
				{
					byte += 1;
				}
			}
		}
	}
	printf("%dByte%dEat\n", byte, eat);
	if (eat == 3)
	{
		*eatjudge = false;
	}
	byte = 0;
	eat = 0;

}
///////////////////////////////////////////////////////////////////////

/*		whileの終了条件(eat)をポインタで持ってきた場合
void EnemyInput(int Enumber[], int size);
void Input(int PlayerInput[]);
void Comparison(int Enumber[], int playerInput[], int* eat, int* byte);


int main()
{
	int Enumber[3]      = {};
	int playerInput[3]  = {};
	int byte		    = 0;
	int eat			    = 0;
	int* eat1 = &eat;
	int* byte1 = &byte;
	srand((unsigned)time(NULL));

	EnemyInput(Enumber, 3 );

	
	printf("三桁入力してください\n");

	while (true)
	{
		Input(playerInput);
		Comparison(Enumber, playerInput, eat1, byte1);
		if (eat == 3)
		{
			break;
		}
	}

	printf("結果：");
	for (int i = 0; i < 3; i ++ )
	{
		printf("%d", Enumber[i]);
	}
	printf("\n");
}

void EnemyInput(int Enumber[], int size)
{
	while (true)
	{
		if (Enumber[0] == Enumber[1] || Enumber[1] == Enumber[2] || Enumber[2] == Enumber[0])
		{
			for (int i = 0; i < size; i++)
			{
				Enumber[i] = (rand() % 9) + 1;
			}
		}
		else
		{
			break;
		}
	}

}


void Input(int PlayerInput[])
{
	for (int j = 0; j < 3; j++)
	{
		scanf_s("%d", &PlayerInput[j]);
	}
}


void Comparison(int Enumber[], int playerInput[], int* eat, int* byte)
{
	*byte = 0;
	*eat = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (Enumber[i] == playerInput[j])
			{
				if (i == j)
				{
					*eat += 1;
				}
				else
				{
					*byte += 1;
				}

			}

		}

	}
	printf("%dByte%dEat\n", *byte, *eat);
	

}*/

