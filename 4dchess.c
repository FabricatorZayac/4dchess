#include "lib/string/str.h"

void bfparse(string* s);

int main(int argc, char* argv[])
{
	string* bf = str_input();

	bfparse(bf);
	return 0;
}

void bfparse(string* s)
{
	size_t loop;
	string* memory = str_create("\0\0");
	int i = 0, c;

	for(c=0; c<s->len; c++)
	{
		switch(s->data[c])
		{
			case '<':
				--i;
				if(i<0)
					printf("Oops, cannot go below zero memory\n");
					i = 0;
				break;
			case '>':
				++i;
				if(i>=memory->len)
					str_push_back(memory, 0);
				break;
			case '+':
				memory->data[i]++;
				break;
			case '-':
				memory->data[i]--;
				break;
			case '.':
				printf("%c",memory->data[i]);
				break;
			case ',':
				memory->data[i]=getchar();
				break;
			case '[':
				if(memory->data[i])
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
				if(memory->data[i]==0)
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
