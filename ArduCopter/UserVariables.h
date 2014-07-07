// agmatthews USERHOOKS
// user defined variables

// example variables used in Wii camera testing - replace with your own
// variables
#if WII_CAMERA == 1
WiiCamera           ircam;
int                 WiiRange=0;
int                 WiiRotation=0;
int                 WiiDisplacementX=0;
int                 WiiDisplacementY=0;
#endif

#define msg_toNano_size 6
#define msg_fromNano_size 3

// byte = unsigned char

int16_t remote_RPM;
uint8_t nano_frontlight_auto = 1;
uint8_t nano_frontlight_on = 0;
byte nanoRXi = 0;
byte msg_toNano[msg_toNano_size] = {0};
byte msg_fromNano[msg_fromNano_size] = {0};



