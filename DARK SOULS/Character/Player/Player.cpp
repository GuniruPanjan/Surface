#include "Player.h"
#include "Map/Map.h"
#include<math.h>

Player::Player():
	m_cameraAngle(0.0f),
	m_updatePosX(485.0f),
	m_updatePosY(0.0f),
	m_updatePosZ(-800.0f),
	m_stamina(0.0f),
	m_lockonTarget(false),
	m_moveAnimFrameIndex(0),
	m_moveAnimShieldFrameIndex(0),
	m_a(0),
	m_pad(0),
	m_animRollAttack(-1),
	m_avoidance(false),
	m_nextAttack1(false),
	m_nextAttack2(false),
	m_pushButton(false),
	m_avoidanceNow(false),
	m_restAction(false),
	m_dashMove(false),
	m_staminaBroke(false),
	m_nowPos(VGet(0.0f,0.0f,0.0f)),
	m_bounceMove(VGet(0.0f,0.0f,0.0f)),
	m_hpLevel(0),
	m_staminaLevel(0),
	m_animHeel(0),
	m_recoveryNumber(0),
	m_recoberyAmount(0.0f),
	m_heel(0.0f),
	m_recoberyAction(false)
{
}

Player::~Player()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);
	MV1DeleteModel(m_animRoll);
	MV1DeleteModel(m_animAttack1);
	MV1DeleteModel(m_animAttack2);
	MV1DeleteModel(m_animAttack3);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animHeel);

}

void Player::Init()
{
	//プレイヤーHPの初期化
	m_hp = 150.0f;

	//プレイヤーのスタミナ初期化
	m_stamina = 100.0f;

	//プレイヤースピード初期化
	m_speed = 2.0f;

	//プレイヤーを押し出す距離
	m_bounceDis = 3.0f;

	//プレイヤーの攻撃力初期化
	m_attack = 10.0f;

	//回復関係の初期化
	m_recoberyAmount = 100.0f;
	m_heel = 0.0f;
	m_recoveryNumber = 5;
	m_recoberyAction = false;

	//一回だけ初期化
	if (m_oneInit == false)
	{
		//レベル初期化
		m_hpLevel = 1;
		m_staminaLevel = 1;

		m_modelSize = 0.4f;

		//プレイヤーもモデル読み込み
		m_handle = MV1LoadModel("Data/Player/PlayerModel.mv1");

		//プレイヤーの大きさを変える
		MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

		//プレイヤーのアニメーション読み込み
		m_animStand = MV1LoadModel("Data/PlayerAnimation/PlayerAnimStand.mv1");
		m_animWalk = MV1LoadModel("Data/PlayerAnimation/PlayerAnimWalk.mv1");
		m_animRun = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRun.mv1");
		m_animRoll = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRoll.mv1");
		m_animAttack1 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack1.mv1");
		m_animAttack2 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack2.mv1");
		m_animAttack3 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack3.mv1");
		m_animRollAttack = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRollAttack.mv1");
		m_animDeath = MV1LoadModel("Data/PlayerAnimation/PlayerAnimDeath.mv1");
		m_animHeel = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRecovery.mv1");

		//アニメーションアタッチ
		m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
		m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
		m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
		m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);
		m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);
		m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);
		m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);
		m_animation[7] = MV1AttachAnim(m_handle, 1, m_animRollAttack, TRUE);
		m_animation[8] = MV1AttachAnim(m_handle, 1, m_animDeath, TRUE);
		m_animation[9] = MV1AttachAnim(m_handle, 1, m_animHeel, TRUE);

		//アタッチしたアニメーションの総再生時間を取得する
		m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
		m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
		m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
		m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);
		m_totalAnimTime[4] = MV1GetAttachAnimTotalTime(m_handle, m_animation[4]);
		m_totalAnimTime[5] = MV1GetAttachAnimTotalTime(m_handle, m_animation[5]);
		m_totalAnimTime[6] = MV1GetAttachAnimTotalTime(m_handle, m_animation[6]);
		m_totalAnimTime[7] = MV1GetAttachAnimTotalTime(m_handle, m_animation[7]);
		m_totalAnimTime[8] = MV1GetAttachAnimTotalTime(m_handle, m_animation[8]);
		m_totalAnimTime[9] = MV1GetAttachAnimTotalTime(m_handle, m_animation[9]);


		//一旦待機以外のアニメーションデタッチ
		MV1DetachAnim(m_handle, m_animation[1]);
		MV1DetachAnim(m_handle, m_animation[2]);
		MV1DetachAnim(m_handle, m_animation[3]);
		MV1DetachAnim(m_handle, m_animation[4]);
		MV1DetachAnim(m_handle, m_animation[5]);
		MV1DetachAnim(m_handle, m_animation[6]);
		MV1DetachAnim(m_handle, m_animation[7]);
		MV1DetachAnim(m_handle, m_animation[8]);
		MV1DetachAnim(m_handle, m_animation[9]);
		m_animation[1] = -1;
		m_animation[2] = -1;
		m_animation[3] = -1;
		m_animation[4] = -1;
		m_animation[5] = -1;
		m_animation[6] = -1;
		m_animation[7] = -1;
		m_animation[8] = -1;
		m_animation[9] = -1;

		m_oneInit = true;
	}

	m_playTime = 0.0f;

	//当たり判定
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colAttackPos = Pos3(m_pos.x - 50.0f, m_pos.y + 35.0f, m_pos.z);
	m_initializationPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_vec = Vec3(0.0f, m_vec.y + 2.0f, 0.0f);
	m_len = 40.0f;
	m_capsuleRadius = 12.0f;
	m_sphereRadius = 18.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
	m_sphereCol.Init(m_colAttackPos, m_sphereRadius);
	

	m_posX = m_updatePosX;
	m_posY = m_updatePosY;
	m_posZ = m_updatePosZ;

	//プレイヤーのポジション設定
	m_pos = VGet(m_posX, m_posY, m_posZ);
	m_drawPos = m_pos;

	//死亡アニメーションが入っていたら
	if (m_animation[8] != -1)
	{
		//アニメーションデタッチ
		MV1DetachAnim(m_handle, m_animation[8]);

		//アニメーションアタッチ
		m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

		m_playTime = 0.0f;

		
		m_animation[8] = -1;
	}

	m_death = false;

	//モデル全体のコリジョン情報のセットアップ
	//MV1SetupCollInfo(map->GetCollisionMap(), -1);
}

