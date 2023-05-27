#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void permute(uint16_t index, uint8_t **result, uint8_t *arr, uint16_t arrLen, uint8_t* tBuf)
{
	static uint8_t count = 0;
	if(index >= arrLen)
	{
		/*
			1. copy a result to list 
			2. count +1
		*/
		result[count] = (uint8_t*)malloc(sizeof(uint8_t) * arrLen);
		memcpy(result[count], tBuf, arrLen);
		printf("count = %d\n", count);
		count++;
	}
	else
	{
		for (int i = 0; i < arrLen; i++)
		{
			/*
				1. store variable to tBuf
				2. index+1
			*/
			tBuf[index] = arr[i];
			printf("index = %d\n",index );
			permute(index+1, result, arr,arrLen, tBuf);
		}
	}
}
int main(int argc, char const *argv[])
{
	/*declaration*/
	uint8_t arr[] = {1,2, 3};
	uint16_t possible = 1;
	uint16_t arrLen = 0;
	uint8_t **result = NULL;
	uint8_t *tBuf = NULL;	
	arrLen = sizeof(arr);

	/*calculate possibility permutation*/
	for(uint8_t i = 0; i < arrLen; i++)
		possible *= arrLen;
	printf("possible = %d\n", possible);


	result = (uint8_t**)malloc(sizeof(uint8_t*) * possible);
	tBuf = (uint8_t*)malloc(sizeof(uint8_t) * arrLen);
	/*do calculate*/
	permute(0, result, arr, arrLen, tBuf);

	free(tBuf);

	/*print result*/
	for(uint16_t i = 0 ; i < possible; i++)
	{
		for(uint16_t j = 0; j < arrLen; j++)
		{
			printf("result[%d][%d] = %d\n", i, j, result[i][j]);
		}
		free(result[i]);
	}
	free(result);


	return 0;
}
