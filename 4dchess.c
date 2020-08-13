#include "lib/string/str.h"
#include <stdbool.h>

void move(char*, char, bool);
void bfparse(string*);

int main(int argc, char* argv[])
{
	string* bf = str_input();

	bfparse(bf);
	return 0;
}

void bfparse(string* s)
{
	size_t loop;
	char memory[8][8][8][8];

	size_t c;
	char i[4] = {0};

	#define MEMORY_VALUE memory[i[1]][i[2]][i[3]][i[4]]
	for(c=0; c<s->len; c++)
	{
		switch(s->data[c])
		{
			//dim0
			case '<':
				move(i, 0, 0);
				break;
			case '>':
				move(i, 0, 1);
				break;
			//dim1
			case 'V':
				move(i, 1, 0);
				break;
			case '^':
				move(i, 1, 1);
				break;
			//dim2
			case 'o':
				move(i, 2, 0);
				break;
			case '*':
				move(i, 2, 1);
				break;
			//dim3
			case '?':
				move(i, 3, 0);
				break;
			case '@':
				move(i, 3, 1);
				break;

			case '+':
				MEMORY_VALUE++;
				break;
			case '-':
				MEMORY_VALUE--;
				break;
			case '.':
				printf("%c", MEMORY_VALUE);
				break;
			case ',':
				MEMORY_VALUE=getchar();
				break;
			case '[':
				if(MEMORY_VALUE)
				{
					continue;
				}
				else
				{
					loop = 1;
					while(loop>0)
					{
						c++;
						if (s->data[c] == '[')
						{
							loop++;
						}
						else if (s->data[c] == ']')
						{
							loop--;
						}
					}
				}
				break;
			case ']':
				if(!MEMORY_VALUE)
					continue;
				loop = 1;
				while (loop > 0)
				{
					c--;
					if (s->data[c] == '[')
					{
						loop--;
					}
					else if (s->data[c] == ']')
					{
						loop++;
					}
				}
				break;
		}
	}
}

void move(char* i, char dim, bool inc)
{
	if(inc)
		++i[dim];
	else
		--i[dim];
	if(i[dim]>8)
		printf("Fallen off of hypercube at %d,%d,%d,%d,", i);
		exit(1);
}