void Player::Update()
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);


	//アニメーションで移動しているフレームの番号を検索する
	m_moveAnimFrameIndex = MV1SearchFrame(m_handle, "mixamorig:Hips");

	//盾を構えるときのアニメーションのフレーム所得
	m_moveAnimShieldFrameIndex = MV1SearchFrame(m_handle, "mixamorig:LeftHand");

	//パッド入力所得
	m_pad = GetJoypadXInputState(DX_INPUT_KEY_PAD1, &m_xpad);

	//アナログスティックを使って移動
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	if (m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);
	}
	

	m_move = VGet(-analogX, 0.0f, analogY);  //ベクトルの長さ
	m_bounceMove = VGet(analogX, 0.0f, -analogY);  //ベクトルの長さ

	//ベクトルの長さを取得する
	float len = VSize(m_move);
	float bounceLen = VSize(m_bounceMove);
	//ベクトル長さを0.0〜1.0の割合に変換する
	float rate = len / 1000.0f;
	float bounceRate = bounceLen / 1000.0f;

	//アナログスティック無効な範囲を除外する
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	bounceRate = (bounceRate - 0.1f) / (0.8f - 0.1f);
	bounceRate = min(bounceRate, 1.0f);
	bounceRate = max(bounceRate, 0.0f);


	//速度が決定できるので移動ベクトルに反映する
	m_move = VNorm(m_move);
	float speed = m_speed * rate;

	m_move = VScale(m_move, speed);

	m_bounceMove = VNorm(m_bounceMove);
	float bounceDis = m_speed * bounceRate;

	m_bounceMove = VScale(m_bounceMove, bounceDis);

	//cameraの角度から
	//コントローラーによる移動方向を決定する
	MATRIX mtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_move = VTransform(m_move, mtx);
	MATRIX reverseMtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_bounceMove = VTransform(m_bounceMove, reverseMtx);

	//移動方向からプレイヤーへの向く方向を決定する
	//移動していない場合(ゼロベクトル)の場合は変更しない
	if (VSquareSize(m_move) > 0.0f && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		//アングルを決定
		m_angle = atan2f(-m_move.z, m_move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);

		//プレイヤーが動いたら
		m_moveflag = true;
	}
	//プレイヤーが動いてなかったら
	else if (VSquareSize(m_move) <= 0.0f)
	{
		m_moveflag = false;
	}

	//プレイヤーが生きている時だけ
	if (m_hp >= 0.0f)
	{
		m_pos = VAdd(m_pos, m_move);

		Action();
	}
	

	//攻撃の当たり判定をプレイヤーの正面に持ってくる
	m_colAttackPos.x = m_pos.x + sinf(m_angle) * -25.0f;
	m_colAttackPos.z = m_pos.z - cosf(m_angle) * 25.0f;


	//アニメーション時間を進める前のアニメーションで移動をしているフレームの座標取得
	m_prevPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);

	//攻撃していない時のアニメーション速度
	if(m_moveAttack == false)
	{
		//再生時間を進める
		m_playTime += 0.5f;
	}


	//Aボタンが押されたら
	if (m_xpad.Buttons[12] == 1 && m_staminaBroke == false && m_recoberyAction == false)
	{
		if (m_a > 50 && m_stamina >= 0.1f)
		{
			m_avoidance = false;

			//ダッシュ中
			m_dashMove = true;

			m_speed = 3.0f;

			//スタミナ消費
			m_stamina -= 0.1f;
		}
		else if(m_stamina >= 10.0f)
		{
			m_avoidance = true;
		}

		if (m_a < 51)
		{
			m_a++;
		}
	}
	else
	{
		m_dashMove = false;

		m_speed = 2.0f;

		m_a = 0;
	}
	//回避や攻撃していない時に座標を入れる
	if (m_avoidance == false && m_moveAttack == false)
	{
		m_drawPos = m_pos;
	}
	//回避行動中
	if (m_playTime <= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		//フレーム回避
		if (m_playTime >= 0.0f && m_playTime <= 25.0f)
		{
			m_avoidanceNow = true;
		}
		else
		{
			m_avoidanceNow = false;
		}
	}
	if (m_playTime >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		
		m_drawPos = m_pos;

		//回避終了
		m_avoidance = false;
	}
	if (m_playTime >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		m_drawPos = m_pos;

		//攻撃終了
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		m_drawPos = m_pos;

		//攻撃終了
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		m_drawPos = m_pos;

		//攻撃終了
		m_moveAttack = false;
	}

	//スタミナ切れ
	if (m_stamina <= 0.1f)
	{
		m_staminaBroke = true;
	}
	//動けるようになる
	else if (m_stamina >= 20.0f)
	{
		m_staminaBroke = false;
	}
	//スタミナ回復
	if (m_dashMove == false && m_moveAttack == false && m_avoidance == false)
	{
		if (m_stamina <= 100.0f)
		{
			m_stamina += 0.3f;
		}
	}

	Animation(m_playTime, m_pos);

	m_capsuleCol.Update(m_colPos, m_vec);

	//マップとの当たり判定用
	m_mapHitColl = VGet(m_colPos.x, m_colPos.y, m_colPos.z);
}

