#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "GraphMode.h"
#include<math.h>
//#define PI 3.1415926535897932384626433832795f



class Shot;
GraphMode graph;

Player::Player():
	HP(10),
	Speed(1.0f),
	Aiming(-1),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerWidth(16),
	PlayerHeight(16),
	PlayerX(640.00f / 12.0f),
	PlayerY(480.00f - 100.0f),
	ScrollX(0.0f),
	ScrollY(0.0f),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0),
	Gravity(0),
	BulletTime(0),
	W(0),
	H(0),
	PlayerRight(false),
	PlayerDamage(false),
	Left(false),
	Right(false),
	PlayerRise(false),
	Count(0),
	RightAnimCount(0),
	LeftAnimCount(11),
	RightAnimTime(0),
	LeftAnimTime(0),
	DeadAnim(0),
	DeadAnimTime(0),
	DeadAnimCount(9),
	DamegeCount(0),
	Reload(false),
	SEReload(0),
	SEDamage(0),
	SEShotMem(0),
	SE(false),
	PlayerArm(0),
	PlayerArmFlag(false)
{
	//弾初期化
	memset(shot, 0, sizeof(shot));

	
}

Player::~Player()
{
}

void Player::FinalizePlayer(Player& player, Shot shot[],Shield& shield)
{
	DeleteGraph(player.Aiming);

	DeleteGraph(player.DeadAnim);

	for (int i = 0; i < 14; i++)
	{
		DeleteGraph(player.DeadGraph[i]);
	}

	for (int i = 0; i < 12; i++)
	{
		DeleteGraph(player.playerGraph[i]);
	}

	for (int i = 0; i < SHOT; i++)
	{
		DeleteGraph(shot[i].Graph);

		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(shot[i].ShotAnimGraphRight[j]);

			DeleteGraph(shot[i].ShotAnimGraphLeft[j]);

			DeleteGraph(shot[i].ShotSparkGraphRight[j]);

			DeleteGraph(shot[i].ShotSparkGraphLeft[j]);

			DeleteSoundMem(shot[i].SEShot);

			DeleteSoundMem(shot[i].SENotShot);
		}
	}
	DeleteSoundMem(player.SEReload);
	DeleteSoundMem(player.SEDamage);

	DeleteGraph(shield.ShieldGraph);
	DeleteGraph(player.PlayerArm);
}

void Player::Init(Shield& shield ,Player& player)
{
	//DrawGraph(PlayerX, PlayerY, playerGraph, true);

	player.BulletTime = 0;

	player.Aiming = LoadGraph("date/標準.png");

	player.DeadAnim = LoadGraph("date/墓.png");

	player.PlayerArm = LoadGraph("date/腕.png");
	player.PlayerArmFlag = false;

	player.HP = 10;
	player.Speed = 1.0f;
	player.AimingW = 0;
	player.AimingH = 0;
	player.MouseX = 0;
	player.MouseY = 0;
	player.PlayerWidth = 16;
	player.PlayerHeight = 16;
	player.PlayerX = 640.0f / 12.0f;
	player.PlayerY = 480.0f - 100.0f;
	player.ScrollX = 0.0f;
	player.ScrollY = 0.0f;
	player.PlayerShotFlag = false;
	player.PlayerW = 0;
	player.PlayerH = 0;
	player.W = 0;
	player.H = 0;
	player.Gravity = 0.3f;
	player.PlayerRight = false;
	player.PlayerDamage = false;
	player.Bullet = 12;
	player.BulletTime = 0;
	player.Left = false;
	player.Right = false;
	player.PlayerRise = false;
	player.Count = 0;
	player.RightAnimCount = 0;
	player.LeftAnimCount = 11;
	player.RightAnimTime = 0;
	player.LeftAnimTime = 0;
	player.DamegeCount = 0;
	player.Reload = false;

	player.DeadAnimCount = 9;
	player.DeadAnimTime = 0;
	player.ShotGraph = LoadGraph("date/銃弾.png");
	player.SEShotMem = LoadSoundMem("SE/拳銃を撃つ.mp3");
	player.SENotShotMem = LoadSoundMem("SE/拳銃の弾切れ.mp3");

	player.SE = false;

	LoadDivGraph("date/爆発Down.png", 14, 8, 2, 30, 30, player.DeadGraph);

	LoadDivGraph("date/PlayerMove.png", 12, 6, 2, 20, 25, player.playerGraph);

	player.SEReload = LoadSoundMem("SE/決定ボタンを押す31.mp3");
	player.SEDamage = LoadSoundMem("SE/衝撃.mp3");
	player.SEReloadCan = player.SEReload;

	shield.LeftFlag = false;
	shield.RightFlag = false;
	shield.ShieldGraph = LoadGraph("date/Shiled.png");
	shield.ShieldWidth = 3;
	shield.ShieldHeight = 30;
}

