/* FIDI PROTOCOL SPECS */

/* STATUS BYTE (0x00 - 0xFF = 256 addresses) */
enum {

  TIME		= 0x00, /* Gives the time. Followed by (long) bytes */
  HEART_RATE	= 0x10, /* Measures the heart rate. 1 byte follows. */
  MOTION	= 0x11, /* Rotational motion. Followed by 4 bytes */
  RESISTANCE	= 0x12 /* Resistance. Followed by (int) bytes OPTIONAL */

};

/* MOTION 
 * 
 * The motion is represented by 4 bytes where the highest byte corresponds to the limb and the lower 3 correspond to the 3 dimensions of rotation (X, Y, Z)
 *
 */

/* LIMB BYTE (0x00 - 0xFF = 256 addresses) */
enum {

  RIGHT_FOREARM	= 0x00,
  LEFT_FOREARM	= 0x01,
  RIGHT_ARM	= 0x02,
  LEFT_ARM	= 0x03

  /* TODO: More ... */

};