/// <summary>
/// プレイヤーの行動に関する実装をまとめる関数
/// </summary>
void Player::Action()
{
	//PAD_INPUT_2はBボタン
	//PAD_INPUT_3はXボタン
	//PAD_INPUT_4はYボタン
	//PAD_INPUT_5はLボタン
	//PAD_INPUT_7はBackボタン
	//PAD_INPUT_8はStartボタン
	//PAD_INPUT_9はLスティック
	//PAD_INPUT_10はRスティック

	//Rボタンで攻撃
	//一段階目の攻撃
	if (m_xpad.Buttons[9] == 1 && m_staminaBroke == false && m_recoberyAction == false)
	{
		if (m_attackNumber == 0 && m_stamina >= 10.0f)
		{
			//攻撃力初期化
			m_attack = 10.0f;

			//スタミナ消費
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 1;

			m_moveAttack = true;
		}
		else if (m_nextAttack1 == true && m_stamina >= 10.0f)
		{
			//攻撃力初期化
			m_attack = 10.0f;

			//スタミナ消費
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 2;

			m_moveAttack = true;
		}
		else if (m_nextAttack2 == true && m_stamina >= 10.0f)
		{
			//攻撃力初期化
			m_attack = 10.0f;

			//スタミナ消費
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 3;

			m_moveAttack = true;
		}
	}

	//ZRボタンで強攻撃
	if (m_xpad.RightTrigger)
	{
		DrawFormatString(0, 10, 0xffffff, "強攻撃");
	}


	//Lボタンで防御
	if (m_xpad.Buttons[8] == 1)
	{
		DrawFormatString(0, 10, 0xffffff, "防御");
	}

	//攻撃時のアニメーションを速くする
	if (m_moveAttack == true)
	{
		
		if (m_animation[4] != -1 && m_playTime >= 15.0f)
		{

			m_playTime += 0.9f;

			//攻撃の当たり判定発生
			if (m_playTime >= 25.0f && m_playTime <= 30.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//攻撃の当たり判定を初期化する
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}


			if (m_playTime >= 30.0f)
			{
				//2段階目の攻撃準備
				m_nextAttack1 = true;
			}

		}
		else if (m_animation[5] != -1 && m_playTime >= 5.0f)
		{
			m_playTime += 0.9f;

			//攻撃の当たり判定発生
			if (m_playTime >= 10.0f && m_playTime <= 15.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//攻撃の当たり判定を初期化する
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}

			if (m_playTime >= 15.0f)
			{
				//3段階目の攻撃準備
				m_nextAttack2 = true;
			}
			
		}
		else if (m_animation[6] != -1 && m_playTime >= 15.0f)
		{
			m_playTime += 0.9f;

			//攻撃の当たり判定発生
			if (m_playTime >= 20.0f && m_playTime <= 25.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//攻撃の当たり判定を初期化する
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}

		}
		else
		{
			m_playTime += 0.5f;
		}

	}

	//回避中に攻撃するため
	if (m_avoidance == true)
	{
		if (m_pad & PAD_INPUT_6)
		{
			m_moveAttack = true;
		}
	}

	if (m_moveAttack == false)
	{
		//次の攻撃段階の初期化
		m_attackNumber = 0;

		//攻撃準備初期化
		m_nextAttack1 = false;
		m_nextAttack2 = false;

	}


	//敵をロックオンする
	if (m_lockonTarget == false)
	{
		if (m_xpad.Buttons[7] == 1 && m_pushButton == true)
		{
			m_lockonTarget = true;
			m_pushButton = false;
		}
		else if (m_xpad.Buttons[7] == 0)
		{
			m_pushButton = true;
		}
	}
	else if (m_lockonTarget == true)
	{
		DrawString(0, 100, "ロックオン", 0xffffff);

		if (m_xpad.Buttons[7] == 1 && m_pushButton == true)
		{
			m_lockonTarget = false;
			m_pushButton = false;
		}
		else if (m_xpad.Buttons[7] == 0)
		{
			m_pushButton = true;
		}
	}

	

	//回復
	//Xボタンが押されたら
	if (m_xpad.Buttons[14] == 1)
	{
		if (m_moveAttack == false && m_avoidance == false)
		{
			m_recoberyAction = true;
		}
		
	}
	else if(m_recoberyAction == false)
	{
		m_heel = 0.0f;
	}

	if (m_recoveryNumber >= 0 && m_recoberyAction == true && m_moveAttack == false && m_avoidance == false)
	{
		//HP回復
		if (m_hp < 150.0f && m_heel < m_recoberyAmount)
		{
			m_heel += 0.1f;

			m_hp += m_heel;
		}

	}
	
}

