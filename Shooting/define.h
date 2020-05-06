#pragma once

#define SINGLE(className) public: \
						static className* GetInst() \
						{\
							static className mgr;\
							return &mgr;\
						}\
						private:\
							className();\
							~className();

#define KEY(type, state) CKeyMgr::GetInst()->GetKeyState(type, state)
#define DT CTimeMgr::GetInst()->DeltaTime()
#define PI 3.14159265358979

// 생각해보니 굳이 시간을 이렇게 표현할 필요가 없던거 같다. enum이 더 효율적인듯
#define TimeOne 0x01
#define TimeTwo 0x02
#define TimeThree 0x04
#define TimeFour 0x08
#define TimeFive 0x10
#define TimeSix 0x20
#define TimeSeven 0x40
#define TimeEight 0x80
#define TimeNine 0x100
#define TimeTen 0x200
#define TimeEleven 0x400

#define ITEM_DUAL 0x01
#define ITEM_MAGNET 0x02
#define ITEM_INVINCIBLE 0x04

enum class KEY_TYPE
{
	KEY_1 = 0,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9, 
	KEY_0,
	KEY_Q,
	KEY_W,
	KEY_E,
	KEY_R,
	KEY_T,
	KEY_Y,
	KEY_U,
	KEY_I,
	KEY_O,
	KEY_P,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_Z,
	KEY_X,
	KEY_C,
	KEY_V,
	KEY_B,
	KEY_N,
	KEY_M,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,

	KEY_CTRL,
	KEY_ALT,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_TAB,
	KEY_CAP,
	KEY_ENTER,
	KEY_ESC,
	KEY_SPACE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,

	KEY_NUM1,
	KEY_NUM2,
	KEY_NUM3,
	KEY_NUM4,
	KEY_NUM5,
	KEY_NUM6,
	KEY_NUM7,
	KEY_NUM8,
	KEY_NUM9,
	KEY_NUM0,	
	END,
};

enum class KEY_STATE
{
	TAB,	// 최초 눌린 시점
	HOLD,   // 누르고 있는 중
	AWAY,   // 키를 막 뗀 시점
	NONE,   // 안눌림	
};

enum class STAGE
{
	LOGO,
	ONE,
	RESULT,
	END
};

enum class BELONG
{
	NONE,
	PBULLET,
	MONSTER,
	PLAYER,
	METEO,
	ITEM,
	MBULLET,
	UI,
	END
};

enum class OBJ_STATE
{
	NONE,
	DIE,
	DIE_METEO,
	BULLET,
	DIE_BOSS,
	GAME_END,
	INVINCIBLE
};

enum class ITEM
{
	DUAL,
	MAGNET,
	INVINCIBLE,
	END
};

enum class TEXT
{
	TEXT_A,
	TEXT_B,
	TEXT_C,
	TEXT_D,
	TEXT_E,
	TEXT_F,
	TEXT_G,
	TEXT_H,
	TEXT_I,
	TEXT_J,
	TEXT_K,
	TEXT_L,
	TEXT_M,
	TEXT_N,
	TEXT_O,
	TEXT_P,
	TEXT_Q,
	TEXT_R,
	TEXT_S,
	TEXT_T,
	TEXT_U,
	TEXT_V,
	TEXT_W,
	TEXT_X,
	TEXT_Y,
	TEXT_Z,
	TEXT_0,
	TEXT_1,
	TEXT_2,
	TEXT_3,
	TEXT_4,
	TEXT_5,
	TEXT_6,
	TEXT_7,
	TEXT_8,
	TEXT_9,
	TEXT_EXCLAMATION,
	TEXT_DOLLAR,
	TEXT_PERCENT,
	TEXT_AND,
	TEXT_BRACKET_IN,
	TEXT_BRACKET_OUT,
	TEXT_TILDE,
	TEXT_QUOTATION,
	TEXT_COLON,
	TEXT_COMMA,
	TEXT_POINT,
	TEXT_QUESTION,
	TEXT_PLUS,
	TEXT_MINUS,
	TEXT_SLASH,
	TEXT_MULTIPLY,
	TEXT_EQUAL,
	TEXT_AT,
	END
};