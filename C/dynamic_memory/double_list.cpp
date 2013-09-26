//represents one wave
typedef struct wave_struct{
int time; //in dSec
int voltage; //in mV
}wave_struct;

//represents one beat
typedef struct beat_struct{
wave_struct P,Q,R,S,T;
}beat_struct;

//used to enumerate disease types
enum diseaseNames {
BRAD, TACH, AF, PSVT
};

extern void *
ecg_malloc(int size);
extern void
ecg_free(void *ptr);

void addBeat(beat_struct paramBeat);
void clearEcgData(void);
int isValidRVoltage(int voltage);
int isValidACase(int pV, int sV, int tV);

struct node
{
beat_struct beat;
struct node* next;
struct node* prev;
int bCounter;
int tCounter;
int aCounter;
int pCounter;
};

typedef struct node ecg_data;

ecg_data* head = 0;

void addBeat(beat_struct paramBeat)
{
ecg_data* temp = (ecg_data*) ecg_malloc(sizeof(ecg_data));

//Malloc error
if(!temp)
return;

temp->beat = paramBeat;
temp->next = 0;
temp->prev = 0;
temp->bCounter = 0;
temp->tCounter = 0;

//First node
if(!head)
{
head = temp;
}
else
{
//Go till the last node and append the node
ecg_data* e_type = head;
while(e_type->next)
{
e_type = e_type->next;
}
e_type->next = temp;
temp->prev = e_type;
}
}

void clearEcgData(void)
{
ecg_data* e_type = head;

if(!head)
return;

while(e_type)
{
ecg_data* temp = e_type;
e_type = e_type->next;
ecg_free(temp);
}
head = 0;
e_type = 0;
}

void sendBeat(beat_struct paramBeat)
{
addBeat(paramBeat);
}

int isValidRVoltage(int voltage)
{
return ((voltage>=12) && (voltage<=16));
}

int isValidACase(int pV, int sV, int tV)
{
return (((pV>=2) && (pV<=4)) && ((sV>=-5) && (sV>=-3)) && ((tV>=3) && (tV<=6)));
}

void getArrhythmiaTypes(int param[])
{
    param[BRAD] = 0;
    param[TACH] = 0;
    param[AF]   = 0;
    param[PSVT] = 0;

ecg_data* init = head;

while(init)
{
if(init->prev && isValidRVoltage((init->prev->beat).R.voltage) && isValidRVoltage((init->beat).R.voltage))
{
int prevTime = (init->prev->beat).R.time;
int currTime = (init->beat).R.time;
int timeDiff = currTime-prevTime;

//Validating for BRAD
if((timeDiff) >= 120)
{
//First difference is detected among 4 continuous
if(init->prev->bCounter == 0)
{
init->prev->bCounter = 1;
init->bCounter = init->prev->bCounter+1;
}
else
{
//Prev bCounter is not 0, so in the BRAD sequence. Increment counter
init->bCounter = init->prev->bCounter+1;
}

if(init->bCounter == 4)
{
//Not incremented till now, so add 4
param[BRAD] = param[BRAD]+4;
}
else if(init->bCounter > 4)
{
//Incrementing for every R difference
param[BRAD]++;
}
}

//Validating for TACH
if((timeDiff) <= 50)
{
//First difference is detected among 8 continuous
if(init->prev->tCounter == 0)
{
init->prev->tCounter = 1;
init->tCounter = init->prev->tCounter+1;
}
else
{
//Prev tCounter is not 0, so in the TACH sequence. Increment counter
init->tCounter = init->prev->tCounter+1;
}

if(init->tCounter == 8)
{
//Not incremented till now, so add 4
param[TACH] = param[TACH]+8;
}
else if(init->tCounter > 8)
{
//Incrementing for every R difference
param[TACH]++;
}
}
}
init = init->next;
}
}

void clearBeats()
{
clearEcgData();
}