/// <summary>
/// アニメーションに関する実装をまとめる関数
/// </summary>
void Player::Animation(float& time, VECTOR& pos)
{
	//プレイヤーが動いていないなら
	if (m_moveflag == false && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//アニメーションアタッチ
			m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

			time = 0.0f;

			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
		
	}
	//プレイヤーが動いたら
	//Aボタン長押し
	if (m_dashMove == true && m_moveflag == true && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);



			//アニメーションアタッチ
			m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;


		}
	}
	//回避
	else if (m_avoidance == true && m_moveAttack == false && m_recoberyAction == false)
	{

		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{
			m_stamina = m_stamina - 10.0f;

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);


			//アニメーションアタッチ
			m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	else if (m_moveflag == true && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//アニメーションアタッチ
			m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	if (m_avoidance == false && m_moveAttack == true && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[3] != -1 || m_animation[7] != -1 || m_animation[9] != -1)
		{
			//攻撃1段階目
			if (m_attackNumber == 1)
			{
				//一段階目の攻撃力
				m_attack = m_attack * 1.0f;

				//アニメーションデタッチ
				MV1DetachAnim(m_handle, m_animation[0]);
				MV1DetachAnim(m_handle, m_animation[1]);
				MV1DetachAnim(m_handle, m_animation[2]);
				MV1DetachAnim(m_handle, m_animation[3]);
				MV1DetachAnim(m_handle, m_animation[7]);
				MV1DetachAnim(m_handle, m_animation[9]);

				//アニメーションアタッチ
				m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);

				time = 0.0f;

				m_animation[0] = -1;
				m_animation[1] = -1;
				m_animation[2] = -1;
				m_animation[3] = -1;
				m_animation[7] = -1;
				m_animation[9] = -1;


				m_moveAttackEnd = false;
			}

		}
		//攻撃2段階目
		if (m_attackNumber == 2 && m_animation[4] != -1)
		{
			//2段階目の攻撃力
			m_attack = m_attack * 1.2f;

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);

			//アニメーションアタッチ
			m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;

			m_moveAttackEnd = false;

		}
		//攻撃3段階目
		if (m_attackNumber == 3 && m_animation[5] != -1)
		{
			//3段階目の攻撃力
			m_attack = m_attack * 1.5f;

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);

			//アニメーションアタッチ
			m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;

			m_moveAttackEnd = false;

		}
		//攻撃2段階目
		//else if (m_attackNumber == 2 && m_animation[4] != -1 && m_moveAttackEnd == true)
		//{
		//	//アニメーションデタッチ
		//	MV1DetachAnim(m_handle, m_animation[0]);
		//	MV1DetachAnim(m_handle, m_animation[1]);
		//	MV1DetachAnim(m_handle, m_animation[2]);
		//	MV1DetachAnim(m_handle, m_animation[3]);
		//	MV1DetachAnim(m_handle, m_animation[4]);

		//	//アニメーションアタッチ
		//	m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);

		//	time = 0.0f;

		//	m_animation[0] = -1;
		//	m_animation[1] = -1;
		//	m_animation[2] = -1;
		//	m_animation[3] = -1;
		//	m_animation[4] = -1;

		//	m_moveAttackEnd = false;

		//}
		////攻撃3段階目
		//else if (m_attackNumber == 3 && m_animation[5] != -1 && m_moveAttackEnd == true)
		//{
		//	//アニメーションデタッチ
		//	MV1DetachAnim(m_handle, m_animation[0]);
		//	MV1DetachAnim(m_handle, m_animation[1]);
		//	MV1DetachAnim(m_handle, m_animation[2]);
		//	MV1DetachAnim(m_handle, m_animation[3]);
		//	MV1DetachAnim(m_handle, m_animation[4]);
		//	MV1DetachAnim(m_handle, m_animation[5]);

		//	//アニメーションアタッチ
		//	m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);

		//	time = 0.0f;

		//	m_animation[0] = -1;
		//	m_animation[1] = -1;
		//	m_animation[2] = -1;
		//	m_animation[3] = -1;
		//	m_animation[4] = -1;
		//	m_animation[5] = -1;

		//	m_moveAttackEnd = false;

		//}
	}

	//プレイヤーが回復したとき
	if (m_recoberyAction == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);

			//アニメーションアタッチ
			m_animation[9] = MV1AttachAnim(m_handle, 1, m_animHeel, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
		}
	}

	//プレイヤーが死んだ時
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1 ||
			m_animation[3] != -1 || m_animation[4] != -1 || m_animation[5] != -1 ||
			m_animation[6] != -1 || m_animation[7] != -1 || m_animation[9] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//アニメーションアタッチ
			m_animation[8] = MV1AttachAnim(m_handle, 1, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[1] && m_animation[1] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[2] && m_animation[2] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		time = 0.0f;

		//回避終了
		m_avoidance = false;
	}
	if (time >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		//攻撃終了
		m_moveAttackEnd = true;

		time = 0.0f;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		time = 0.0f;

		//攻撃終了
		m_moveAttackEnd = true;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		time = 0.0f;

		//攻撃終了
		m_moveAttackEnd = true;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[7] && m_animation[7] != -1)
	{
		time = 0.0f;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[8] && m_animation[8] != -1)
	{
		time = 120.0f;

		m_death = true;
	}
	if (time >= m_totalAnimTime[9] && m_animation[9] != -1)
	{
		m_recoveryNumber--;

		m_recoberyAction = false;

		time = 0.0f;
	}

	//再生時間をセットする
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
	if (m_animation[1] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[1], time);
	}
	if (m_animation[2] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[2], time);
	}
	if (m_animation[3] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[3], time);

		//アニメーションが経過中の座標取得
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;
	}
	if (m_animation[4] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[4], time);

		//アニメーションが経過中の座標取得
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;
	}
	if (m_animation[5] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[5], time);

		//アニメーションが経過中の座標取得
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;

		//2段階目の攻撃準備終了
		m_nextAttack1 = false;
	}
	if (m_animation[6] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[6], time);

		//アニメーションが経過中の座標取得
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;

		//3段階目の攻撃準備終了
		m_nextAttack2 = false;
	}
	if (m_animation[7] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[7], time);
	}
	if (m_animation[8] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[8], time);
	}
	if (m_animation[9] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[9], time);
	}
}

