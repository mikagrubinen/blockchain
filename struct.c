#include "stdio.h"
#include "string.h"
#include <time.h>

typedef struct
{
	char* text;	
} data_t;

typedef struct 
{
	unsigned int index;
	time_t time;
	data_t data; 
} Block_t;

Block_t create_genesis_block()
{
	Block_t temp;
	temp.index = 0;
	temp.time = time(NULL);
	temp.data.text = "I am a genesis block";
	return temp;
}

Block_t next_block(Block_t previous_block)
{
	Block_t temp;
	temp.index = previous_block.index + 1;
	temp.time = time(NULL);
	temp.data.text = "I am a new block";
	return temp;
}


int main(){

	Block_t blockchain[10];
	blockchain[0] = create_genesis_block();
	Block_t previous_block = blockchain[0];

	for (int i = 1; i < 10; ++i)
	{
		Block_t block_to_add = next_block(previous_block);
		blockchain[i] = block_to_add;
		previous_block = block_to_add;

		//wait
		for (int i = 0; i < 1000000000; ++i)
    	{
    		/* code */
    	}
	}


	for (int i = 0; i < 10; ++i)
	{
		printf("Block index: %d, timestamp: %s\n", blockchain[i].index, ctime(&blockchain[i].time));
	}



	return 0;
}