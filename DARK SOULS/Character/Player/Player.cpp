#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	m_cameraAngle(0.0f),
	m_moveAnimFrameIndex(0),
	m_moveAnimShieldFrameIndex(0),
	m_a(0),
	m_pad(0),
	m_animRollAttack(-1),
	m_avoidance(false),
	m_nextAttack1(false),
	m_nextAttack2(false),
	m_nowPos(VGet(0.0f,0.0f,0.0f))
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

}

void Player::Init()
{
	//プレイヤーHPの初期化
	m_hp = 150.0f;

	//プレイヤースピード初期化
	m_speed = 2.0f;

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


	//アニメーションアタッチ
	m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
	m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
	m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
	m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);
	m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);
	m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);
	m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);
	m_animation[7] = MV1AttachAnim(m_handle, 1, m_animRollAttack, TRUE);


	//アタッチしたアニメーションの総再生時間を取得する
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
	m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
	m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
	m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);
	m_totalAnimTime[4] = MV1GetAttachAnimTotalTime(m_handle, m_animation[4]);
	m_totalAnimTime[5] = MV1GetAttachAnimTotalTime(m_handle, m_animation[5]);
	m_totalAnimTime[6] = MV1GetAttachAnimTotalTime(m_handle, m_animation[6]);
	m_totalAnimTime[7] = MV1GetAttachAnimTotalTime(m_handle, m_animation[7]);

	//一旦待機以外のアニメーションデタッチ
	MV1DetachAnim(m_handle, m_animation[1]);
	MV1DetachAnim(m_handle, m_animation[2]);
	MV1DetachAnim(m_handle, m_animation[3]);
	MV1DetachAnim(m_handle, m_animation[4]);
	MV1DetachAnim(m_handle, m_animation[5]);
	MV1DetachAnim(m_handle, m_animation[6]);
	MV1DetachAnim(m_handle, m_animation[7]);
	m_animation[1] = -1;
	m_animation[2] = -1;
	m_animation[3] = -1;
	m_animation[4] = -1;
	m_animation[5] = -1;
	m_animation[6] = -1;
	m_animation[7] = -1;


	//プレイヤーのポジション設定
	m_pos = VGet(m_posX, m_posY, m_posZ);
	m_drawPos = m_pos;
}

void Player::Update()
{
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

	if (m_avoidance == false && m_moveAttack == false)
	{
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);
	}
	

	m_move = VGet(-analogX, 0.0f, analogY);  //ベクトルの長さ

	//ベクトルの長さを取得する
	float len = VSize(m_move);
	//ベクトル長さを0.0～1.0の割合に変換する
	float rate = len / 1000.0f;

	//アナログスティック無効な範囲を除外する
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//速度が決定できるので移動ベクトルに反映する
	m_move = VNorm(m_move);
	float speed = m_speed * rate;

	m_move = VScale(m_move, speed);

	//cameraの角度から
	//コントローラーによる移動方向を決定する
	MATRIX mtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_move = VTransform(m_move, mtx);

	//移動方向からプレイヤーへの向く方向を決定する
	//移動していない場合(ゼロベクトル)の場合は変更しない
	if (VSquareSize(m_move) > 0.0f && m_avoidance == false && m_moveAttack == false)
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

	m_pos = VAdd(m_pos, m_move);

	//アニメーション時間を進める前のアニメーションで移動をしているフレームの座標取得
	m_prevPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);

	//攻撃していない時のアニメーション速度
	if(m_moveAttack == false)
	{
		//再生時間を進める
		m_playerTime += 0.5f;
	}


	//Aボタンが押されたら
	if (m_xpad.Buttons[12] == 1)
	{
		if (m_a > 50)
		{
			m_avoidance = false;
		}
		else
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
		m_a = 0;
	}
	//アニメーションが終わった後に座標を入れる
	if (m_avoidance == false && m_moveAttack == false)
	{
		m_drawPos = m_pos;
	}

	Action();

	Animation(m_a, m_playerTime, m_pos);
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
	if (m_xpad.Buttons[9] == 1)
	{
		if (m_attackNumber == 0)
		{
			m_attackNumber = 1;

			m_moveAttack = true;
		}
		else if (m_nextAttack1 == true)
		{
			m_attackNumber = 2;

			m_moveAttack = true;
		}
		else if (m_nextAttack2 == true)
		{
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
		
		if (m_animation[4] != -1 && m_playerTime >= 15.0f)
		{

			m_playerTime += 0.8f;

			if (m_playerTime >= 25.0f)
			{
				//2段階目の攻撃準備
				m_nextAttack1 = true;
			}

		}
		else if (m_animation[5] != -1 && m_playerTime >= 5.0f)
		{
			m_playerTime += 0.8f;

			if (m_playerTime >= 10.0f)
			{
				//3段階目の攻撃準備
				m_nextAttack2 = true;
			}
			
		}
		else if (m_animation[6] != -1 && m_playerTime >= 15.0f)
		{
			m_playerTime += 0.9f;
		}
		else
		{
			m_playerTime += 0.5f;
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
	
}

/// <summary>
/// アニメーションに関する実装をまとめる関数
/// </summary>
void Player::Animation(int& A, float& time, VECTOR& pos)
{
	//プレイヤーが動いていないなら
	if (m_moveflag == false && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);

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

		}
		
	}
	//プレイヤーが動いたら
	//Aボタン長押し
	if (A > 50 && m_moveflag == true && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);



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


		}
	}
	else if (m_avoidance == true && m_moveAttack == false)
	{

		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);


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
		}
	}
	else if (m_moveflag == true && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);

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
		}
	}
	if (m_avoidance == false && m_moveAttack == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[3] != -1 || m_animation[7] != -1)
		{
			//攻撃1段階目
			if (m_attackNumber == 1)
			{
				//アニメーションデタッチ
				MV1DetachAnim(m_handle, m_animation[0]);
				MV1DetachAnim(m_handle, m_animation[1]);
				MV1DetachAnim(m_handle, m_animation[2]);
				MV1DetachAnim(m_handle, m_animation[3]);
				MV1DetachAnim(m_handle, m_animation[7]);

				//アニメーションアタッチ
				m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);

				time = 0.0f;

				m_animation[0] = -1;
				m_animation[1] = -1;
				m_animation[2] = -1;
				m_animation[3] = -1;
				m_animation[7] = -1;


				m_moveAttackEnd = false;
			}

		}
		//攻撃2段階目
		else if (m_attackNumber == 2 && m_animation[4] != -1 && time >= m_totalAnimTime[4])
		{
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
		else if (m_attackNumber == 3 && m_animation[5] != -1 && time >= m_totalAnimTime[5])
		{
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

		m_avoidance = false;
	}
	if (time >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		time = 0.0f;

		//攻撃終了
		m_moveAttackEnd = true;

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
}

void Player::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(m_handle, m_drawPos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3Dモデル描画
	MV1DrawModel(m_handle);

	DrawFormatString(0, 0, 0xffffff, "playTime : %f", m_playerTime);
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

}
