#pragma once

class Physics final
{
public:
	void Update();  //更新(登録オブジェクトの物理移動)
private:
	//位置補正、決定
	void FixNextPosition() const;
	void FixPosition();
};