void Player::InitShot(Shot shot[],Player& player)
{
	for (int i = 0; i < SHOT; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			shot[i].ShotAnimGraphLeft[j] = 0;
			shot[i].ShotAnimGraphRight[j] = 0;
			shot[i].ShotSparkGraphLeft[j] = 0;
			shot[i].ShotSparkGraphRight[j] = 0;
		}

		shot[i].X = -50;
		shot[i].Y = -50;

		shot[i].Flag = false;

		shot[i].Damage = 3;

		shot[i].Graph = player.ShotGraph;

		shot[i].ShotAnimCountRight = 0;
		shot[i].ShotAnimCountLeft = 0;

		shot[i].ShotAnimTime = 0;

		LoadDivGraph("date/血しぶき(小)右.png", 2, 2, 1, 5, 5, shot[i].ShotAnimGraphRight);
		LoadDivGraph("date/血しぶき(小)左.png", 2, 2, 1, 5, 5, shot[i].ShotAnimGraphLeft);

		shot[i].ShotSparkCountRight = 0;
		shot[i].ShotSparkCountLeft = 0;

		shot[i].ShotSparkTime = 0;

		LoadDivGraph("date/火花(小)右.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphRight);
		LoadDivGraph("date/火花(小)左.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphLeft);

		shot[i].SEShot = player.SEShotMem;
		shot[i].SENotShot = player.SENotShotMem;
	}
	
}

void Player::Update(Player& player,Map& map,Shield& shield,Background& back)
{

	//盾実装
	//下キーを押した時
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//プレイヤーを動けなくする
		Left = true;
		Right = true;
		player.PlayerShotFlag = true;

		//左に盾を構える
		if (player.PlayerX > player.MouseX)
		{
			shield.LeftFlag = true;

			shield.RightFlag = false;

			player.LeftAnimCount = 11;
		}
		//右に盾を構える
		if (player.PlayerX < player.MouseX)
		{
			shield.RightFlag = true;

			shield.LeftFlag = false;

			player.RightAnimCount = 0;
		}
		
	}
	//下キーを押してないとき
	else if (CheckHitKey(KEY_INPUT_DOWN) == false)
	{
		//盾を消す
		shield.LeftFlag = false;
		shield.RightFlag = false;

		Left = false;
		Right = false;
	}

	//左キーを押したとき
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		if (player.HP > 0)
		{

			if (Left == false)
			{
				//標準がプレイヤーより右なら
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;
					if (player.RightAnimTime >= 10)
					{
						player.RightAnimCount++;

						player.RightAnimTime = 0;
					}
				}
				//標準がプレイヤーより左なら
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;
					if (player.LeftAnimTime >= 10)
					{
						player.LeftAnimCount--;

						player.LeftAnimTime = 0;
					}
				}

				player.PlayerX -= Speed;

				//左端から先にいかない
				if (player.PlayerX < 8.0f)
				{
					player.PlayerX = 8.0f;
				}
			}
		}
		
	}
	//右キーを押したとき
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		if (player.HP > 0)
		{
			Left = true;

			if (Right == false)
			{
				//標準がプレイヤーより右なら
				if (player.MouseX >= player.PlayerX)
				{
					player.RightAnimTime++;
					if (player.RightAnimTime >= 10)
					{
						player.RightAnimCount++;

						player.RightAnimTime = 0;
					}
				}
				//標準がプレイヤーより左なら
				else if (player.MouseX < player.PlayerX)
				{
					player.LeftAnimTime++;
					if (player.LeftAnimTime >= 10)
					{
						player.LeftAnimCount--;

						player.LeftAnimTime = 0;
					}
				}

				player.PlayerX += player.Speed;

				//真ん中から先に行くと画面がついてくる
				if (player.PlayerX >= graph.GraphModeWIDTH / 6)
				{
					player.PlayerRight = true;
					player.PlayerX = static_cast<float>(graph.GraphModeWIDTH / 6);
				}
			}
		}

	}
	//移動してないと画面が止まる
	else if (player.PlayerX <= graph.GraphModeWIDTH / 2)
	{
		//停止中は画面のスクロールは行わない
		player.PlayerRight = false;
		
	}
	

	if (player.PlayerRight == true)
	{
		//シールドを構えた時はスクロール量を加算しない
		if (player.Right == false)
		{
			//プレイヤー操作からスクロール量を算出する
			player.ScrollX -= Speed;
			player.ScrollY = 0.0f;
		}
		
	}
	
	//当たり判定の更新
	m_colRect.SetCenter(player.PlayerX, player.PlayerY - 1, player.PlayerWidth - 2, player.PlayerHeight);
	
	//マウスの座標取得
	GetMousePoint(&player.MouseX, &player.MouseY);

	if (player.PlayerDamage == true)
	{
		
		if (player.SE == false)
		{
			PlaySoundMem(player.SEDamage, DX_PLAYTYPE_BACK, TRUE);

			player.SE = true;
		}
		
		//画面を揺らす
		if (player.Count > 1 && player.Count <= 100)
		{
			back.BackX = GetRand(10);

			back.BackY = GetRand(10);

			back.BackX = GetRand(-10);

			back.BackY = GetRand(-10);
		}
		if (player.Count > 100)
		{
			back.BackX = 0;

			back.BackY = 0;
		}

		player.Count++;

		player.DamegeCount++;

	}
	//4フレーム後
	if (player.Count >= 224)
	{
		player.SE = false;

		player.PlayerDamage = false;
		player.Count = 0;
	}
}


