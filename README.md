# HIClyde
HIClyde is a library provides kernel-level keyboard/mouse simulation, pretty easy to use

## Methods
* **HIC_Load_Device_Routine()** - This is a __*prerequisite*__ for all other methods since HIClyde is working under the its own driver(device).
* **HIC_Verify_Device_State_Routine()** - To prevent unexpected system failure, this method has to be executed successfully at least once.
* **HIC_Send_Keyboard_Stroke_Routine(struct HIClydeKeyStroke)** - simulates keyboard stroke, see the structure named HIClydeKeyStroke.
* **HIC_Send_Mouse_Stroke_Routine(struct HIClydeMouseStroke)** - simulates mouse stroke, see the structure named HIClydeMouseStroke.

## Additional Methods for Advanced Use
* **HIC_Manage_Status_Routine(..)** - can control the connection state of specific HID.
* **HIC_Toggle_Device_Manager_Routine(..)** - toggle automated re-connection between HIClyde and the real HID.

## Limitations
* HIClyde implements its own device using [CVE-2022-3699](https://github.com/alfarom256/CVE-2022-3699)
  * so this library works on only **Windows 10 1607(x64) to Windows 11 22449.1(x64)**
  * and currently it only support **x64 executables** since it is DLL
  * loading its device can be considered **virus** by anti-virus solutions.
  * loading its device can be considered **cheat** by anti-cheat solutions.
  
## Related Repository
* [kbd_hookka](https://github.com/ClaudeoPK/kbd_hookka)