void Player::HitObj(Map& map)
{
	int j;

	//プレイヤーの周囲にあるコリジョンのポリゴンを取得する
	HitDim = MV1CollCheck_Sphere(map.GetCollisionMap(), -1, map.GetVectorMapPos(), 1500.0f);

	//検出されたポリゴンが壁ポリゴン(XZ平面に垂直なポリゴン)か床ポリゴン(XZ平面に垂直ではないポリゴン)かを判断する
	for (int i = 0; i < HitDim.HitNum; i++)
	{
		//XZ平面に垂直かどうかはポリゴンの法線のY成分が0に限りなく近いかどうかで判断する
		if (HitDim.Dim[i].Normal.y < 0.000001f && HitDim.Dim[i].Normal.y > -0.0000001f)
		{
			if (HitDim.Dim[i].Position[0].y > m_pos.y + 1.0f ||
				HitDim.Dim[i].Position[1].y > m_pos.y + 1.0f ||
				HitDim.Dim[i].Position[2].y > m_pos.y + 1.0f)
			{
				//ポリゴンの数が列挙できる限界数に達していなかったらポリゴンを配列に追加
				if (m_WallNum < PLAYER_MAX_HITCOLL)
				{
					//ポリゴンの構造体のアドレスを壁ポリゴンポインタ配列に保存する
					m_Wall[m_WallNum] = &HitDim.Dim[i];

					//壁ポリゴンの数を加算する
					m_WallNum++;
				}
			}
		}
	}

	//壁ポリゴンと当たり判定処理
	if (m_WallNum != 0)
	{
		//壁に当たったかどうかのフラグは初期状態では「当たっていない」にしておく
		m_HitFlag = false;

		//移動したかどうかで処理を分岐
		if (m_moveflag == true)
		{
			//壁ポリゴンの数だけ繰り返し
			for (int i = 0; i < m_WallNum; i++)
			{
				//i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
				m_Poly = m_Wall[i];

				//ポリゴンとプレイヤーが当たっていなかったら次のカウントへ
				if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == false) continue;

				//ここにきたらポリゴンとプレイヤーが当たっているということなので、ポリゴンに当たったフラグを立てる
				m_HitFlag = true;

				//新たな移動座標で壁ポリゴンと当たっていないかどうかを判定する
				for (j = 0; j < m_WallNum; j++)
				{
					//j番目の壁ポリゴンと当たっていないかどうかを判定する
					m_Poly = m_Wall[j];

					//当たっていたらループから抜ける
					if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true) break;
				}

				//jがm_WallNumだった場合はどのポリゴンとも当たらなかったということなので
				//壁に当たったフラグを倒したうえでループから抜ける
				if (j == m_WallNum)
				{
					m_HitFlag = false;
					break;
				}
			
			}
		}
		else
		{
			//移動していない場合の処理

			//壁ポリゴンの数だけ繰り返し
			for (int i = 0; i < m_WallNum; i++)
			{
				//i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
				m_Poly = m_Wall[i];

				//ポリゴンに当たっていたら当たったフラグを立てた上でループから抜ける
				if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true)
				{
					m_HitFlag = true;
					break;
				}

			}
		}

		//壁に当たっていたら壁から押し出す処理を行う
		if (m_HitFlag == true)
		{
			//壁からの押し出し処理を試みる最大数だけ繰り返す
			for (int i = 0; i < PLAYER_MAX_HITCOLL; i++)
			{
				//壁ポリゴンの数だけ繰り返し
				for (int k = 0; k < m_WallNum; k++)
				{
					//j番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
					m_Poly = m_Wall[k];

					//プレイヤーと当たっているか判定
					if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == false) continue;

					//当たっていたら規定距離分プレイヤーを壁の法線方向に移動させる
					m_pos = VAdd(m_pos, VScale(m_Poly->Normal, m_speed));

					//移動した上で壁ポリゴンと接触しているかどうかを判定
					for (j = 0; j < m_WallNum; j++)
					{
						//当たっていたらループを抜ける
						m_Poly = m_Wall[j];
						if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true) break;

					}

					//すべてのポリゴンと当たっていなかったらループ終了
					if (j == m_WallNum) break;
				}

				//iがm_WallNumではない場合は全部のポリゴンで押し出しを試みる前にすべての壁ポリゴンと接触しなくなったということなのでループから抜ける
				if (i != m_WallNum) break;
			}
		}
	}

	SaveAction(map);

	//検出したプレイヤーの周囲のポリゴン情報を解放する
	MV1CollResultPolyDimTerminate(HitDim);

}

