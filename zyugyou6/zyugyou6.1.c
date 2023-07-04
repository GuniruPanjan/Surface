#include<stdio.h>


//‰Û‘è
int main(void)
{
	int answer = 0;
	int sum = 0;
	int a;

	for (a = 0; a <= 100; a++)
	{
		if (a % 7 != 0)continue;
		sum += a;
	}
	printf("‡Œv‚Í%d‚Å‚·\n", sum);

	//while•¶‚íg‚Á‚Ä‘‚«Š·‚¦
	int addNum = 7;
	while (addNum <= 100)
	{
		answer += addNum;
		addNum += 7;
	}

	for (int i = 1; ; i++)
	{
		if ((7 * i) > 100) 
		{
			break;
	    }
		answer += (i * 7);
	}
	int baseNum = 1;
	while (1) {
		int addNum = 7 * baseNum;
		if (addNum > 100) {
			break;
		}
		answer += addNum;
		baseNum;
	}
	
}

/*
//break,continue‚Ì•œK
int main(void)
{
	//ƒvƒŒƒCƒ„[‚ÌHP
	int playerHp = 50;
	//“G‚ÌUŒ‚—Í
	int enemyAttack = 3;
	//“G‚ÌUŒ‚‰ñ”
	int enemyAttackNum = 10;

	//“G‚ÌUŒ‚‰ñ”‰ñƒ_ƒ[ƒW‚ğ‹ò‚ç‚¤
	for (int i = 0; i < enemyAttackNum; i++)
	{
		printf("%d‰ñ–Ú‚ÌUŒ‚I\n", i + 1);

		//Šï”‰ñ–Ú‚ÌUŒ‚‚ğó‚¯‚é
		//‹ô”‰ñ–Ú‚ÌUŒ‚‚ğ‰ñ”ğ‚·‚é
		//UŒ‚‰ñ”‚ÍŠï”‚ÌAi‚Ì’l‚Í‹ô”@‹t‚à‚Ü‚½‘R‚è
		//i‚ªŠï”‚Ì‚Écontinue‚·‚é
		if (i % 2 == 1)
		{
			printf("‰ñ”ğ‚µ‚½I\n");
		    continue;
		}
		playerHp -= enemyAttack;
		printf("c‚èHP%d\n", playerHp);

		//hp‚ª0‚É‚È‚Á‚½‚çUŒ‚‚ğ‚â‚ß‚é
		if (playerHp <= 0)
		{
			printf("€‚ñ‚Å‚µ‚Ü‚Á‚½\n");
			break;  //break‚ÅŒJ‚è•Ô‚µ‚ğ‹­§“I‚É‚â‚ß‚é
		}
	}

	while (1)
	{
		printf("–³ŒÀƒ‹[ƒv\n");
		if (1)
		{
			printf("–³ŒÀƒ‹[ƒv”²‚¯‚é\n");
			break;
		}
	}
}
*/
/*
//for•¶‚Ì•œK
int main(void)
{
	//Œˆ‚Ü‚Á‚½‰ñ”‚ğŒJ‚è•Ô‚·ê‡forg‚¤‚±‚Æ‚ª‘½‚¢
	for (
		int i = 0;  //for•¶‚Ì‰Šú‰»ˆ—
		i < 5;        //ŒJ‚è•Ô‚µğŒ
		i++         //Œp‘±ˆ—@ŒJ‚è•Ô‚³‚ê‚é’†g‚ªI‚í‚Á‚½ŒãÀs‚³‚ê‚é
		) 
	{
		//ŒJ‚è•Ô‚³‚ê‚é’†g
	}

	//‚«‚ê‚¢‚É‘‚«’¼‚µ
	int loopNum = 16;
	for (int i = 0; i < loopNum, i++);
	{
		printf("%d‰ñ–Ú‚ÌŒJ‚è•Ô‚µ\n", i + 1);
	}

	//‰½‚©‚µ‚ç‚ÌğŒ‚ğ–‚½‚·‚Ü‚ÅŒJ‚è•Ô‚·ê‡while‚ğg‚¤‚±‚Æ‚ª‘½‚¢
	int playerHp = 50;
	//ƒvƒŒƒCƒ„[‚ÌHP‚ª0ˆÈ‰º‚É‚È‚é‚Ü‚Åƒ_ƒ[ƒW‚ğŒJ‚è•Ô‚µó‚¯‚é
	while (playerHp > 0)
	{
	   playerHp -= 7;
	   printf("c‚èHP %d\n", playerHp);

	}
}
*/
/*
//switch•¶‚Ì•œK
int main(void)
{
	int num = 5;
	switch (num)
	{
	case 0:
		printf("num‚Í0\n");
		break;
	case 1:
		printf("num‚Í1\n");
		break;
	case 2:
		printf("num‚Í2\n");
		break;
	case 3:
		printf("num‚Í3\n");
		break;
	case 4:
		printf("num‚Í4\n");
		break;
	case 5:
		printf("num‚Í5\n");
		break;
	default:
		printf("num‚Í‚»‚êˆÈŠO\n");
		break;

	}

	return 0;
}
*/