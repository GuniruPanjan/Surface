#include<stdio.h>


//ŒJ‚è•Ô‚µˆ—
int main(void)
{
	int hp = 100;  //‰Î‚Ì–³‚¢ŠD

	int enemyNum = 4;    //“G‚Ì”

	int count = 0;  //ŒJ‚è•Ô‚µ‰ñ”‚ğ”‚¦‚é
	for (count = 1; count <= 4; count++)
	{
		hp -= 20;  //UŒ‚‚ğ‹ò‚ç‚Á‚½@HP‚ğ20Œ¸‚ç‚·
		printf("%d‘Ì–Ú‚Ì“G‚ÌUŒ‚I\n", count);
		printf("c‚è‚ÌHP: %d\n", hp);
	}

	printf("count = %d\n", count);

	/*
	//‡@‚ªÀs‚³‚ê‚é
	count = 1;
	//‡AŒJ‚è•Ô‚·ğŒ‚ğƒ`ƒFƒbƒN
	count <= 4 //true‚Ìê‡ŒJ‚è•Ô‚·ˆ—(‡Cj‚ğÀs‚·‚é
		//false‚Ìê‡‚Ífor•¶I‚í‚è
 //ŒJ‚è•Ô‚µğŒ‚ğ–‚½‚µ‚½ê‡‚Íˆ—‚ªs‚í‚ê‚é
		hp -= 20;  //UŒ‚‚ğ‹ò‚ç‚Á‚½@HP‚ğŒ¸‚ç‚·
	printf("%d‘Ì–Ú‚Ì“G‚ÌUŒ‚I\n", count);
	printf("c‚èHP: %d\n", hp);

	//‡B–½—ß‚ğÀs‚µ‚½Œã‚Ìˆ—‚ªÀs‚³‚ê‚é
	count++;   //count = 2

	//‡A‚ÌğŒƒ`ƒFƒbƒN‚É–ß‚é
	*/

	//for•¶‚Ìà–¾
	for (
		count = 1;      //‡@for•¶‚É—ˆ‚½‚ÉÅ‰‚ÉÀs‚³‚ê‚é
		count <= 4;     //‡AŒJ‚è•Ô‚·ğŒ
		count++        //‡BŒJ‚è•Ô‚µ–½—ß‚ğÀs‚µ‚½Œã‚És‚í‚ê‚éˆ—
		) 
	{
		//‚±‚Ì’†g‚ğŒJ‚è•Ô‚·
	}

	return 0;

	/*
	//“G‚ª4‘Ì
	hp -= 20;  //1‘Ì–Ú‚Ì“G‚©‚çUŒ‚‚ğ‚à‚ç‚Á‚½@@HP‚ğ20Œ¸‚ç‚·
	printf("c‚èHP: %d\n", hp);

	hp -= 20;  //2‘Ì–Ú‚Ì“G‚©‚çUŒ‚‚ğ‚à‚ç‚Á‚½@@HP‚ğ20Œ¸‚ç‚·
	printf("c‚èHP: %d\n", hp);

	hp -= 20;  //3‘Ì–Ú‚Ì“G‚©‚çUŒ‚‚ğ‚à‚ç‚Á‚½@@HP‚ğ20Œ¸‚ç‚·
	printf("c‚èHP: %d\n", hp);

	hp -= 20;  //4‘Ì–Ú‚Ì“G‚©‚çUŒ‚‚ğ‚à‚ç‚Á‚½@@HP‚ğ20Œ¸‚ç‚·
	printf("c‚èHP: %d\n", hp);

	hp -= 20;  //1‘Ì–Ú‚Ì“G‚©‚çUŒ‚‚ğ‚à‚ç‚Á‚½@@HP‚ğ20Œ¸‚ç‚·
	printf("c‚èHP: %d\n", hp);

	if (hp == 0)
	{
		printf("‰Î‚Ì–³‚¢ŠD‚Í€‚ñ‚Å‚µ‚Ü‚Á‚½\n");
	}

	*/
}





//if•¶Aswitch•¶‚Ì—ûK
/*
int main(void)
{









	
	int num = 1;
	int num2 = 0;

	if (num == 0 && num2 == 0)      //‚Ç‚Á‚¿‚à0
	{
		if (num == 0)
		{
			printf("ƒCƒ“ƒfƒ“ƒg‚É‹C‚ğ•t‚¯‚é\n");
		}
		else if (num2 == 0)
		{

		}
		else
		{

		}
	}



	switch (num)
	{
	case 0:
		printf("num‚Í%d‚Å‚·\n", num);
		if (num2 == 0)   //switch•¶‚Ì’†‚Éif•¶‚ğ‘‚¯‚é
		{


		}
		break;
	case 1:
		printf("num‚Í%d‚Å‚·\n", num);
		break;
	case 2:
		printf("num‚Í%d‚Å‚·\n", num);
		break;
	case 3:
		printf("num‚Í%d‚Å‚·\n", num);
		break;
	}




	
	int num = 3;

	int num2 = 0;
	
	if (num == 0 && num2 == 0)         //num,num2‹¤‚É0      and‰‰Z
	{
		printf("num‚Í%d‚ÅAnum2‚Í%d‚Å‚·\n", num, num2);
	}
	else if (num == 0 || num2 ==0)       //num,num2‚Ì‚Ç‚¿‚ç‚©‚ª()
	{
		printf("num‚Í0‚à‚µ‚­‚Ínum2‚Í0‚Å‚·\n");

	}
	else if(num == 1)
	{
		printf("num‚Í1‚Å‚·\n");
	}
	else if (num == 2)
	{
		printf("num‚Í2‚Å‚·\n");
	}
	else if (num == 3)
	{
		printf("num‚Í3‚Å‚·\n");
	}
	else
	{
		printf("num‚Í%d‚Å‚ ‚è0‚Å‚à1‚Å‚à2‚Å‚à3‚Å‚à‚ ‚è‚Ü‚¹‚ñ", num);
	}
	return 0;
	
}
*/