void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	//弾が満タンだとリロードできない
	if (player.Bullet < 12)
	{
		//右クリックで弾をリロード
		if (GetMouseInput() & MOUSE_INPUT_RIGHT)
		{
			if (player.Reload == false)
			{
				PlaySoundMem(player.SEReloadCan, DX_PLAYTYPE_BACK, TRUE);

				player.Reload = true;
			}

		}
		if (player.Reload == true)
		{
			//PlaySoundMem(player.SEReload,DX_PLAYTYPE_BACK, TRUE);

			player.PlayerShotFlag = true;

			player.BulletTime++;
			if (player.BulletTime >= 40)
			{
				player.Bullet = 12;

				player.Reload = false;

				player.BulletTime = 0;
			}
		}
	}
	//マウスキー(左クリック)が押されると発射
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		//弾が入っていると撃てる
		if (player.Bullet > 0)
		{
			

			if (player.PlayerShotFlag == false)
			{

				for (int i = 0; i < shotSize; i++)
				{
					PlaySoundMem(shot[i].SEShot, DX_PLAYTYPE_BACK, TRUE);

					if (shot[i].Flag == false)
					{
						shot[i].Flag = true;
						shot[i].X = player.PlayerX;
						shot[i].Y = player.PlayerY;

						//弾の移動速度を設定する
						double sb, sbx, sby, ax, ay, sx, sy;

						sx = shot[i].X + shot[i].Width / 2;
						sy = shot[i].Y + shot[i].Height / 2;

						ax = player.MouseX + player.AimingW / 2;
						ay = player.MouseY + player.AimingH / 2;

						sbx = ax - sx;
						sby = ay - sy;

						sb = sqrt(sbx * sbx + sby * sby);

						//1フレームあたり10ドットで動く
						shot[i].AimX = sbx / sb * 10;
						shot[i].AimY = sby / sb * 10;

						player.Bullet--;

						//一つ弾を出したので弾を出すループから抜ける
						break;
					}
				}
				player.PlayerShotFlag = true;
			}
		}
		else if (player.Bullet <= 0)
		{
			//弾切れなら音を出す
			for (int i = 0; i < shotSize; i++)
			{
				PlaySoundMem(shot[i].SENotShot, DX_PLAYTYPE_BACK, TRUE);
			}
		
		}
	}
	else
	{
		if (player.BulletTime <= 40)
		{
			player.PlayerShotFlag = false;
		}

	}
}