void Player::SaveAction(Map& map)
{
	//休息が可能だったら
	if (map.GetSavePossible() == true)
	{	
		//Yボタンが押されたら
		if (m_xpad.Buttons[15] == 1)
		{
			m_updatePosX = 95.0f;
			m_updatePosY = 0.0f;
			m_updatePosZ = -40.0f;

			m_restAction = true;
		}
	}
}

void Player::Draw()
{
	//方向ベクトル
	Vec3 vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_colPos + vec;
	Pos3 pos2 = m_colPos - vec;

	//カプセル3Dの描画
	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_capsuleRadius, 16, m_color, 0, false);

	//円の3D描画
	DrawSphere3D(m_colAttackPos.GetVector(), m_sphereRadius, 16, 0xffffff, 0xffffff, false);
	//DrawSphere3D(map->GetVectorMapPos(), 1500.0f, 16, 0xffffff, 0xffffff, false);

	//3Dモデルのポジション設定
	MV1SetPosition(m_handle, m_drawPos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3Dモデル描画
	MV1DrawModel(m_handle);

	if (m_HitFlag == true)
	{
		DrawFormatString(0, 100, 0xffffff, "壁に当たった");
	}
	if (m_restAction == true)
	{
		DrawFormatString(0, 80, 0xffffff, "回復できる");
	}

	DrawFormatString(0, 120, 0xffffff, "HitPoly : %d", HitDim.HitNum);
	DrawFormatString(0, 0, 0xffffff, "playTime : %f", m_playTime);
	DrawFormatString(0, 30, 0xffffff, "posX : %f posY : %f posZ : %f", m_pos.x, m_pos.y, m_pos.z);
	DrawFormatString(0, 50, 0xffffff, "DrawposX : %f DrawposY : %f DrawposZ : %f", m_drawPos.x, m_drawPos.y, m_drawPos.z);
	//バグで攻撃状態になるがモーションが入らない
	DrawFormatString(0, 180, 0xffffff, "m_attack : %d", m_moveAttack);
	DrawFormatString(0, 200, 0xffffff, "m_stamina : %f", m_stamina);
	DrawFormatString(0, 220, 0xffffff, "アニメ0 : %d", m_animation[0]);
	DrawFormatString(0, 240, 0xffffff, "アニメ1 : %d", m_animation[1]);
	DrawFormatString(0, 260, 0xffffff, "アニメ2 : %d", m_animation[2]);
	DrawFormatString(0, 280, 0xffffff, "アニメ3 : %d", m_animation[3]);
	DrawFormatString(0, 300, 0xffffff, "アニメ4 : %d", m_animation[4]);
	DrawFormatString(0, 320, 0xffffff, "アニメ5 : %d", m_animation[5]);
	DrawFormatString(0, 340, 0xffffff, "アニメ6 : %d", m_animation[6]);
	DrawFormatString(0, 360, 0xffffff, "アニメ7 : %d", m_animation[7]);
	DrawFormatString(0, 380, 0xffffff, "アニメ8 : %d", m_animation[8]);
	DrawFormatString(0, 400, 0xffffff, "回復数 : %d", m_recoveryNumber);


}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);
	MV1DeleteModel(m_animRoll);
	MV1DeleteModel(m_animAttack1);
	MV1DeleteModel(m_animAttack2);
	MV1DeleteModel(m_animAttack3);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animHeel);

}

