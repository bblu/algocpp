//Philosophers have dinner...
//

enum State{
	Thinking,
	Waiting,
	Eating,
	Full=10
}

bool chopsticks[6]=[true];

class Philosopher{
public:
	int id;
	State state;
	Philosopher(int id)
		:id(num),state(Thinking){}
};