void Player::Draw(Shield& shield, Player& player)
{	

	//キーが押されてないとき
	if (CheckHitKey(KEY_INPUT_LEFT) == false && CheckHitKey(KEY_INPUT_RIGHT) == false)
	{
		//ダメージをくらった時点滅させる
		if (player.Count == 0 || player.DamegeCount >= 10)
		{
			DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.playerGraph[0], true);

			player.DamegeCount = 0;
		}

	}
	//キーが押されていたら
	//ダメージを食らったとき点滅させる
	else if (player.Count == 0 || player.DamegeCount >= 10)
	{
		//プレイヤーよりマウスが右なら
		if (player.MouseX >= player.PlayerX)
		{

			if (player.RightAnimCount == 6)player.RightAnimCount = 1;

			DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.playerGraph[player.RightAnimCount], true);

			player.PlayerArmFlag = false;
		}
		//プレイヤーよりマウスが左なら
		if (player.MouseX < player.PlayerX)
		{
			if (player.LeftAnimCount == 6)player.LeftAnimCount = 10;

			DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.playerGraph[player.LeftAnimCount], true);

			player.PlayerArmFlag = true;

		}

		player.DamegeCount = 0;

		//ダメージを喰らった4フレーム後
		if (player.Count >= 224)
		{
			//アニメーションを戻す
			player.LeftAnimCount = 6;
			player.RightAnimCount = 6;
		}

	}

	//プレイヤーの腕表示
	//DrawGraph(player.PlayerX - 5, player.PlayerY - 10, player.PlayerArm, true);
	//プレイヤーの腕角度を求める
	//double a, b, c, bc, angle,abc,angleL;
	//a = player.MouseX - player.PlayerX;
	//b = player.MouseY - player.PlayerY;
	//c = sqrt(a * a + b * b);

	//abc = ((a * a) + (c * c) - (b * b));

	//angleL = (2 * (a * c));

	//angle = abc / angleL;

	//DrawRotaGraph(player.PlayerX, player.PlayerY - 3, 1.0f, angle, player.PlayerArm, true, player.PlayerArmFlag, 3);

	//プレイヤーの当たり判定の表示
	//player.m_colRect.Draw(GetColor(0, 0, 255), false);

	//左に盾を構える
	if (shield.LeftFlag == true)
	{
		//shield.RightFlag = false;

		DrawGraph(player.PlayerX - 12, player.PlayerY - 20, shield.ShieldGraph, true);
		//当たり判定の更新
		shield.m_colRect.SetCenter(player.PlayerX - 13, player.PlayerY - 5, shield.ShieldWidth + 3, shield.ShieldHeight);

		//shield.m_colRect.Draw(GetColor(0, 0, 255), false);
	}
	//右に盾を構える
	if (shield.RightFlag == true)
	{
		//shield.LeftFlag = false;

		DrawGraph(player.PlayerX + 10, player.PlayerY - 20, shield.ShieldGraph, true);
		//当たり判定の更新
		shield.m_colRect.SetCenter(player.PlayerX + 12, player.PlayerY - 5, shield.ShieldWidth + 3, shield.ShieldHeight);

		//shield.m_colRect.Draw(GetColor(0, 0, 255), false);

	}

	//プレイヤーが死亡したら
	if (player.HP <= 0)
	{
		//死んだときの演出
		player.DeadAnimTime++;
		if (player.DeadAnimTime >= 5)
		{
			player.DeadAnimCount++;

			player.DeadAnimTime = 0;
		}

		DrawGraph(player.PlayerX - 10, player.PlayerY - 15, player.DeadGraph[player.DeadAnimCount], true);


		for (int i = 0; i < 12; i++)
		{
			DeleteGraph(player.playerGraph[i]);
		}
		
		DeleteGraph(shield.ShieldGraph);

		player.PlayerShotFlag = true;

		player.Right = true;
		player.Left = true;


		if (player.DeadAnimCount >= 13)
		{
			DrawGraph(player.PlayerX - 10, player.PlayerY - 17, player.DeadAnim, true);
		}
		

	}

}

void Player::DrawShot(Shot& shot)
{
	//弾の移動
	//発射してる弾数だけ
	if (shot.Flag)
	{
		//shot.Graph = LoadGraph("date/銃弾.png");

		DrawGraph(shot.X, shot.Y, shot.Graph, true);

		shot.X += shot.AimX;
		shot.Y += shot.AimY;

		//当たり判定の更新
		shot.m_colRect.SetCenter(shot.X, shot.Y, shot.Width, shot.Height);

		//画面の外にはみ出したらフラグを戻す
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
			//DeleteGraph(shot.Graph);
		}

	}

	
}



	