bool Player::IsCapsuleHit(const CapsuleCol& col, const CapsuleCol& col1)
{
	bool isHit = m_capsuleCol.IsHitCapsule(col);
	bool isHitBoss = m_capsuleCol.IsHitCapsule(col1);

	if (isHit || isHitBoss)
	{
		m_color = 0xffff00;

		//当たっていたら規定距離分プレイヤーを法線方向に移動させる
		m_pos = VAdd(m_pos, VScale(m_bounceMove, m_bounceDis));

		//回避行動だった場合
		//m_posが動いている
		if (m_avoidance == true)
		{
			//当たっていたら規定距離分プレイヤーを法線方向に移動させる
			m_pos.x -= m_moveVector.x + m_bounceDis;
			m_pos.z -= m_moveVector.z + m_bounceDis;
			m_drawPos.x -= m_moveVector.x + m_bounceDis;
			m_drawPos.z -= m_moveVector.z + m_bounceDis;
		}
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit || isHitBoss;
}

bool Player::isSphereHit(const SphereCol& col, const SphereCol& col1, const SphereCol& col2, const SphereCol& col3, float damage, float bossdamage)
{
	bool isHit = m_capsuleCol.IsHitSphere(col);
	bool isBossAttackHit1 = m_capsuleCol.IsHitSphere(col1);
	bool isBossAttackHit2 = m_capsuleCol.IsHitSphere(col2);
	bool isBossAttackHit3 = m_capsuleCol.IsHitSphere(col3);

	//ダメージを受けた判定
	if (isHit)
	{
		m_color = 0xffff00;

		//ダメージを一回だけ与える
		if (m_damageReceived == false)
		{
			//回避中のフレームだとダメージを受けない
			if (m_avoidanceNow == false)
			{
				m_hp = m_hp - damage;
			}
			
			m_damageReceived = true;
		}

	}
	else if (isBossAttackHit1 || isBossAttackHit2 || isBossAttackHit3)
	{
		m_color = 0xffff00;

		//ダメージを一回だけ与える
		if (m_damageReceived == false)
		{
			//回避中のフレームだとダメージを受けない
			if (m_avoidanceNow == false)
			{
				m_hp = m_hp - bossdamage;
			}

			m_damageReceived = true;
		}
	}
	else
	{
		m_damageReceived = false;

		m_color = 0xffffff;
	}

	return isHit || isBossAttackHit1 || isBossAttackHit2 || isBossAttackHit3;
}
