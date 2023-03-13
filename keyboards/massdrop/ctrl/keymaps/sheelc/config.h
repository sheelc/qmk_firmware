#define ONESHOT_TIMEOUT 2500  /* Time (in ms) before the one shot key is released */
#define PERMISSIVE_HOLD

// Enable / disable OFFICE_MODE
//#define OFFICE_MODE

#ifdef OFFICE_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#else
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_JELLYBEAN_RAINDROPS
#endif

#define TAPPING_TERM 150

#define FORCE_NKRO

#define UNDERGLOW_LIGHT_INDEX 87

// Mouse key speed and acceleration.
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_MOVE_DELTA 32
#define MOUSEKEY_MAX_SPEED 128