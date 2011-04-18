/* FIDI PROTOCOL SPECS */

/* STATUS BYTE (0xAA - 0xFF = 12 addresses) */
enum {

  HEART_RATE	= 0xAA,
  REP		= 0xAB

};

/* REP BYTE (0x00 - 0xA9 = 244 addresses) */
enum {

  MUSCLE_GROUP		= 0x00,
  RESISTANCE		= 0x01,
  ROTATION_ANGLE	= 0x02,
  SPEED			= 0x03

};

/* 
 * MUSCLE GROUP BYTE (0x00 - 0xA7 = 241 addresses unassigned)
 * 
 * 0x00 - 0xA7 are reserved for the individual muscle group
 * 0xA7 - 0xA9 are reserved for the specific side where:
 * - 0xA8 - left side
 * - 0xA9 - right side
 */
