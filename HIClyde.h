#pragma once
#pragma comment(lib, "HICLYDE_CORE.lib")
#include <stdint.h>

#define HIC_IMPORT __declspec(dllimport)
#define HIC_API __stdcall



#pragma pack(push, 8)
typedef struct _HIClydeMouseStroke
{
	unsigned short state;
	unsigned short flags;
	short rolling;
	int x;
	int y;
	unsigned int information;
} HIClydeMouseStroke;

typedef struct _HIClydeKeyStroke
{
	unsigned short code;
	unsigned short state;
	unsigned int information;
} HIClydeKeyStroke;

typedef struct _HIClydeVerifyStatus
{
	unsigned int status_keyboard;
	unsigned int status_mouse;
	unsigned int information;
} HIClydeVerifyStatus;

typedef struct _HIClydeRequestStatus
{
	unsigned int index;
	unsigned int status;
} HIClydeRequestStatus;
typedef struct _HIClydeManageStatus
{
	unsigned int device;
	unsigned int status;
} HIClydeManageStatus;
typedef struct _HIClydeToggleDeviceManager
{
	unsigned int status;
} HIClydeToggleDeviceManager;
typedef struct _HICDummy
{
	unsigned int a0;
	unsigned long long a1;
	unsigned int a2;
	unsigned long long a3;
	unsigned int a4;
} HICDummy;
#pragma pack(pop)

enum HIClydeKeyState
{
	HICLYDE_KEY_DOWN = 0x00,
	HICLYDE_KEY_UP = 0x01,
	HICLYDE_KEY_E0 = 0x02,
	HICLYDE_KEY_E1 = 0x04,
	HICLYDE_KEY_TERMSRV_SET_LED = 0x08,
	HICLYDE_KEY_TERMSRV_SHADOW = 0x10,
	HICLYDE_KEY_TERMSRV_VKPACKET = 0x20
};


enum HIClydeMouseState
{
	HICLYDE_MOUSE_LEFT_BUTTON_DOWN = 0x001,
	HICLYDE_MOUSE_LEFT_BUTTON_UP = 0x002,
	HICLYDE_MOUSE_RIGHT_BUTTON_DOWN = 0x004,
	HICLYDE_MOUSE_RIGHT_BUTTON_UP = 0x008,
	HICLYDE_MOUSE_MIDDLE_BUTTON_DOWN = 0x010,
	HICLYDE_MOUSE_MIDDLE_BUTTON_UP = 0x020,

	HICLYDE_MOUSE_BUTTON_1_DOWN = HICLYDE_MOUSE_LEFT_BUTTON_DOWN,
	HICLYDE_MOUSE_BUTTON_1_UP = HICLYDE_MOUSE_LEFT_BUTTON_UP,
	HICLYDE_MOUSE_BUTTON_2_DOWN = HICLYDE_MOUSE_RIGHT_BUTTON_DOWN,
	HICLYDE_MOUSE_BUTTON_2_UP = HICLYDE_MOUSE_RIGHT_BUTTON_UP,
	HICLYDE_MOUSE_BUTTON_3_DOWN = HICLYDE_MOUSE_MIDDLE_BUTTON_DOWN,
	HICLYDE_MOUSE_BUTTON_3_UP = HICLYDE_MOUSE_MIDDLE_BUTTON_UP,

	HICLYDE_MOUSE_BUTTON_4_DOWN = 0x040,
	HICLYDE_MOUSE_BUTTON_4_UP = 0x080,
	HICLYDE_MOUSE_BUTTON_5_DOWN = 0x100,
	HICLYDE_MOUSE_BUTTON_5_UP = 0x200,

	HICLYDE_MOUSE_WHEEL = 0x400,
	HICLYDE_MOUSE_HWHEEL = 0x800
};
enum class HIClydeToggleDeviceManagerStatus : unsigned int
{
	HICLYDE_DEVICE_MANAGER_AUTO_DETECT_OFF,
	HICLYDE_DEVICE_MANAGER_AUTO_DETECT_ON,
	HICLYDE_DEVICE_MANAGER_MAX
};
enum class HIClydeManageDevice : unsigned int
{
	HICLYDE_MANAGE_ALL,
	HICLYDE_MANAGE_MOUSE,
	HICLYDE_MANAGE_KEYBOARD,
	HICLYDE_MANAGE_MAX
};
enum class HIClydeManageDeviceStatus : unsigned int
{
	HICLYDE_MANAGE_STATUS_CREATE,
	HICLYDE_MANAGE_STATUS_CLOSE,
	HICLYDE_MANAGE_STATUS_MAX
};
enum class HIClydeMouseButton : unsigned int
{
	HICLYDE_MOUSE_LEFT,
	HICLYDE_MOUSE_RIGHT,
	HICLYDE_MOUSE_MIDDLE,
	HICLYDE_MOUSE_BUTTON_4,
	HICLYDE_MOUSE_BUTTON_5,
	HICLYDE_MOUSE_MAX
};
enum HIClydeMouseFlag
{
	HICLYDE_MOUSE_MOVE_RELATIVE = 0x000,
	HICLYDE_MOUSE_MOVE_ABSOLUTE = 0x001,
	HICLYDE_MOUSE_VIRTUAL_DESKTOP = 0x002,
	HICLYDE_MOUSE_ATTRIBUTES_CHANGED = 0x004,
	HICLYDE_MOUSE_MOVE_NOCOALESCE = 0x008,
	HICLYDE_MOUSE_TERMSRV_SRC_SHADOW = 0x100
};


#ifdef __cplusplus
extern "C" {
#endif
	HIC_IMPORT int HIC_API HIC_Load_Device_Routine();
	HIC_IMPORT int HIC_API HIC_Verify_Device_State_Routine();
	HIC_IMPORT int HIC_API HIC_Send_Keyboard_Stroke_Routine(HIClydeKeyStroke* pStroke);
	HIC_IMPORT int HIC_API HIC_Send_Mouse_Stroke_Routine(HIClydeMouseStroke* pStroke);
	HIC_IMPORT int HIC_API HIC_Manage_Status_Routine(HIClydeManageDevice device, HIClydeManageDeviceStatus status);
	HIC_IMPORT int HIC_API HIC_Toggle_Device_Manager_Routine(HIClydeToggleDeviceManagerStatus status);
#ifdef __cplusplus
}
#endif
