/* CLIENT */

enum {

  biceps, quads, calves, triceps, pectorals

};


typedef struct _rep {

  unsigned int muscle_group;
  unsigned int resistance;
  unsigned int rotation;
  unsigned int speed;

} Rep;

/*
  TODO

typedef struct _heartrate {

  unsigned int rate;

} Heartrate;

*/

/* 
 * Reader function that reads from the instrument stream and returns a Rep struct 
 * representing the rep done
 */
int reader(int, Rep*);

/* Calculates the energy requirements for a rep */
double energyOutput(Rep*);

/* Calculates the calories expended per rep */
double calorieOutput(Rep*);

/* Calculates the fatigue per rep */
double fatigueOutput(Rep*);

/* Output the rep */
void output(Rep*);
